### 解题思路
两个锁可以让两个函数交替运行：
    mutex lock1
    mutex lock2

    init():
        lock2.lock()

    fun1():
        lock1.lock()
        /..../
        lock2.unlock()

    fun2():
        lock2.lock()
        /..../
        lock1.unlock()
考虑把odd和even函数放一起当成一个函数，这个函数和zero函数交替运行，这里用2个锁。
odd和even也交替运行，这里也用2个锁。

odd和even的函数先执行“odd和even”的锁，避免死锁。

### 代码

```cpp
class ZeroEvenOdd {
private:
    int n;
    mutex lock0;
    mutex lock1;
    mutex lock2;
    mutex lock3;
public:
    ZeroEvenOdd(int n) {
        lock1.lock();
        lock3.lock();
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
            lock0.lock();
            printNumber(0);
            lock1.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=0;i<(n+1)/2;i++){
            lock2.lock();
            lock1.lock();
            printNumber(i*2+1);
            lock3.unlock();
            lock0.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=0;i<n/2;i++){
            lock3.lock();
            lock1.lock();
            printNumber((i+1)*2);
            lock0.unlock();
            lock2.unlock();
        }
    }
};
```