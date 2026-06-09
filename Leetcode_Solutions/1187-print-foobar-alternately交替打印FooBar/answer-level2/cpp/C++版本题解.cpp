```
class FooBar {
private:
    int n;
    mutex foo_mutex;
    mutex bar_mutex;

public:
    FooBar(int n) {
        this->n = n;
        foo_mutex.unlock();
        bar_mutex.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            foo_mutex.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            bar_mutex.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            bar_mutex.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_mutex.unlock();
        }
    }
};
```
