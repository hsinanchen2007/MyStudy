### 解题思路

![解题思路](https://pic.leetcode-cn.com/fd0a26fa6d65fb8e76ea094da3aa944ff89a1e136b37d535b4c2177644518c5b.png)

### 代码

```cpp
class Solution {
public:
    int numberOf2sInRange(int num) {
        int ans = 0;
        int n = getN(num); // 获取num的位数
        for (int i = 0; i< n;i++){
            int k = num / (int)pow(10, n-i-1) %10;
            if (k > 2) {
               int f = num / (int)pow(10, n-i) + 1;
               int b = pow(10, n-i-1);
               ans += f * b;
            } else {
                int f = num / (int)pow(10, n-i);
                int b = (int)pow(10, n-i -1);
                ans += f * b;
            }
            if (k == 2) ans += num % (int)pow(10, n-i-1) + 1;
        }
        return ans;
    }
    int getN(int x){ // 获取x的位数
        if (x == 0) return 0;
        if (x < 10) return 1;
        return getN(x / 10) + 1;
    }
};
```