### 解题思路
这道题最麻烦的地方在出现`*`的情况。
首先从最简单的情况开始，只看要比较的两个字符，即源字符串s[i]和模式串p[j]
- 如果`p[j] == '.'`或者`p[j] == s[i]`：当前匹配成功
- 如果`p[j] == '*'`：需要进一步分情况讨论，假设`p[j]`前面`p[j-1]`存在
    - 如果`p[j-1] == '.'`或者`p[j-1] == s[i]`，则`p[j-1]p[j]`这两个模式串可以使用1到无数次，匹配成功
    - 如果`p[j-1] == '.'`和`p[j-1] == s[i]`都不成立，但可以使用`p[j-1]p[j]`这两个模式串0次，匹配成功
- 除了以上情况，均匹配不成功

#### 动态规划算法
由于判断`p[j] == s[i]`、`p[j-1]p[j]`等当前问题附近的情况，即可减小原问题，因此存在最优子结构，因此可以写出动态规划方程：
记dp[i][j]表示前i个源字符与前j个模式串字符是否匹配（含当前`i,j`这两个字符）
dp[i][j]就等于：
- 如果`p[j] == '.'`或者`p[j] == s[i]`：当前匹配成功，**等于`true  && dp[i-1][j-1]`**
- 如果`p[j] == '*'`：需要进一步分情况讨论，假设`p[j]`前面`p[j-1]`存在
    - 如果`p[j-1] == '.'`或者`p[j-1] == s[i]`，则`p[j-1]p[j]`这两个模式串可以使用1到无数次，匹配成功，**等于`true && dp[i-1][j]`**
    - 如果`p[j-1] == '.'`和`p[j-1] == s[i]`都不成立，但可以使用`p[j-1]p[j]`这两个模式串0次，匹配成功，**等于`true && dp[i-1][j-2]`**
- 除了以上情况，均匹配不成功，**等于`false && dp[i-1][j-1]`**

**初始解**
动态规划方程根据分析很好写，但是很重要的一点是初始解怎么写
初始解一般是对第一个变量等于0的情况，含义即源字符串为空的时候怎么与模式串P进行匹配
- 首先想到两个都是空的时候，是匹配的，为`true`
- 如果模式串不为空，也要分情况讨论：
    - 对`p[j] != '*'`，一定是不匹配的
    - 如果`p[j] == '*'`，那么就存在`p[j-1]p[j]`这两个模式串使用0次，也可以匹配
    
因此初始解dp[0][j]可以定义为:
- 对`p[j] != '*'`，一定是不匹配的，等于`false && dp[0][j-1]`
- 如果`p[j] == '*'`，那么就存在`p[j-1]p[j]`这两个模式串使用0次，也可以匹配,等于`true && dp[0][j-2]`

##### 复杂度分析
记源字符串长为N，模式串长为M
时间复杂度：$O(MN)$,因为对每个源字符串都要对应比较模式串的每一位
空间复杂度：$O(MN)$,开了这么大的数组存值

#### 递归比较
根据上面的分析，递归实现即可

### 代码

```cpp
class Solution {
public:
    // 动态规划
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if(p.empty()) return s.empty();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= np; i++){
            if(i-2 >= 0 && p[i-1] == '*' && p[i-2]){
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for(int i = 1; i <= ns; i++){
            for(int j = 1; j <= np; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    bool zero, one;
                    if(j-2 >= 0){
                        zero = dp[i][j-2];
                        one = (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];
                        dp[i][j] = zero || one;
                    }
                }
            }
        }
        return dp[ns][np];
    }
    
    // 递归比较
    bool isMatch2(string s, string p) {
        return helperMatch(s, p, 0, 0);
    }

    bool helperMatch(string &s, string &p, int i, int j){
        int ns = s.size();
        int np = p.size();
        if(np == j){
            if(ns == i) return true;
            return false;
        }
        bool one = false, zero = false;
        if(j + 1 < np && p[j+1] == '*'){  // 遇到*时
            zero = helperMatch(s, p, i, j+2);  // 使用0次
            if(!zero && (i < ns) && (p[j] == s[i] || p[j] == '.')){
                one = helperMatch(s, p, i+1, j);  // 使用多次
            }
            return zero || one;
        }else{
            if((i < ns) && (p[j] == s[i] || p[j] == '.')){
                return helperMatch(s, p, i+1, j+1);  // 当前字符正常匹配
            }else{
                return false;  // 不匹配
            }
        }
        return false;
    }
};
```