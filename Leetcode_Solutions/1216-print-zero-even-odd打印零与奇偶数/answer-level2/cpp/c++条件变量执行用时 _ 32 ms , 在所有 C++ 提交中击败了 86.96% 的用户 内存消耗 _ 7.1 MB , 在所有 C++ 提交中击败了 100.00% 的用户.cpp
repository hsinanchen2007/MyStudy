### 解题思路
首先，输出0的个数为n，之后输出奇数还是偶数用if语句判断循环次数；如果是奇数时，唤醒对应的条件变量，并控制count为3（count 1，2，3分别表示输出0，偶，奇的操作），同理，如果为偶数时，唤醒条件变量，并控制count为2.
在Even和Odd中，只需要在输出数字后，唤醒zero的条件变量，去输出0即可。

### 代码

```cpp
class ZeroEvenOdd {
private:
    int n;
    mutex myMutex;
    condition_variable cv1;
    condition_variable cv2;
    condition_variable cv3;
    int count = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(myMutex);
            cv1.wait(lck, [this](){return count == 1;});
            printNumber(0);
            if (i % 2 == 0) {
                cv3.notify_one();
                count = 3;
            }
            else {
                cv2.notify_one();
                count = 2;
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 1; i < n; i++) {
            unique_lock<mutex> lck(myMutex);
            cv2.wait(lck, [this](){return count == 2;});
            while (i % 2 != 0) {
                i++;
            }
            printNumber(i);
            cv1.notify_one();
            count = 1;
        }
    }

    void odd(function<void(int)> printNumber) {
         for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(myMutex);
            cv3.wait(lck, [this](){return count == 3;});
            while (i % 2 != 1) {
                i++;
            }
            printNumber(i);
            cv1.notify_one();
            count = 1;
        }
    }
};
```