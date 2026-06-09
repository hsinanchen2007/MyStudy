&emsp;&emsp;按照位数计算不重复的数字,1位数有9个,2位数有9\*9个,3位数有9\*9\*8,...以此类推,一直算到和N的位数相同为止,之后在对N从高位到低位分别计算即可,遇到有重复的数字直接break.时间复杂度O(logn).
```c++
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int n = ceil(log10(N + 1)), count = 0, tmp = 1, base = 1;
        for(int i = 0; i < n - 1; i++){
            count += tmp * 9;
            tmp *= (9 - i);
            base *= 10;
        }
        int j = 0, h[10] = {};
        while(N && base >= 1){
            int t = (N/base)%10, k = 0;
            for(int i = (j == 0 ? 1 : 0) ; i < 10 && i <= (base != 1 ? t - 1 : t); i++){
                if(h[i] == 0)
                    k++;
            }
            count += k * tmp;
            if(h[t] == 1) break;
            h[t] = 1, base /= 10, tmp /= (9 - j++);
        }
        return N - count;
        
    }
};
```
