### 解题思路

分析可能出现0的情况，为因子里面有5，0。具体如下：
（1）5, 10, 15...这些数字，和2相乘，会共享1个0；
（2）25, 50, 75, 100...这些数字，和4相乘会共享两个0，考虑是（1）的子集，故是多一个0.
（3）125, 250, 375, 500...这些数字，和8相乘共享3个0，考虑（1），（2），多一个0
 (4)...

 (m) 5^m, 2*5^m, 3*5^m, 4*5^m...这些数字，和2^m相乘，可以共享m个0。

从上至下，是不断缩小的集合，故需要遍历m种情况，考虑5^m <= n即可。

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        
        int res = 0;
        int step = 5;
        while(step <= n) {
            for(int i = step; i <= n; i+=step) {
                res++;
                if(i > n-step) break;
            } 
            if(step > n/5) break;
            step*=5;
        }
        return res;
    }
};
```