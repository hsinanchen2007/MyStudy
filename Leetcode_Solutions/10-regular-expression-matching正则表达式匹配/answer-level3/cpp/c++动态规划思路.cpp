#### 题目：
实现简单正则匹配
***
#### 解法：动态规划
字符：```.``` 与 ```a~z``` 。  
数量：```*``` ，与其前的字符是一个整体。

```a*``` 结构具体实现几个a的作用规则非常复杂，不太可能直接if写，因此需要列举出所有的情况（0~n个a的作用），其中有一个匹配成功就算成功。  
- 选择状态  
```dp[i][j]``` 表示 ```s[0~i]``` 与 ```p[0~j]``` 是否匹配。
- 状态转移方程
$$
dp[i][j] = \begin{cases}
dp[i-1][j-1] & p[j]!='*'且check(s[i],p[j]) \\
false & p[j]!='*'且!check(s[i],p[j]) \\
dp[i][j-2] & p[j]=='*'且!check(s[i],p[j-1]) \\
发挥0个dp[i][j-2] || 发挥1个dp[i-1][j-2] || 发挥多个dp[i-1][j] & p[j]=='*'且check(s[i],p[j-1])
\end{cases}
$$
```0<=i<s.length()``` ，```0<=j<p.length()```  
其中check函数为：
```cpp
bool check(char a, char b){
        if(a=='.' || b=='.') return true;
        else return a==b;
    }
```
至此仍然需要解决两个问题：
1. 如果输入空串，开数组时会出错。  
让空串的匹配和正常串的匹配用同一套方法，可以统一在开头或者结尾加一个字符 ```?``` 。即让输入的串长度至少为1。
2. 状态转移方程中可能出现负数下标（边界）。  
为保证```i,j>=1```，可以让string的字符从1开始编号。结合第一个问题，可以在string的开头统一插入一个“起始符号”。
- 边界  
第0行，第0列需要初始化：  
```dp[0][0] = true```  
```dp[i][0] = false, 1<=i<s.length()```

$$
1<=j<p.length() \\
dp[0][j] = \begin{cases}
dp[0][j-2] & p[j]=='*'（等于*的j一定是偶数） \\
false & p[j]!='*' 
\end{cases}
$$

- 处理顺序  
涉及点在当前点左方、上方、左上方。处理顺序为从上到下，从左到右。
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        s.insert(s.begin(), '?');
        p.insert(p.begin(), '?');
        int slen=s.length(), plen=p.length();
        //初始化
        bool dp[slen][plen]={};
        dp[0][0] = true;
        for(int j=1; j<plen; j++){
            if(p[j]=='*') dp[0][j] = dp[0][j-2];
            else dp[0][j] = false;
        }
        //填表
        for(int j=1; j<plen; j++){
            for(int i=1; i<slen; i++){
                if(p[j]=='*'){
                    if(check(s[i], p[j-1])) dp[i][j] = dp[i][j-2]||dp[i-1][j-2]||dp[i-1][j];
                    else dp[i][j] = dp[i][j-2];
                }
                else{
                    if(check(s[i], p[j])) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[slen-1][plen-1];
    }

    bool check(char a, char b){
        if(a=='.' || b=='.') return true;
        else return a==b;
    }
};
```
![微信图片_20200311165818.png](https://pic.leetcode-cn.com/5bb5186b2bbc6bf9dae8c484781c5c78a1af6c234b5d4336eabb6a9d0f9d4663-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200311165818.png)
