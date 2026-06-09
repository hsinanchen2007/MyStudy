![image.png](https://pic.leetcode-cn.com/391a3c859094b204fb07acf754b3f2a89c60942e910818a9d2e1d63b0702474b-image.png)


### 解题思路

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
    vector<int> count(n+1,0);
    count[0] = 1;
    count[1] = 1;
    for (int i = 2; i <= n ; i++) {
        int lastJindex = (i - 1) / 2;
        for (int j = 0; j <= lastJindex; j++) {
            int partnerIndex = i - 1 - j;
            int sum = count[j] * count[partnerIndex];
            if (j != partnerIndex) {
                //需要翻倍，因为存在镜像
                sum<<=1;
            }
            count[i] += sum;
        }
    }
    int result = count[n];
    return result;

    }
};
```