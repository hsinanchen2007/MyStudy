### 解题思路
此处撰写解题思路
与其他的java玩家写的一样，使用linux的信号量来解决，因为c++11没有提供信号量，信号量在解决这种依次问题很有特点。

测试demo示例如下

```cpp
int main() {
    FizzBuzz fb(15);

    thread t1(&FizzBuzz::fizzbuzz, &fb, bind(&showStr, static_cast<string>( "fizzbuzz" )));
    thread t2(&FizzBuzz::buzz, &fb, bind(&showStr, static_cast<string>( "buzz" )));
    thread t3(&FizzBuzz::fizz, &fb, bind(&showStr, static_cast<string>( "fizz" )));
    thread t4(&FizzBuzz::number, &fb, show);
    t1.join();
    t2.join();
    t3.join();
    t4.join();


```
### 代码

```cpp
#include <semaphore.h>
#include <iostream>
#include <functional>
#include <thread>
#include <unistd.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;

    sem_t semNum;
    sem_t semfizz;
    sem_t sembuzz;
    sem_t sembuzzfizz;
public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 1;
        sem_init(&semNum, 0, 1);
        sem_init(&semfizz, 0, 0);
        sem_init(&sembuzz, 0, 0);
        sem_init(&sembuzzfizz, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        do {
            sem_wait(&semfizz);
            if (cur > n) {
                return;
            }
            printFizz();
            checkNextNum(cur);
        } while (cur <= n);
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        do {
            sem_wait(&sembuzz);
            if (cur > n) {
                return;
            }
            printBuzz();
            checkNextNum(cur);
        } while (cur <= n);

    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        do {
            sem_wait(&sembuzzfizz);
            if (cur > n) {
                return;
            }
            printFizzBuzz();
            checkNextNum(cur);
        } while (cur <= n);

    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        do {
            sem_wait(&semNum);
            if (cur > n) {
                return;
            }
            printNumber(cur);
            checkNextNum(cur);

        } while (cur <= n);
    }

    void checkNextNum(int &num) {
        ++num;
        if (!(num % 15)) {
            sem_post(&sembuzzfizz);
        } else if (!(num % 5)) {
            sem_post(&sembuzz);
        } else if (!(num % 3)) {
            sem_post(&semfizz);
        } else {
            sem_post(&semNum);
        }
        if (num > n) {
            sem_post(&semfizz);
            sem_post(&sembuzz);
            sem_post(&semNum);
            sem_post(&sembuzzfizz);
        }
    }
};
```