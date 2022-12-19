## 分析
![image.png](https://pic.leetcode-cn.com/44d3d58edb0ebb733a97b51f7125832f041a52ab98f70ac61c1e4901db825294-image.png)
如图所示，利用mutex加锁解锁即可实现顺序打印，其中由于构造函数先执行，所以需要将mutex变量进行加锁初始化。

## 代码
```c++
class Foo {
public:
    Foo() {
        m2.lock();
        m3.lock();
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        printThird();
        m3.unlock();
    }
    
private:
    std::mutex m2, m3;
    
};
```
