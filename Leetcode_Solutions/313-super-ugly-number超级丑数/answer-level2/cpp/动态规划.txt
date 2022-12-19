### 解题思路
需要注意的是，ptr这个数组是以primes[]数组为目标记录的，用re为基础来记录也可以，但是铁超时，内存估计也会超(re集可以非常大，而primes数组毕竟有限)

### 代码

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ptr(primes.size(), 0);
        vector<int> re(n, INT_MAX);
        re[0] = 1;
        for (int i=1; i<n; i++) {
            int k = 0;
            for (int j=0; j<primes.size(); j++) {
                int cal = re[ptr[j]]*primes[j];
                if (cal < re[i]) {
                    re[i] = cal;
                    k = j;
                }
                else if (cal == re[i])
                    ptr[j]++;     
            }
            ptr[k]++;
        }
        return re[n-1];
    }
};
```