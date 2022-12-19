### 解题思路
此处撰写解题思路

### 代码

```cpp
class FizzBuzz {
private:
    int n;
    int i;
    std::mutex m1,m2,m3;
public:
    FizzBuzz(int n) {
        this->n = n;
        i=1;
        m2.lock();
        m3.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i<=n)
        {
            m1.lock();
            if(i%3==0 && i%5!=0 && (i<=n))  
            {
                
                printFizz();
                i++;
            }
            m2.unlock();
            m3.unlock();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n)
        {
            m2.lock();
            if(i%5==0 && i%3!=0&& (i<=n)) 
            {    
                
                printBuzz();
                i++;
            }
            m1.unlock();
            m3.unlock();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
           while(i<=n) 
            {
                m3.lock();
                if(i%5==0 && i%3==0&& (i<=n) )
                {    
                    
                    printFizzBuzz();
                    i++;
                }
                m1.unlock();
                m2.unlock();
            }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
            while(i<=n)
            {
                if(i%5!=0 && i%3!=0 && (i<=n)) 
                {    
                    
                    printNumber(i);
                    i++;
                }
                m3.unlock();
                m1.unlock();
                m2.unlock();
            }
    }
};
```