emmmmm，你们这些大佬上来就是发现了IX这种I比X小就表示X减一的操作，我怎么读了好几遍题也没发现。。。。。我是从上一道数字转罗马数字的题目过来的，想到的是一个字符串匹配多个字母和字母组合的操作，即这里的麻烦之处在于I ,V 有单独的含义，IV还有组合起来的含义，一遍扫下来很可能算错了。这里的组合含义优先于单独的含义，那么如果已经dp[i]表示input[0..i]对应的阿拉伯数字值，递推公式是什么呢？
dp[i]=dp[i-2]+valueOf([i-1,i]) , if input[i-1,i]有意义
dp[i]=dp[i-1]+valueOf([i]), if input[i-1,i]无意义且input[i]有意义（题目保证了单个字符肯定有意义，所以这个不用操心）

初值应该算的是dp[0]=0,dp[0]=valueOf(input[1])

代码如下
```
class Solution {
public:
    int romanToInt(string s) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int res=0;
        vector<int> dp(s.size()+1,0);
        dp[1]=nums[std::find(romans.begin(),romans.end(),s.substr(0,1))-romans.begin()];
        for(size_t i=2;i<s.size()+1;i++)
        {
            auto j=std::find(romans.begin(),romans.end(),s.substr(i-2,2));
            if(j==romans.end())
            {
                j=std::find(romans.begin(),romans.end(),s.substr(i-1,1));
                dp[i]=dp[i-1]+nums[j-romans.begin()];
            }
            else
            {
                dp[i]=dp[i-2]+nums[j-romans.begin()];
            }
        }
        return dp[s.size()];
    }
};
```
