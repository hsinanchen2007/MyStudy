逻辑很简单，用输出数字所在的进程控制其余所有的进程，通过判断取余的结果解锁对应的进程就可以了。
执行时间32ms，内存消耗9.1MB。

```
using namespace std;

class FizzBuzz {
private:
    int n;
    mutex mNum, mFizz, mBuzz, mFB;

public:
    FizzBuzz(int n) {
        this->n = n;
        mFizz.lock();
        mBuzz.lock();
        mFB.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 == 0) {
                continue;
            }
            else {
                mFizz.lock();
                printFizz();
                mNum.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 == 0) {
                continue;
            }
            else {
                mBuzz.lock();
                printBuzz();
                mNum.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 15; i <= n; i += 15) {
            mFB.lock();
            printFizzBuzz();
            mNum.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            mNum.lock();
            if ((i % 3 == 0) && (i % 5 == 0)) {
                mFB.unlock();
            }
            else if (i % 3 == 0) {
                mFizz.unlock();
            }
            else if (i % 5 == 0) {
                mBuzz.unlock();
            }
            else {
                printNumber(i);
                mNum.unlock();
            }
        }
    }
};
```
