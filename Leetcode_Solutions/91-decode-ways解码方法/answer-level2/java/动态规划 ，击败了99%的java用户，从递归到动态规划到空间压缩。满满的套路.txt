
递归和动态规划两种解法。本题解讲述如何从递推转换成动态规划。
 从后往前遍历。如果
以22067为例，从后往前遍历。
首先如果为7。很显然是1种7->G
如果为67。很显然还是1种67->FG
如果为067。结果为0。
如果为2067。 结果为numDecodings（20 67）+ numDecodings（2 067）= numDecodings（20 67）->TFG
如果为22067。 结果为numDecodings（2 2067）+ numDecodings（22 067）= numDecodings（2 2067）->BTFG

从中，我们可以看出规律。
如果开始的数为0，结果为0。
如果开始的数加上第二个数小于等于26。结果为 numDecodings（start+1）+ numDecodings（start +2）
如果开始的数加上第二个数大于26。结果为 numDecodings（start +1）
```
public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        return digui(s, 0);
    }

//递归的套路，加一个index控制递归的层次
    private int digui(String s, int start) {
        //递归的第一步，应该是加终止条件，避免死循环。
        if (s.length() == start) {
            return 1;
        }
        //以0位开始的数是不存在的
        if (s.charAt(start) == '0') {
            return 0;
        }
        //递归的递推式应该是如果index的后两位小于等于26，  
        // digui(s, start) = digui(s, start+1)+digui(s, start+2)   
        // 否则digui(s, start) = digui(s, start+1)
        int ans1 = digui(s, start + 1);
        int ans2 = 0;
        if (start < s.length() - 1) {
            int ten = (s.charAt(start) - '0') * 10;
            int one = (s.charAt(start + 1) - '0');
            if (ten + one <= 26) {
                ans2 = digui(s, start + 2);
            }
        }
        return ans1 + ans2;
    }
```
递归解法存在大量的重复计算从中可以看出，在计算中进行了大量的重复计算，因此。可以想办法将重叠子问题记录下来，避免重复计算。
 引入一个数组dp[]，用来记录以某个字符为开始的解码数。动态规划其实就是一个填表的过程。整个过程的目标就是要填好新增的dp[]数组。 
![图片.png](https://pic.leetcode-cn.com/d921902fe1b671733b837520f979415f9011ec07d0a9a862ea67c14663cf5a25-%E5%9B%BE%E7%89%87.png)

--------
```
public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int len = s.length();
        int[] dp = new int[len + 1];
        dp[len] = 1;
        if (s.charAt(len - 1) == '0') {
            dp[len - 1] = 0;
        } else {
            dp[len - 1] = 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                dp[i] = 0;
                continue;
            }
            if ((s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0') <= 26) {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
```
细心的话，会发现我们其实并不需要申请一个长度为len+1的数组来存储中间过程。其实dp[i]只和dp[i+1]以及dp[i+2]相关。
因此，此处可以继续空间压缩。
```
 public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int len = s.length();

        int help = 1;
        int res = 0;
        if (s.charAt(len - 1) != '0') {
            res = 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                help = res;
                res = 0;
                continue;
            }
            if ((s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0') <= 26) {
                res += help;
                //help用来存储res以前的值
                help = res-help;
            } else {
                help = res;
            }

        }
        return res;
    }
```
# [更多leetcode题解写在本人博客](http://51leetcode.top/tags?tag=leetcode)