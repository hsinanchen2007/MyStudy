**解题思路**
题目相当于两个线程同步运行 可以把锁定互斥元看做一个release,释放互斥元看做一个acquire,用内存序来确保同步,最重要的是自旋的时候一定在条件不满足时让出时间片,即yield操作,否则时间消耗极高,也很好理解,cpu一直在无休止的空转,至此完成.

class FooBar{
private:
    int n;
    std::atomic<bool> flag;
public:
    FooBar(int n): flag(true) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(!flag.load(std::memory_order_acquire))
                std::this_thread::yield();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag.store(false, std::memory_order_release);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(flag.load(std::memory_order_acquire))
                std::this_thread::yield();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag.store(true, std::memory_order_release);
        }
    }
};