### 解题思路
此处撰写解题思路

### 代码

```cpp
class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(Mu);//获取Mu锁
            v1.wait(lk,[this](){return count == 1;});//看v1是否满足条件，（锁和变量）
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            count++;//变量+1，=2，等于2时，foo会阻塞，bar的condition_variable 满足条件
            v2.notify_one();//通知并唤醒阻塞在v2里面的线程
        }
    }

    void bar(function<void()> printBar) {
        //注释同上
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(Mu);
            v2.wait(lk,[this](){return count == 2;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            count--;
            v1.notify_one();
        }
    }
private:
    int count = 1;//条件变量
    std::condition_variable v1;//foo条件变量对象
    std::condition_variable v2;//bar条件变量对象
    std::mutex Mu;//定义一个锁
};
```