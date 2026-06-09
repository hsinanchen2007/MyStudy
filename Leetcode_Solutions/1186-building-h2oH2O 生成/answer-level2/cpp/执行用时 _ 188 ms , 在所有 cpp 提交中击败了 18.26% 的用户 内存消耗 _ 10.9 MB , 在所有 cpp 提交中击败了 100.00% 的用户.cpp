### 解题思路
1. H和O各生成一个
2. 判断当前组H的个数，如果H个数未到2个，则释放H锁，再生成一个H

### 代码

```cpp
class H2O {
public:
    int nH=0, nO=0;
    pthread_mutex_t mtx_o;
    pthread_mutex_t mtx_h;
    H2O() {
        pthread_mutex_init(&mtx_h, NULL);
        pthread_mutex_init(&mtx_o, NULL);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        pthread_mutex_lock(&mtx_h);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        nH++;
        if(nH<2){
            pthread_mutex_unlock(&mtx_h);
        }else{
            pthread_mutex_unlock(&mtx_o);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        pthread_mutex_lock(&mtx_o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        nH=0;
        pthread_mutex_unlock(&mtx_h);
    }
};
```