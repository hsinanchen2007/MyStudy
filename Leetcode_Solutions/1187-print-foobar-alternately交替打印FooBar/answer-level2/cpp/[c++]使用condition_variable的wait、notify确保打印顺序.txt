使用条件变量控制，确保foo先于bar打印，第一个打印确保是foo。
```
#include <functional>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

class FooBar {
private:
    int n;

public:
    FooBar(int n){
        this->n = n;
        bFirst = true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            if (!bFirst)
            {
                cv2.wait(lk, [this] {return bBar; });
            }
            printFoo();
            bFirst = false;
            bFoo = true;
            bBar = false;
            cv1.notify_one();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv1.wait(lk, [this] {return bFoo; });
            printBar();
            bFoo = false;
            bBar = true;
            cv2.notify_one();
        }
    }

private:
    bool bFirst, bFoo, bBar;
    condition_variable cv1, cv2;
    mutex m;
};
```
