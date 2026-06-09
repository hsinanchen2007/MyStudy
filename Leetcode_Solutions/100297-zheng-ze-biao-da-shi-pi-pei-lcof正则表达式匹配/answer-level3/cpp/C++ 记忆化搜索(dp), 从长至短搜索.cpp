### 此题可以写成常规dp以外(自短向长搜索)， 也可以写成记忆化搜索dp

以下方法为记忆化搜索dp

运行4-8ms, 内存≈10MB

- 定义dp[i][j]: s的前sLen长度的子串(s[0:sLen]) 和 p的前pLen长度字串(p[0:pLen]) 匹配结果, -1未搜索, 0成功, 1失败   在搜索时用dp的值判断是否搜索过以及匹配结果
- 开辟dp数组时注意应使用 s的长度加1 和 p的长度加1
- 初始化: dp[0][j]和dp[i][0], 按照匹配的定义初始化即可, 注意dp[0][0]=0处理
- 搜索: 如果需要求sLen和pLen是否匹配, 发现求过, 那么自然返回已经缓存的结果
- 如果没有怎么办？
  1. 如果p当前字符是'.' 那么匹配任意一个s的字符, s 和 p 长度**各减一** 向内搜索。把结果赋给dp并返回。
  2. 如果p当前字符是'\*' 那么分情况：
  2.1 假如 '\*'是p的第一个字符 或者 '\*'前面还是'\*', 那么当前长度组合sLen和pLen不匹配, 把匹配失败赋值给dp并返回
  2.2 假如 '\*'前面是'.', 那么把**pLen长度去掉2**, **把sLen长度去掉0至sLen** 向内搜索, 如果有匹配成功的则停止搜索, 把结果赋给当前sLen和pLen并返回。
  2.3 假如 '\*'前面是某个字母(以\$表示), 那么以**s的长度自长至短依次判断**s的字符是否和\$匹配, 如果匹配则向内进一步搜索, 如果有匹配成功的则停止搜索, 把结果赋给当前sLen和pLen并返回
  在2.2和2.3中最后：找不到任何匹配可能性，则把匹配失败赋值给dp并返回
  3. 如果p当前字符是是某个字母(以\$表示), 那么判断s的当前字母是否是\$, 是则s 和 p 长度**各减一** 向内搜索, 把结果赋给dp并返回; 不是则把匹配失败赋值给dp并返回

- 最后, 在主函数入口调用搜索时, 以最后位置调用: 即搜索长度组合s.size()和p.size()的匹配结果

```cpp
//定义
//记忆化搜索

class Solution {
private:
    int memoryDFS(vector<vector<int>>& dp, int sLen, int pLen, const string& s, const string& p) {
        if (dp[sLen][pLen] != -1) return dp[sLen][pLen];    //搜索过了
        else {
            //p当前字符是'.', 匹配任意s的字符, s和p长度各消耗1, 向内搜索
            if (p[pLen - 1] == '.') return (dp[sLen][pLen] = memoryDFS(dp, sLen - 1, pLen - 1, s, p));
            
            //p当前字符是'*, 分情况:'*'前面是'.' , '任意字母' , '*'或者当前的*已经到头了
            else if (p[pLen - 1] == '*') {
                if (pLen > 1 && p[pLen - 2] != '*') {  //如果'*'前面不是'*' 也没有到尽头
                    //跳过最近的 ?*组合, 其中?可以是.或者字母, 那么s长度不变, p长度减2
                    if (memoryDFS(dp, sLen, pLen - 2, s, p) == 0) return (dp[sLen][pLen] = 0);  //假如这种情况成功匹配则返回0
                    
                    //使用当前的?*组合, 匹配s的1至多个字母
                    int preLoc = sLen - 1;  //preLoc代表待比较的s的位置, 如果此位置字母等于p *前的字母, 或者p *前是. 那么可以向前搜索
                    while (preLoc >= 0 && (p[pLen - 2] == '.' || s[preLoc] == p[pLen - 2])) {
                        if (memoryDFS(dp, preLoc, pLen - 2, s, p) == 0) return (dp[sLen][pLen] = 0);  //假如这种情况成功匹配则返回0
                        else preLoc--;   //preLoc向前移动, 继续深入搜索
                    }
                    return (dp[sLen][pLen] = 1);  //无法匹配, 返回1
                }
                else  return (dp[sLen][pLen] = 1);  //'*'前面是'*' 或者到尽头, 返回1
            }
            else {
                //如果p当前字符和s相同, s和p长度各消耗1, 向内搜索
                if (s[sLen - 1] == p[pLen - 1]) return (dp[sLen][pLen] = memoryDFS(dp, sLen - 1, pLen - 1, s, p));
                //否则返回1
                else return (dp[sLen][pLen] = 1);
            }
        }
    }

public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<int>> dp(sSize + 1, vector<int>(pSize + 1, -1));  //-1: not searched, 0:success, 1:fail
        //初始化, 处理s长度为0或0长度为0时的dp匹配结果
        dp[0][0] = 0;
        for (int i = 1; i <= pSize; ++i) {
            if (p[i - 1] == '*' && dp[0][i - 2] == 0) dp[0][i] = 0;
            else dp[0][i] = 1;
        }
        for (int i = 1; i <= sSize; ++i) dp[i][0] = 1;

        //搜索开始, 从完整字符串 长度逐渐变短 开始搜索
        int ret = memoryDFS(dp, sSize, pSize, s, p);
        if (ret == 1) return false;
        else return true;
    }
};
```
