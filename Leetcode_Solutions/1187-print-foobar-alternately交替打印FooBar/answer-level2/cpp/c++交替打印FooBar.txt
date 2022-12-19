### 解题思路
此处撰写解题思路

### 代码

```cpp
class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        mutex2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            
            
           mutex1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
           mutex2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mutex2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mutex1.unlock();
        }
    }
private:
    std::mutex mutex1;
    std::mutex mutex2;
    

};
```