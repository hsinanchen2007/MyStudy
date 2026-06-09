### 解题思路
又是交替打印的题目,, 使用原子操作即可完成线程间的同步
![image.png](https://pic.leetcode-cn.com/27e6d2afe1aecf333a4d37e2a140db4cf5dd851b6a13ed3ff53b1661c2a9730f-image.png)

### 代码

```cpp
class H2O {
    atomic<int> h2;
public:
    H2O() {
        h2=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        while(h2.load()>1)std::this_thread::yield();
        releaseHydrogen();
        h2++;
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        while(h2.load()!=2)std::this_thread::yield();
        releaseOxygen();
        h2.store(0);
    }
};
```