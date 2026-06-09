### 解题思路
将N进行质因数分解，然后将对应的所有质因数全部累加
1是特殊的边界情况，无需步骤，因此直接返回0


### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        
        if (n == 2 || n == 3) {
            return n;
        }

        /* 递归获取质因数 */
        int factorial = 0;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                factorial = i;
                break;
            }
        }

        if (factorial == 0) {
            return n;
        }
        
        // 质因数累加
        return factorial + minSteps(n / factorial);
    }
};
```