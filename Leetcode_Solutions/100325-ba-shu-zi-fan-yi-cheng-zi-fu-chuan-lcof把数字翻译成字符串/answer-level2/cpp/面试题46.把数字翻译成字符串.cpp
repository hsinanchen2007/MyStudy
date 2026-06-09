### 解题思路
- 核心思路：实质为动态规划，第i位之前（含第i位）的数字翻译成字符串的方案数dp[i]，要看第i位和第i-1位连起来的两位数能否被一起翻译，如果能被一起翻译，那么方案数就等于dp[i-1]+dp[i-2]，否则为dp[i-1]
- 注意：两位数不能被一起翻译的条件是**不小于26或不大于9**
- 执行用时：4 ms, 在所有 C++ 提交中击败了47.48%的用户
- 内存消耗：5.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        if(num/10==0)return 1;
        //num形如abcdef
        int ef=num%100;
        if(ef>=26||ef<=9)return translateNum(num/10);
        else return translateNum(num/10)+translateNum(num/100);
    }
};
```