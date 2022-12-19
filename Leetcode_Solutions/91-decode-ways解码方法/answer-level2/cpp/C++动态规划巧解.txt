
![d.png](https://pic.leetcode-cn.com/5517c65323268182dd5a841efd6d34fe1d803fb3b35a198e9525ab94cb8090be-d.png)

```
class Solution {
public:
    bool accept(int index, int len, string &s)
    {
        string str=s.substr(index, len);
        int num = atoi(str.c_str());
        int l=1+(int)log10(num);
        if (num >= 1 && num <= 26 && l==str.size())
            return true;
        return false;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size());
        dp[0] = (accept(0,1,s)?1:0);
        for (int i = 1; i < s.size(); i++)
            dp[i] = (accept(i, 1, s)?dp[i-1]:0)+(accept(i-1, 2, s)?dp[(i-2<0?0:i-2)]:0);
        return dp[s.size()-1];
    }
};
```

其实这道题就是从第70题爬楼梯衍生来的

https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/

动态规划代码如下：
```
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

分析70题的代码后回到本题，dp用于保存符合的解码方法的总数，dp[0]和dp[1]是初始的解码方法的总数由于dp[1]的取值需要依赖for循环中的公式，所以我通过
dp[(i-2<0?0:i-2)]:0);这样的方式解决了，然后我们观察下下面这张图发现一下规律

![c.png](https://pic.leetcode-cn.com/09557f4e1f8b775b9b013d0c32a3736cc1e79d45943506f40d7563bc8072d029-c.png)

可知dp3是由dp1和dp2合成的，取决是否合成的因素是红色方框右侧的值满足法则与否，比如说如果位置4的值为0，那么不符合一位数取值在1～9的要求所以前面dp2是取不到的，位置3，4和在一起看，如果位置3，4组合成的数字为34，那么不符合二位数取值在10～26的要求，所以dp1取不到。总之，我们下面通过accept函数验证红色方框后面的数是否符合法则决定了我们能否取到前面的dp，所以我们就得到了方程：

`dp[i] = (accept(i, 1, s)?dp[i-1]:0)+(accept(i-1, 2, s)?dp[(i-2<0?0:i-2)]:0);`

当前符合法则的解析情况总数   ＝    之前符合法则的总数   ＋    再之前的符合法则的总数

其中accept(下标, 判断的字符串长度, 系统给出的字符串)，该函数用于截取字符串检测其整数是否符合法则(区间[1,26])，需要注意的是，我们对s="101"的这种情况当我们for循环遍历到的下标为2时，执行accept(i-1, 2, s)?dp[(i-2<0?0:i-2)]:0将截取"01"这个字符串进行判断，由于"01"转换为整数后为1，落在[1,26]区间内，会误认为符合要求，这将导致"11"和"101"都对应"AA"这个解析，显然是不符合要求的，所以我们需要先获取"01"这个字符串的长度，然后再通过1+(int)log10(num)计算出num对应的十进制整数位数，然后判断两者是否相等，这样就可以排出00,01这样的特殊情况。