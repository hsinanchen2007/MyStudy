```
class Foo {

public:
    mutex mx1;     // 锁1
    mutex mx2;     // 锁2
    
    Foo() {
        mx1.lock();       // 初始：锁1锁上
        mx2.lock();       // 初始：锁2锁上
    }

    void first(function<void()> printFirst) {
        printFirst();
        mx1.unlock();     // 释放锁1 
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> lg(mx1);    // 尝试锁上锁1，成功继续，否则等待
        printSecond();
        mx2.unlock();      // 释放锁2
    }

    void third(function<void()> printThird) {
        lock_guard<mutex> lg2(mx2);     // 注意顺序：必须先获得锁2，成功后才能获得锁1
        lock_guard<mutex> lg1(mx1);     // 如果顺序反了，second和third会因同时竞争锁1而超时
        printThird();
    }

};
```