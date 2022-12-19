### 解题思路
此处撰写解题思路
dalao太多了，这里只是分享下思路
简单来说 (()(())) = (()) + ((())) //不知道各位能否明白=-=
有一点把被包住的括号分解掉的感觉
这样当遇到后括号的时候，只需要让答案加上前2^(前括号数-后括号数)即可
**注意遇到连续的后括号时第一个之后的在本次计算不要统计**
时间复杂度O(N)只需要遍历一次数组
### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        int openTime = 0,closeTime = 0,ans = 0;//统计前后括号数量
        for(int i=0;i<S.size();++i) {
            if(S[i] == '(') ++openTime;
            if(S[i] == ')') {
                ++closeTime;
                ans += pow(2,openTime-closeTime); //计算时仅需统计上第一个遇到的后括号
                while(S[i] == ')' && i<S.size()) ++i,++closeTime; //略去后面的后括号
                --i;
                --closeTime;
            }
        }
        return ans;
    }
};
```