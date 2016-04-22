///
///@date   2016-04-22 21:58:19
///
 
 
 
#include <iostream>
#include <pthread.h>
using std::cin;
using std::cout;
using std::endl;

class condition;

class mutexlock
{
friend condition;            //声明友元类  ，condition需要用到mutexlock私有成员
public:
mutexlock();
~mutexlock();
void lock();
void unlock();

private:
	pthread_mutex_t mutex;
};

mutexlock::mutexlock()
{
	pthread_mutex_init(&mutex,NULL);
}
mutexlock::~mutexlock()
{
	pthread_mutex_destroy(&mutex);
}

void mutexlock::lock()
{
	pthread_mutex_lock(&mutex);
}

void mutexlock::unlock()
{
	pthread_mutex_unlock(&mutex);
}

//  mutex类完成




class condition
{
public:
	condition(mutexlock&);
	~condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	mutexlock &_mutex;       //引用一个互斥锁
};

condition::condition(mutexlock &mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}
condition::~condition()
{
	pthread_cond_destroy(&_cond);
}

void condition::wait()
{
	_mutex.lock();     //wait前需上锁
	pthread_cond_wait(&_cond,&(_mutex.mutex));
	_mutex.unlock();
}

void condition::notify()
{
	pthread_cond_signal(&_cond);
}

void condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

int main()
{
	return 0;
}
