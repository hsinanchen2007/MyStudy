### 解题思路
- 第一个双百很开心决定写下题解
- 这道题实际上是一个具有斐波那契特性的dp
- 但其中有几个坑
### 分析题目
    我们先分析一下题目,按照1->26对字母A->Z编码
    每个字母所占有的数字个数不为2即为1
    也就是说理论上我们可以设立一维dp数组
    dp[i] = dp[i-1] + dp[i-2]
    - 但是这里有些是我们不能相加的
        - 比如s[i-1] > 2 那么s[i-1]一定没办法与s[i]组成字母故此时dp[i] 不能加上dp[i-2]
        - 如果s[i] = 0 那么不能加上dp[i-1]
    - 何时能加dp[i-2] : s[i-1] 与 s[i] 组合形成的number：0<number<27
    - 何时能加dp[i-1] ：s[i] != 0 
### 初始化
    首先我们先对一维dp初始化，并处理一些特殊情况（按照如下的顺序）
    - s[0] = '0' : 首数字为0 结果一定为0
    - len == 1 :  结果为1
    - 将dp初始化为全0
    - dp[0] = 1
    -  0 < char < 27 dp[1] = 1
    - char != 20 or 10 dp[1] = 2
### 状态转换
```cpp
for(int i=2; i<len; ++i)
            {
                if(s[i-1]>'0'&&(s[i-1]<'2' || (s[i-1] == '2' && s[i] < '7')))
                    dp[i] += dp[i-2];
                if(s[i] != '0') dp[i] += dp[i-1];
            }
```
### 输出
```cpp
dp[len-1]
```
### 复杂度
- 时间：O(n)
- 空间：O(n)
### O（1）的空间复杂度
    可以对dp进行压缩，实际上只用了dp[i-1]和dp[i-2]可以用滚动数组压缩至2个存储空间
    O（1）
![image.png](https://pic.leetcode-cn.com/c2aa55aa51ca8a5376a82d447f16f721e212c6c44a1377d01b9a60efe982ae1f-image.png)
### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        // 斐波那契数列
        int len = s.size();
        if(len < 2) {return s[0] > '0' ? 1:0;} // 特判
        else
        {
            // 0 < char < 27
            vector<int> dp(len, 0);
            // 初始化
            if(s[0] == '0')
            {
                return 0; // char = 0……
            }
            else
            {
                ++dp[0];
                if(s[0] < '2' ||(s[0] == '2' && s[1] < '7')) ++dp[1];  // 0< char < 27
                if(s[1] != '0') ++dp[1];// char != 10 or 20
            }
            for(int i=2; i<len; ++i)
            {
                if(s[i-1]>'0'&&(s[i-1]<'2' || (s[i-1] == '2' && s[i] < '7')))
                    dp[i] += dp[i-2];
                if(s[i] != '0') dp[i] += dp[i-1];
            }
            return dp[len-1];
        }
    }
};
```