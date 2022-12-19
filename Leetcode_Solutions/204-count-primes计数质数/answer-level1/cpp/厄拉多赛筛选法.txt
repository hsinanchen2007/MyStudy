### 解题思路
本题最简单的做法是直接暴力检索，判定是否为素数。
但是，这样会超时。

所以，我想到了取根号来检索，还是会超时。

因此，使用了比较出名的厄拉多赛筛选法，直接将其倍数都标记出来，剩下的就是质数。

注意，这种方法的使用上需要进行是否被标记的判定，这样才会减少时间的消耗。

### 代码

```cpp
class Solution {
public:
    //厄拉多塞筛法
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<bool> res(n,1);
        res[1] = 0;
        res[2] = 1;
        for(int i=2;i<n;i++){
            if(res[i] == 1){
                for(int j=2;j*i < n;j++){
                    res[j*i] = 0;
                }
            }

        }
        int count = 0;
        for(int i=1;i<n;i++){
            if(res[i] == 1) count++;
        }
        return count;
    }
};
```