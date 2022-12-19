### 解题思路


### 代码

```cpp
class H2O {
public:
    H2O():H(0),O(0) {
         
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        if(O!=1&&H==2){
            std::unique_lock<std::mutex> lock(mutex4);
            cond4.wait(lock,[&](){
                if(O==1){
                    return true;
                }
                else{
                    return false;
                }
            });           
        }
        
        if(O==1&&H==2){
            this->O=0;
            this->H=0;
            
                  
        }

        
        mutex1.lock();
        releaseHydrogen();
        this->H++;
        mutex1.unlock();
        cond3.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        // releaseOxygen() outputs "O". Do not change or remove this line.

        if(O==1&&H<2){
            std::unique_lock<std::mutex> lock(mutex3);
            cond3.wait(lock,[&](){
                if(H==2){
                    return true;
                }
                else{
                    return false;
                }
            });          
        }

         if(O==1&&H==2){
            this->O=0;
            this->H=0;
                  
        }


        mutex2.lock();
        releaseOxygen();
        this->O++;
        mutex2.unlock();
       cond4.notify_one();


    }
private:
    int H;
    int O;
    std::mutex mutex1;
    std::mutex mutex2;
    std::mutex mutex3;
    std::mutex mutex4;
    std::condition_variable cond3;
    std::condition_variable cond4;
};
```