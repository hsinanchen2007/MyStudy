### 解题思路
此处撰写解题思路

### 代码

```cpp
class ZeroEvenOdd {
private:
    int n;
    int k;
    std::mutex mutex1;
    std::mutex mutex2;
    std::mutex mutex3;
    
public:
    ZeroEvenOdd(int n):k(1) {
        this->n = n;
        mutex2.lock();
        mutex3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=this->n;i++){  

            mutex1.lock();
            printNumber(0);
            if(i%2==1){
                mutex3.unlock();
            }
            if(i%2==0){
                
                mutex2.unlock();
                //
               
            }
        
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=this->n;i+=2){
            
            
                
                mutex2.lock();

                printNumber(i);
                 mutex1.unlock();
  
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=this->n;i+=2){
            
                mutex3.lock();
                
                printNumber(i);
                mutex1.unlock();

        }
    }
};
```