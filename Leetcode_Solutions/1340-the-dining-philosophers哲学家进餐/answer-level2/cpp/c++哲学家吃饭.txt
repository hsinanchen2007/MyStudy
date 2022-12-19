### 解题思路


### 代码

```cpp
class DiningPhilosophers {

public:
    DiningPhilosophers() {
        this->a[0]=0;
        this->a[1] = 0;
        this->a[2] = 0;
        this->a[3] = 0;
        this->a[4] = 0;
    }
    

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

                    mutex.lock();
                    //尝试拿叉子,没拿到，阻塞
                    int left=philosopher;
                    int right=(philosopher+1)%5;
                    std::unique_lock<std::mutex> lock(mutex1);
                    cond.wait(lock,[&](){
                        if(this->a[left]==0&&this->a[right]==0){    
                        return true;//左边和右边的人都不在吃饭
                        }
                        return false;
                    });
                    a[philosopher]=1;//本身处于吃饭状态了
                    mutex.unlock();


                    pickLeftFork();
                    pickRightFork();
                    eat();


                    mutex.lock();
                    putLeftFork();
                    putRightFork();
                    this->a[philosopher]=0;//放下叉子，变成不吃饭状态。
                    cond.notify_all(); //让其他所有人去试着拿叉子
                    mutex.unlock();

		
    }
private:
    int a[5];//初始化状态数组，记录哲学家状态
                        //0：没在吃   1：吃饭
    std::mutex mutex;
    std::mutex mutex1;
    std::condition_variable cond;

    
};
```