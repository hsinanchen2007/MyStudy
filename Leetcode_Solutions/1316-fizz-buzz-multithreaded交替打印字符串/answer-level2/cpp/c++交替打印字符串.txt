### 解题思路
此处撰写解题思路

### 代码

```cpp
class FizzBuzz {
private:
    int n;
    std::mutex mutex1;
    std::mutex mutex2;
    std::mutex mutex3;
    std::mutex mutex4;
public:
    FizzBuzz(int n) {
        this->n = n;
        mutex3.lock();
        mutex2.lock();
        mutex1.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=1;i<=this->n;i++){
            if(i%3==0&&i%5!=0){
                mutex1.lock();
                printFizz();
                mutex4.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=1;i<=this->n;i++){
            if(i%5==0&&i%3!=0){
                mutex2.lock();
                printBuzz();
                mutex4.unlock();
            }


        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=1;i<=this->n;i++){
            if(i%5==0&&i%3==0){
                mutex3.lock();
                printFizzBuzz();
                mutex4.unlock();
            }


        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=this->n;i++){
            
            mutex4.lock();
            if(i%5==0&&i%3==0){
                mutex3.unlock();
            }
            else if(i%5==0&&i%3!=0){
                mutex2.unlock();
            }
            else if(i%5!=0&&i%3==0){
                mutex1.unlock();
            }
            else{
                
                printNumber(i);
                mutex4.unlock();
            }


        }
    }
};
```