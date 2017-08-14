
QTime timeCounter;
int totalTime = 0;
int lastTime = 0;
timeCounter.start();

//do sth
lastTime = totalTime;
totalTime = timeCounter.elapsed();
LOG4CPLUS_TRACE(g_deviceExplorerLog, "start to map a point.");

lastTime = totalTime;
totalTime = timeCounter.elapsed(); 
LOG4CPLUS_TRACE(g_deviceExplorerLog, "  function  cost " << totalTime - lastTime << " ms.");





#include <windows.h>
LARGE_INTEGER litmp;
LONGLONG start, end;double dft, dff, dfm;
QueryPerformanceFrequency(&litmp);//获得时钟频率
dff = (double)litmp.QuadPart;QueryPerformanceCounter(&litmp);//获得初始值
start = litmp.QuadPart;
// do sth
QueryPerformanceCounter(&litmp);//获得终止值
end = litmp.QuadPart;dfm = (double)(end - start);
dft = dfm / dff;//获得对应的时间值,单位秒
printf("links  cost %lf ms\n", dfm / dff * 1000);
ACE_Time_Value sdate(ACE_OS::gettimeofday())  ; 
ACE_Time_Value edate(ACE_OS::gettimeofday())  ; 
printf(" cost %d ms\n",(edate-sdate).msec());
