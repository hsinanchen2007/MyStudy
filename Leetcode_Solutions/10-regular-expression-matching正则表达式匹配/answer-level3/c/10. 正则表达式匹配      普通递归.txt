### 解题思路
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。



### 代码

```c



bool isMatch(char* s, char* p){
    int lens = strlen(s);
    int lenp = strlen(p);

    if(lenp == 0)
        return lens == 0;

    bool first  = lens > 0 && (s[0] == p[0] || p[0] == '.');
    
//解释下这里为啥fisrt　真或假都执行　(isMatch(s,p+2))，　
//大多isMatch(s,p+2)可以改写成这样 (!first&&isMatch(s,p+2)) 即first不对时，ｐ跳过重新开始
    // 比如这种case: "aab"  "a*b" 　就可以第三个ｂ的fisrt不匹配，ｐ需要跳过重新开始。
 //  但是这种case: "aaa"  "a*a"  就会判断有误，因为 第三个ａ依然是匹配的，p不＋２结束不了
   // 所以即使first为true,也要每个ｓ都执行下isMatch(s,p+2)，　才能“aaa“正常退出。　　
   // 比如:"aaa"   "ab*a*c*a"  也是true
    if(lenp > 1 && p[1] == '*')
        return isMatch(s,p+2) || (first&&isMatch(s+1,p));
    else
        return first && isMatch(s+1,p+1);
}
```