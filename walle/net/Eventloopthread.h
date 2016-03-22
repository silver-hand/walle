#ifndef WALLE_NET_EVENTLOOPTHREAD_H_
#define WALLE_NET_EVENTLOOPTHREAD_H_
#include <walle/stl/functional.h>
#include <walle/stl/noncopyable.h>
#include <walle/sys/wallesys.h>
#include <string>

using namespace walle::sys;

namespace walle {
namespace net{

class EventLoop;

class EventLoopThread : public std::noncopyable 
{
 public:
  typedef std::function<void(EventLoop*)> ThreadInitCallback;

  EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback(),
                            const std::string &name = std::string());
  ~EventLoopThread();
  EventLoop* startLoop();
  void threadFunc();

 private:
  
  
  EventLoop         *_loop;
  bool               _exiting;
  Mutex              _mutex;
  Cond               _cond;
  Thread             _thread;
  ThreadInitCallback _callback;
};

}
}
#endif