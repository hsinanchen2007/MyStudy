#### 回溯

绝大部分树形问题（多叉树或者是二叉树）都可以通过回溯解决，而这道题抽象为树模型后就是：**求一颗二叉树从根结点到达叶子结点的路径总数**。

因为每次可能的选择都只有两个，犹如二叉树的两个分支。栗如：

对于数字 `13` ，你第一次可以只选择一位，那就是 `1` ，翻译成字符就是 `b`；你也可以两位都选，那就是 `13` , 翻译成字符为 `n`。

所以最多就只有两个选择：走左子树或走右子树，走到叶子结点就返回 1 ，代表这条路径可以到达终点。



#### 代码

```cpp
class Solution {
public:
    int backtrace(string& str, int pos) {
        int n = str.size();
        if (pos == n) {
            return 1;
        }
        if (pos == n-1 || str[pos] == '0' || str.substr(pos, 2) > "25") {
            return backtrace(str, pos+1);
        }
        return backtrace(str, pos+1) + backtrace(str, pos+2);
    }
    int translateNum(int num) {
        string str = to_string(num);
        return backtrace(str, 0);
    }
};
```



#### 动态规划

动态规划的思路和 [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) 是一样的。

爬楼梯这道题：爬楼梯时每次可以爬一层或两层，求有多少种不同的方法到达楼顶。而这道题换成了，每次可以选择一个数字或两个数字，用来合并成一个字符，求可以合成多少种字符串。

这道题的状态转移方程为：

$$dp[i]=\begin{cases}dp[i-1]&num[i]和num[i-1]不能合成一个字符\\dp[i-1] + dp[i-2]&num[i]和num[i-1]能够合成一个字符\end{cases}$$



#### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int dp[11];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < str.size(); i ++) {
            if (str[i-1] == '0' || str.substr(i-1, 2) > "25" ) {
                dp[i+1] = dp[i];
            } else {
                dp[i+1] = dp[i] + dp[i-1];
            }
        }
        return dp[str.size()];
    }
};
```



#### 最后

感谢您的观看！欢迎大家留言，一起交流讨论，共同进步。

至此，您已经学会使用回溯和动态规划解决此题，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)