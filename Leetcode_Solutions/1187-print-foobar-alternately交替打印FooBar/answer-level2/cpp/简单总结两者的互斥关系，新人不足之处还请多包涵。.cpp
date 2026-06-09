首先，定义两者的pv操作变量分别为fo,ba，然后分析foo和bar的先后执行顺序，考虑到foo输出完以后，bar要输出，这时候要唤醒bar，因此，printfoo（）以后执行ba.unlock(),又考虑到printbar()以后要重新进行新一轮的printfoo(),所以printbar()之后执行fo.unlock()。在执行printfoo()和printbar()之前都要加锁，因此对应加上自己的锁即可。

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            fo.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ba.unlock();

        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            ba.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fo.unlock();
        }
    }
    std::mutex fo,ba;
};