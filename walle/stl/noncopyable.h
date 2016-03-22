#ifndef WALLE_STL_NOCOPYABLE_H_
#define WALLE_STL_NOCOPYABLE_H_

namespace std {

class noncopyable {
public:
    noncopyable(){}
   virtual  ~noncopyable(){}
private:
    noncopyable(const noncopyable&);
    noncopyable& operator=(const noncopyable&);
};
}
#endif