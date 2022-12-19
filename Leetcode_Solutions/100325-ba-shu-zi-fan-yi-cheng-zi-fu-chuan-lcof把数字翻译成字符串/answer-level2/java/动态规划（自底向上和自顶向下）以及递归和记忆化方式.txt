### 前言
该题应该跟LeetCode题库中的某一题很像，忘了是哪题，大概印象是DP方式，转移方程中有一个我理解了很久才弄懂的，是关于最后一个数字或者字符，跟前一个数字或者字符，能否合并到一起来产生出不同的解的数量。这个就是做这题之前的想法，那既然不记得了，废话不多说，开始重新搞一下这题。

### 动态规划, 自底向上
题目输入就只有一个int数字，范围在`0 <= num < 2^31`之间。
如果转变一下把数字看成一个数组，每一位就是数组中的元素。
那么该题，就变成了输入一个数组，判断数组n有多少中不同翻译的方法。
其中转移方程跟当前数组的数字和前一个数字有关
如果前一个数字是`1`，那么不管怎么样，最后一个数字都可以跟前一个数字合并起来翻译。
如果前一个数字是`2`，那么当前数字只能在`0~5`之间，这样最后一个数字也能跟前一个数字合并起来翻译。
其他Else的情况，最后一个数字只能单独的存在并翻译，实际上，对于之前那么多数字来说加上最后一个`失败`的数字对于翻译种数来说就不会有增加了，比如`99999`不管后面加多少个`9`，最后还是只有一种翻译。好了，整理一下DP信息吧：

* State: `dp[i]`表示`i`长度的数组，总共有多少中翻译方法。
* Transfer Function: If(Condition): `dp[i] = dp[i-1] + dp[i-2], i > 2` Else: `dp[i] = dp[i-1]`, Condition: `pre == 1 || pre == 2 && cur <= 5`
* Initial Condition: dp[0] = 1, dp[1] = 1
* Answer: dp[n]
* Time: O(n)
* Space: O(n)

<br/>
#### DP 自底向上

```java
    public int translateNum(int num) {
        if (num <= 9) return 1;

        List<Integer> numList = new ArrayList<>();
        while (num > 0) {
            numList.add(0, num % 10);
            num /= 10;
        }

        int len = numList.size(), i = 1;
        int[] nums = new int[len + 1];
        for (int n : numList)
            nums[i++] = n;

        int[] dp = new int[len + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (i = 2; i <= len; i++) {
            if (nums[i - 1] == 1 || nums[i - 1] == 2 && nums[i] <= 5) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len];
    }
```

从以上代码可以看出，状态空间只依赖于前一个和前前个。所以压缩状态空间至O(1)。

#### DP 自底向上 压缩状态空间
```java
    public int translateNum(int num) {
        if (num <= 9) return 1;

        List<Integer> numList = new ArrayList<>();
        while (num > 0) {
            numList.add(0, num % 10);
            num /= 10;
        }

        int len = numList.size(), i = 1;
        int[] nums = new int[len + 1];
        for (int n : numList)
            nums[i++] = n;

        int pre2 = 1, pre1 = 1, cur = 0;
        for (i = 2; i <= len; i++) {
            if (nums[i - 1] == 1 || nums[i - 1] == 2 && nums[i] <= 5) {
                cur = pre2 + pre1;
            } else {
                cur = pre1;
            }
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
```

既然都写了DP的自底向上，那么就当练练手，看看写一下该题的DP自顶向下试试看。
由于初始状态是在`dp[0]`和`dp[1]`上面，那么不管怎么样从顶开始，都需要递归到最底层拿到初始值，然后递归回来。
那先来一个递归版本： 

#### 递归版本
```java
    public int translateNum(int num /* 0 <= num < 2^31 (2147483648) **/) {
        if (num <= 9) return 1;
        return fn(num);
    }

    private int fn(int n) {
        if (n == 0) {
            return 1;
        }
        int cur = n % 10;
        int pre = (n / 10) % 10;
        if (pre == 1 || pre == 2 && cur <= 5) {
            return fn(n / 10) + fn(n / 100);
        } else {
            return fn(n / 10);
        }
    }
```

递归版本写完后，发现代码写的有点啰嗦，其实两行足以。

```java
    public int translateNum(int num /* 0 <= num < 2^31 (2147483648) **/) {
        if (num == 0) return 1;
        return ((num / 10) % 10 == 1 || (num / 10) % 10 == 2 && num % 10 <= 5) ?
                translateNum(num / 10) + translateNum(num / 100) :
                translateNum(num / 10);
    }
```

如果把递归看成一颗树的话，其中树下面的有很多`子树`都重复计算了。那再加上`memorization`把重复计算的给缓存起来。
![image.png](https://pic.leetcode-cn.com/d510d42d89cc26329287430d3eef06fe857d2b542e425bf67704cfe30209b67c-image.png)


```java
class Solution {
    private int[] dp = new int[11]; // memorization

    public int translateNum(int num /* 0 <= num < 2^31 (2147483648) **/) {
        if (num <= 9) return 1;
        return fn(num, 0);
    }

    private int fn(int n, int depth) {
        if (dp[depth] != 0) return dp[depth];
        if (n == 0) {
            return 1;
        }
        int cur = n % 10;
        int pre = (n / 10) % 10;
        int ans = (pre == 1 || pre == 2 && cur <= 5) ?
                fn(n / 10, depth + 1) + fn(n / 100, depth + 2) :
                fn(n / 10, depth + 1);
        dp[depth] = ans;
        return ans;
    }
}
```

### 总结
写了那么多，每份代码都能在0～1ms之间通过LC测试。看来要发挥DP的威力，这个计算量得大啊。