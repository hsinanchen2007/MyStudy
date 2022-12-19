![967.jpg](https://pic.leetcode-cn.com/8bee8e665a7f40ce424baff10dd39f44174d3a9d3b06d276936a1e6576833876-967.jpg)

### 解题思路
循环判断个位数加减 K 是否在 0 ～ 9 范围内，直到数字的位数达到 N。

1、首先初始化结果为 {1,2,3,4,5,6,7,8,9}，数字的位数 count 为 1
2、判断个位数加减 K 是否在 0 ～ 9 范围内，数字的位数 count 加 1
    - 是：将结果中的数字乘以 10，再加上得到的数
    - 否：无
3、循环2操作，直到数字的位数 count == N

注：
- 如果 N 为 1，加上数字 0
- 如果 K 为 1，个位数加减 K 只需要做一次

### 代码

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int count = 1;
        vector<int> ans{1,2,3,4,5,6,7,8,9};
        if (N == 1) {
            ans.push_back(0);
        }

        while(count < N) {
            int ansSize = ans.size();

            for(int i = 0; i < ansSize; ++i) {
                int tmp = ans[i] % 10;
                if (tmp - K > -1) {
                    ans.push_back(ans[i] * 10 + tmp - K);
                } 
                
                if (K != 0) {
                    if (tmp + K < 10) {
                        ans.push_back(ans[i] * 10 + tmp + K);
                    }
                }
            }

            ans.erase(ans.begin(), ans.begin() + ansSize);
            count++;
        }
        
        return ans;
    }
};
```