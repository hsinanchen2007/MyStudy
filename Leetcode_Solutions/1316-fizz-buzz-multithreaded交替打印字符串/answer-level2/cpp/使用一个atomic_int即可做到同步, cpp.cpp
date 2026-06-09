### 解题思路
这种交替打印的基本都可以使用原子操作进行同步
![image.png](https://pic.leetcode-cn.com/93765f6c08ac8b5f5e0767217a17a9257753aa4203d96d09bd1eaa1d68aa2a7d-image.png)

### 代码

```cpp
class FizzBuzz {
private:
    int n;
atomic<int> i;
public:
    FizzBuzz(int n) {
        this->n = n;
        i.store(1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i.load(memory_order_acquire)<=n){
            if(i%3==0 && i%5!=0){
                printFizz();
                ++i;
            }else this_thread::yield();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3!=0 && i%5==0){
                printBuzz();
                ++i;
            }else
             this_thread::yield();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3==0 && i%5==0){
                printFizzBuzz();
                ++i;
            } else
            this_thread::yield();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3!=0 && i%5!=0){
                printNumber(i);
                ++i;
            }
            else
            this_thread::yield();
        }
    }
};
```