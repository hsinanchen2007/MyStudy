# 状态
s原串  
p规则串

**dp[i][j]:  p的前j个  能否表示  s的前i个**

那答案就是`dp[s_len][p_len]`

**为什么下标不是减1**，后面讲。做了右偏移1位的处理，**方便处理边界情况**

---
# 约定
算是一些直觉把
我们认为: 
1. s串都是`小写字符`
2. p串有`小写字符`、`.`、`*`
3. p串不存在`#`开头，不存在连续两个`##`  【鲁棒性，程序可以加判断，一旦遇到就false】 **以防万一**


---
# 遍历顺序
```c
//固定规则串一个位置j 扫原串每个位置i
for (j)
    for (i)
        dp[i][j] = ....
```

# 确认状态，从p[j]出发
1. **p[j] 是小写字母**  `dp[i][j] = dp[i - 1][j - 1]`
    1. 对于p[j] == s[i],说明能接上去，`dp[i - 1][j - 1]  --转移--> dp[i][j]`
    2. 对于p[j] != s[i],***不管前面p的前（j-1）个能否表示 s的前（i-1）个***，`dp[i][j] = false`


2. p[j] == '.', `.`是万能匹配，所以p[j]这个`.`**一定匹配s[i]**,所以同样 `dp[i][j] = dp[i - 1][j - 1]`

3. p[j] == '*',由于`*`的定义，它需要看前一个，这里我们设`base = p[j - 1]`
    1. base是`*`,即`**`，我们假设不发生，wa了再说。。。。。确实也没嘛，因为没意义阿
    2. base不存在，就是说(j - 1)越界了，j是p串的第一个下标，也假设不发生。。。。
    3. base是`.`,即`.*`情况
    4. base是`小写字符`,即`a*`,`c*`这些情况

---
**对于3.3和3.4分析**
有如下几种情况
1. **用了0个base**，如
s:   **a**   
p:   **a**a*
`dp[i][j] = dp[i][j - 2]`


2. **用了1个base**,如
s:   **a**   
p:   **a***
`if base == s[i] --转移-->dp[i][j] = dp[i][j - 1]`


3. **用多个base**,如
s:   **aaaaa**   
p:   **a\***
`if base == s[i] --转移-->dp[i][j] = dp[i - 1][j]`

`可以从扫描顺序来理解
固定了 j 即现在的`*`位置，扫i，如果当前p的前j个已经能表示s的前i个，那i++更新后，如果s[i]还==base
那就可以从刚刚的dp[i - 1][j] 转移过来了`

---
# 开始coding，边界注意！
观察刚刚设计的状态转移方程，注意到`i-1，j-1，j-2`这些字眼
为了不出现`i-1 < 0`的情况 越界访问
我们先把s串，p串**右偏移一位**处理
```c
int s_len = s.size(), p_len = p.size();
s.resize(s_len + 1);
p.resize(p_len + 1);//要resize 不然还是原来的长度！！！ 即使你赋值结束符 ‘\0’
//右偏移
for (int i = s_len; i >= 1; --i) {
    s[i] = s[i - 1];
}
for (int i = p_len; i >= 1; --i) {
    p[i] = p[i - 1];
}
//s[s_len + 1] = p[p_len + 1] = '\0';  
// cout << s << endl << p << endl;
//没用噢！！！ 输出居然还是原来的长度【0，len - 1】 我要的是【1，len】
```
## 收获: 改string长度最好调用函数resize(),不要手动加‘\0’
---
## 一开始的边界
` dp[0][0] = true;//边界`
理解：空串能表示空串呀

---
# 坑点——s是空串

s:   ""   
p:   "c*a*"
`true`

`问题是什么`，s是空串，**直接不进主循环，直接返回初始值false**

这里思考了一下
**特判**了一下这种的情况，如下面代码
首先为什么会ture呢？
可以发现是`*`的缘故，`它可以用0个base！`

所以总结出
1. 规则串p若是**奇数，一定是非空的**，因为base和*搭配嘛
2. 若是偶数，那如果是`a*b*d*.*`这种**偶数位**是`*`的话就**能表示空**
```c
if (!s_len) {
    if (p_len & 1)
        return false;
    else {
        bool flag = true;
        for (int i = 2; i <= p_len; i += 2) {
            if (p[i] != '*') {
                flag = false;
                break;
            }
        }
        return flag;
    }
}
```
## 收获 判断string 不能 == ""来判断，应该用size() == 0
---
`好了 到此已经过了很多样例了`

又wa在
s:   "ab"   
p:   "**c\*c\***   .**\*c\*a\***  .  **.\*c\***"


发现了吗，又是这种`*`在偶数导致用了0个base

`我开始思考why？`

可以发现p的第一个`.`会匹配s的a
对于后面的`.*`也会匹配这个a，注意我已经把前面的`c*c*`当成用0个base了

关键错在dp[1][5] = 0（注意下标从1开始）
`它靠dp[i-1][j-1] = dp[0][4]转移，那么问题来了`


我从1开始扫描，你这个dp[0][4]怎么搞
而且`不单单dp[0][4]`
`我改下数据`
s:   "a"   
p:   "i*a"
`现在就是dp[0][2]需要=true了`

**这就是我觉得比较难想出来的一个细节**
dp[0][0]=true  dp[1到s_len][1到p_len] 
涉及的 i - 1、 j - 1、 j - 2
**只要处理好dp[0][j]这些情况 后面就可以一直转移，一劳永逸**

`实质就是，p的前j个是否能表示s空串`
怎么形成空串，**是不是就是上面说的`*`的作用**
所以我就可以从2下标一直看，是否`base*`这种情况，是就一直能表示空串，`dp[0][j] = true`
一旦出现不是，就说明到此为止，已经不能表示空串了
同样就处理了上面s空串的问题了，所以可以**注释上面的特判**
```c
for (int i = 2; i <= p_len; i += 2) {
    if (p[i] == '*' && (isalpha(p[i - 1]) || p[i - 1] == '.')) { //鲁棒性
        dp[0][i] = true;
    }
    else //一旦不是 就说明 前i个一定不能  构造 空串s了
        break;
}
```
# AC代码[]()
```c
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        s.resize(s_len + 1);
        p.resize(p_len + 1);//要resize 不然还是原来的长度！！！ 即使你赋值结束符 ‘\0’
        //右偏移
        for (int i = s_len; i >= 1; --i) {
            s[i] = s[i - 1];
        }
        for (int i = p_len; i >= 1; --i) {
            p[i] = p[i - 1];
        }
        //s[s_len + 1] = p[p_len + 1] = '\0';
        // cout << s << endl << p << endl;
       

        vector<vector<bool> > dp(s_len + 1, vector<bool>(p_len + 1, false));//全初始化false
        dp[0][0] = true;//边界
        char base;

        
        // if (!s_len) {
        //     if (p_len & 1)
        //         return false;
        //     else {
        //         bool flag = true;
        //         for (int i = 2; i <= p_len; i += 2) {
        //             if (p[i] != '*') {
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         return flag;
        //     }
        // }
        
        
        for (int i = 2; i <= p_len; i += 2) {
            if (p[i] == '*' && (isalpha(p[i - 1]) || p[i - 1] == '.')) { //鲁棒性
                dp[0][i] = true;
            }
            else //一旦不是 就说明 前i个一定不能  构造 空串s了
                break;
        }
        
        
        
        for (int j = 1; j <= p_len; ++j) {
            for (int i = 1; i <= s_len; ++i) {
                if (isalpha(p[j])) {
                    if (s[i] == p[j])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                }
                else if (p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*') {
                    base = p[j - 1];
                    if ((base == s[i] || base == '.') && (dp[i][j - 2] == true || dp[i][j - 1] == true || dp[i - 1][j] == true)) {
                         dp[i][j] = true;
                    }
                    else if (isalpha(base) && base != s[i])
                        dp[i][j] = dp[i][j - 2];
                    //if (dp[i][j - 2] == true || dp[i][j - 1] == true || dp[i - 1][j] == true)
                    //    dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[s_len][p_len];
    }
};
```