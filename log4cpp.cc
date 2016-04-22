///
///@date   2016-04-22 19:12:55
///
 
 
#include <stdio.h> 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::cin;
using std::cout;
using std::endl;

class Mylog
{
public:
	Mylog();
	~Mylog();

	void warn(const char*);
	void error(const char*);
	void debug(const char*);
	void info(const char*);
private:
	log4cpp::Category &root;               //一个Category 绑定两个Appender(cout&&RollingFileAppende)
};

Mylog::Mylog()          //构造函数
:root(log4cpp::Category::getRoot().getInstance("root"))   //引用必须在初始化列表初始化
{
	log4cpp::PatternLayout* ptLaout1=new log4cpp::PatternLayout();
	ptLaout1->setConversionPattern("%d: %p %c %x: %m%n");

	log4cpp::PatternLayout* ptLaout2=new log4cpp::PatternLayout();
	ptLaout2->setConversionPattern("%d: %p %c %x: %m%n");

	log4cpp::OstreamAppender*osA=new log4cpp::OstreamAppender("osA",&cout);
	osA->setLayout(ptLaout1);

	log4cpp::RollingFileAppender* roA=new log4cpp::RollingFileAppender(
			"roA","rollw.log",5*1024,1);
	roA->setLayout(ptLaout2);

	root.addAppender(osA);
	root.addAppender(roA);
	root.setPriority(log4cpp::Priority::DEBUG);
}

Mylog::~Mylog() //析构函数
{
	log4cpp::Category::shutdown();
}


void Mylog::warn(const char* str)
{
	ostringstream ost;
	ost<<str<<"   "<<__FILE__<<"  "<<__LINE__;  //一个字符串流输入 文件名和行号
	string s1=ost.str();
	root.warn(s1);
}
void Mylog::error(const char*str)
{
	ostringstream ost;
	ost<<str<<"   "<<__FILE__<<"  "<<__LINE__;
	string s1=ost.str();
	root.error(s1);
}
void Mylog::debug(const char*str)
{
	ostringstream ost;
	ost<<str<<"   "<<__FILE__<<"  "<<__LINE__;
	string s1=ost.str();
	root.debug(s1);
}
void Mylog::info(const char*str)
{
	ostringstream ost;
	ost<<str<<"   "<<__FILE__<<"  "<<__LINE__;
	string s1=ost.str();
	root.info(s1);
}

Mylog log;
#if 1
void logError(const char* str)
{
	log.error(str);
}

void logWarn(const char* str)
{
	log.warn(str);
}

void logDebug(const char* str)
{
	log.debug(str);
}

void logInfo(const char* str)
{
	log.info(str);
}
#endif

int main()
{

	logError("error");
	logWarn("warn");
	logDebug("Debug");
	logInfo("Info");
	return 0;
}

