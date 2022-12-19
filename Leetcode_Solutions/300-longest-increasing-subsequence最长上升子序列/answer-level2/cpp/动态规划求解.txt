### 解题思路
此处撰写解题思路
1、二维动态规划dp[i][j] 表示从第i个元素到第j个元素，最长升序列的个数
2、转移方程：
dp[i][j] =  dp[i][j - 1] + 1  ，如果当前nums[j] 比上一次比较的值nums[last]大,同时更新last的值
         =  dp[i][j - 1]       else
3、参考值nums[last]需要更新，防止如下情况，
  2， 5， 3， 4
i = 0 的时候，从2开始比较，  5〉2， 更新last指向5， 3 〉2 但是 3 < 5,此时要更新last指向的值为3, 后面的4 > 3

所以，last 指向的值为大于基准值且满足递增条件的的最小值，该值动态更新中 

 
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        int last = 0;
        int max = 0;
        int val = 0;
        
        for (int i = 0; i < len; i++) {
            last = i;
            for(int j = i + 1; j < len; j++) {

                if (nums[j] > nums[last]) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    val = nums[last];
                    last = j;
                    
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
                if (nums[j] > val && nums[j] < nums[last]) { 
                    last = j;
                }


                if (max < dp[i][j]) {
                    max = dp[i][j];
                }

            }

            
        }

        return max + 1;
    }
};
```