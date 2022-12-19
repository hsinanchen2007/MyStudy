### 解题思路
此处撰写解题思路
1. 两个线程打印的顺序不能乱，必须先打印foo，再打印bar，交替执行。使用原子变量在两个线程中同步信息；
2. 打印次数。局部变量来计数；
3. 存在CPU空转问题，要主动发起cpu调度。

### 代码

```cpp
#include <thread>
#include <atomic>

class FooBar {
private:
    int n;
    std::atomic<bool> flag_{true};  // print foo

public:
    explicit FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
      int count = 0;
      while (count < n) {
        if (flag_.load()) {
          ++count;
          printFoo();
          flag_.store(false);
        }
        
        std::this_thread::yield();
      }
    }

    void bar(function<void()> printBar) {
      int count = 0;
      while (count < n) {
        if (!flag_.load()) {
          ++count;
          printBar();
          flag_.store(true);
        }
        
        std::this_thread::yield();
      }
    }
};
```