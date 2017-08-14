//测试CPU核心个数
#if !defined (_WIN32) && !defined (_WIN64)
#define LINUX
#include 
#else
#define WINDOWS
#include 
#endif
unsigned core_count()  
{  
  unsigned count = 1; // 至少一个
  #if defined (LINUX)
  count = sysconf(_SC_NPROCESSORS_CONF);  
  #elif defined (WINDOWS)
  SYSTEM_INFO si;  
  GetSystemInfo(&si);  
  count = si.dwNumberOfProcessors;  
  #endif
return count;  
}  
#include 
int main()  
{  
  unsigned sz = core_count();  
  std::cout << sz << (1 == sz ? "core" : "cores") << '/n';  
}  
