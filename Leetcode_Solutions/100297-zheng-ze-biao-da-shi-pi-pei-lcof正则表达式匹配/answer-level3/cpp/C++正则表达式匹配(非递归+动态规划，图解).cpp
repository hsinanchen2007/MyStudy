
### 解题思路：
>简单来说，就是利用dp数组来记录字符串s和p各自的不同子串是否匹配，从而由下至上推导出s和p能否匹配。

注意：为了dp数组和字符串中的下标含义保持一致，同时也为了更方便操作，本题解中分别在字符串s和p前填充一个空格字符‘ ’。因此dp数组大小实际为(pLen+1，sLen+1)，而原字符串也被表示为p[1...pLen]和s[1...sLen]。

因此`dp[i][j]`的含义为： p[1…i]与s[1…j]是否能匹配。



**状态转移方程：**
- 如果`p[i] == ‘.’` 或者 `p[i] == s[j]` :
`dp[i][j] = dp[i-1][j-1]`
- 如果p[i] == ‘ * ’且满足下面任一情况：
    - 如果`p[i-1] == s[j]`或者`p[i-1] == ‘.’`：
`dp[i][j] = dp[i][j-1]`
    - 如果`i>=2`：
`dp[i][j] = dp[i-2][j]`
    - 如果上面两个条件均满足：
`dp[i][j] = dp[i][j-1] | dp[i-2][j]`



>图例演示了如何建立，初始化，更新和使用dp数组来判断字符串s和p是否能匹配。

<![幻灯片1.PNG](https://pic.leetcode-cn.com/e5f23ccc982f6e66c89c154f34ac550134ea352d023dff4c82411a2c9d525168-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/726ac0f50068b0206805d68c97aa5110e7a55ffc87db1b733420fe18160d81f0-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/9b770fd8ae0501ab745ae1ebb59935c1bde5e2e2731c4a399c4a747da9fb0e3c-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/5285d583c9d27c7a50e234f55ab2caa694067fc7c70510ddbe2d2afa47dbd28e-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/738726641d4e35341cfee8f8f81f96a240e9cbe27b0a6e5afdc106476294ecd3-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/324269ad076197d337350f585a3bb0c2ef87c7114308efaf5769c58c637f8047-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/2b264e1f56a8ae06d3a617451e03cf2db789892de891aa574645fe448f8887e1-%E5%B9%BB%E7%81%AF%E7%89%877.PNG),![幻灯片8.PNG](https://pic.leetcode-cn.com/609c0d8f6563c31b27faba9eca889bebc85ac6f7cde6d4b159235aa24730821c-%E5%B9%BB%E7%81%AF%E7%89%878.PNG)>



**代码：**

>为了能使用|=操作符，dp数组使用的是原始二维数组,如果要用vector来保存的话，则需要对|=进行操作符重载，或者将逻辑或操作改成任何能有1取1的操作😘，比如max(),或者加入一个条件判断之类的。





```C++ []
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==p) return true;
        int sLen=s.size(), pLen=p.size();
        s=' '+s;p=' '+p;
        bool match[pLen+1][sLen+1]; 
        memset(match,0,sizeof(match));
        match[0][0]=1; //把(0,0)初始化为true
        for(int i=2;i<=pLen;i++){
            if(p[i]=='*')
                match[i][0]=match[i-2][0]; 
        }
        for(int i=1;i<=pLen;i++){
            for(int j=1;j<=sLen;j++){
                if(p[i]==s[j]||p[i]=='.'){
                    match[i][j]=match[i-1][j-1];
                }
                else if(p[i]=='*'){
                    if(p[i-1]==s[j]||p[i-1]=='.')
                            match[i][j]=match[i][j-1];
                    if(i>=2)
                            match[i][j]|=match[i-2][j];
                }
            }
        }
        return match[pLen][sLen];
    }
};
```

因为这道题是为数不多困难题里我自己头铁磨出来的，所以第一次这么认真做一篇题解，也不知道讲的好不好理解，希望能给大家一些新的思路和启发。但真正去着手这些文字解释和幻灯片的时候，我真的感到好累，因为无论是好内容、好排版和好演示中的任何一条都需要花费大量的精力去准备，所以我也不免开始由衷地钦佩题解区常驻的诸多大佬了，毕竟他们愿意花费那么多自己的时间却做知识的分享，这一点是真的很伟大的。至于我嘛，大概半年都不会点击“发布题解”这按钮了嘿嘿😅
当然，如果上述的内容有不理解的地方或者认为有误的地方，还烦请各位在评论区指出，我尽量帮忙解决(如果我会的而且不在弄论文的话~)。