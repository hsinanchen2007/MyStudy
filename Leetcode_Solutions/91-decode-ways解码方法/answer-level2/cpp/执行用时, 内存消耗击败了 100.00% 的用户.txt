### 解题思路
先使用了DFS+剪枝，果然超时了(因为不是返回所有有效的字符串)
随后看了题解：https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
果然是使用动态规划：
对于字符串中以第i个字符结尾，组合数目为dp[i]
那么有下面的关系
    if(s[i] == '0'){
        // 如果是0，那么必须和前一个字符合并，否则就是无效的
        // 与前一个字符合并后，那么必然有dp[i-2] == dp[i]
        if(s[i-1] == '1' || s[i-1] == '2'){
            dp[i] = dp[i-2];
        }else{
            return 0;
        }
    }else{
        // 如果前一个字符是"1"，那么当前无论是什么(除了0以外)，都可以和前面的合并，那么有dp[i] = dp[i-1](不合并s[i]与s[i-1]) + dp[i-2](合并s[i]与s[i-1])
        // 如果前一个字符是"2"，当前字符小于等于6(除了0以外)，也可以和前面的合并，合并公式同上
        // 如果前一个字符不是1或2，那么不能和前面的字符合并，那么有dp[i-1] == dp[i]
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
            dp[i] = dp[i-1] + dp[i-2];
        }else{
            dp[i] = dp[i-1];
        }
    }


### PASS 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        if(s[0] > '0') dp[0] = 1;
        for(int i = 1; i < dp.size(); ++i){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    int dp_i_2 = i-2 >= 0? dp[i-2]: 1;
                    dp[i] = dp_i_2;
                }else{
                    return 0;
                }
            }else{
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                    int dp_i_2 = i-2 >= 0? dp[i-2]: 1;
                    dp[i] = dp[i-1] + dp_i_2;
                }else{
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp.back();
    }
};
```


### 超时代码
```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int res = 0;
        getCombinationNum(res, s, 0);
        return res;
    }

    void getCombinationNum(int &res, string &s, int idx){
        if(idx >= s.size()){
            res++;
        }else{
            //cout << "idx: " << idx << " s: " << s[idx] << endl;
            if(s[idx] != '0') getCombinationNum(res, s, idx+1);
            if(idx+1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] - '0' <= 6))){
                getCombinationNum(res, s, idx+2);
            }
        }
    }
};
```