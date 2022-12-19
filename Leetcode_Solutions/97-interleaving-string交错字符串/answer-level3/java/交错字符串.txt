#### 方法 1：暴力

最基本的想法就就是找到所有 $s1$ 和 $s2$ 能够形成的交错字符串。为了实现这样的想法，我们使用回溯。我们首先将 $s1$ 中的第一个字符作为开始字符，然后将 $s1$ 字符串剩余部分和 $s2$ 字符串所有可能情况添加在这个字符后面，每次用完所有字符后检查字符串与 $s3$ 是否一致。类似的，我们可以选择 $s2$ 第一个字符作为开始字符，然后将 $s2$ 剩余字符串和 $s1$ 字符串回溯地添加到该字符后面，看是否能形成 $s3$ 。

为了实现回溯函数，我们回溯地调用函数 $is\_Interleave(s1,i+1,s2,j,res+s1.charAt(i),s3)$ ，表示我们选择了 $s1$ 当前字符作为下一个字符，然后又调用函数 $is\_Interleave(s1,i,s2,j+1,res+s2.charAt(j),s3)$ ，这表示选择了 $s2$ 的当前字符作为下一个字符。这里， $res$ 表示 $s1$ 和 $s2$ 已经添加到结果字符串里的部分。如果某一次调用，返回的结果是 $True$ ，这表示至少有一个交错字符串是符合要求 $s3$ 的。当所有情况都被考虑后，过程结束并返回 $False$ 。

让我们来看一个小例子：

```
s1="abc"
s2="bcd"
s3="abcbdc"
```

首先，我们选择 $s1$ 字符串的第一个字母 'a' ，所以递归进去后， $s1$ 变为 "bc" ， $s2$ 保持不变为 "bcd" ，$s3$ 为 "abcbdc" 。当函数返回结果的时候，我们再次调用递归函数，但是这次 3 个字符串分别变为 $s1$="abc" ， $s2$="cd" ，$s3$="abcbdc" 。

```Java []
public class Solution {
    public boolean is_Interleave(String s1,int i,String s2,int j,String res,String s3)
    {
        if(res.equals(s3) && i==s1.length() && j==s2.length())
            return true;
        boolean ans=false;
        if(i<s1.length())
            ans|=is_Interleave(s1,i+1,s2,j,res+s1.charAt(i),s3);
        if(j<s2.length())
            ans|=is_Interleave(s1,i,s2,j+1,res+s2.charAt(j),s3);
        return ans;

    }
    public boolean isInterleave(String s1, String s2, String s3) {
        return is_Interleave(s1,0,s2,0,"",s3);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^{m+n})$ 。 $m$ 是 $s1$ 的长度， $n$ 是 $s2$ 的长度。

* 空间复杂度：$O(m+n)$ 。递归栈的深度最多为 $m+n$ 。

<br />
#### 方法 2：记忆化回溯

**算法**

在上面提到的回溯方法中，我们只考虑了两个字符串的所有可能交错字符串情况。但有可能 $s1$ 和 $s2$ 的相同部分在不同顺序处理情况下，已经被计算过了。不管处理的顺序是如何的，如果已经产生的字符串与要求字符串 $s3$ 是匹配的，那么剩余的结果字符串只与 $s1$ 和 $s2$ 剩余的部分有关系，而与之前已处理过的部分没有关系了，所以回溯方法导致了冗余的计算。

这种冗余可以通过在回溯的过程中使用记忆化去除。为了达到这个目的，我们维护 3 个指针 $i, j, k$ ，分别指向 $s1, s2, s3$ 当前位置。同时，我们维护一个 2D 的记忆数组，记录目前已经处理过的子字符串。 $memo[i][j]$ 保存的值是 1/0 或者 -1 ，取决于状态，也就是 $s1$ 下标为 $i^{th}$ 且 $s2$ 下标为 $j^{th}$ 是否已经被处理过。与方法 1 类似，我们通过判断 $s1$ 的当前字符（通过指针 $i$ 表示）与 $s3$ 的当前字符（通过指针 $k$ 来表示），如果相等，我们可以将它放到暂存的结果串中，并同样递归调用函数：

 $$is\_Interleave(s1, i+1, s2, j, s3, k+1,memo)$$

所以，我们要增加 $i$ 和 $k$ ，因为这两个指针之前的字符串都已经被处理过了。类似的，我们从第二个字符串选择当前字符，然后继续回溯调用。回溯函数停止的条件是 $s1$ 或者 $s2$ 有一个已经被完全处理完了。比方说， $s1$ 处理完时，我们直接将 $s2$剩余部分和 $s3$ 剩余部分进行比较。当从当前回溯调用返回时，我们用记忆化数组保存返回的结果，以便下次再遇到相同情况时，回溯函数不会被调用，而直接返回记忆化数组里的值。

 ```Java []
 public class Solution {
    public boolean is_Interleave(String s1, int i, String s2, int j, String s3, int k, int[][] memo) {
        if (i == s1.length()) {
            return s2.substring(j).equals(s3.substring(k));
        }
        if (j == s2.length()) {
            return s1.substring(i).equals(s3.substring(k));
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        boolean ans = false;
        if (s3.charAt(k) == s1.charAt(i) && is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)
                || s3.charAt(k) == s2.charAt(j) && is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        int memo[][] = new int[s1.length()][s2.length()];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                memo[i][j] = -1;
            }
        }
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^{m+n})$ 。$m$ 是 $s1$ 的长度且 $n$ 是$s2$ 的长度。

* 空间复杂度：$O(m * n)$ 。记忆化数组需要 $m * n$ 的空间。

<br />
#### 方法 3：使用二维动态规划

**算法**

上面提到的回溯方法包含每次从 $s1$ 或者 $s2$ 中选择一个字符并调用递归函数去检查 $s1$ 和 $s2$ 剩余部分能否形成 $s3$ 剩余部分的交错字符串。在现在这种方法中，我们用另一种思路来考虑同样的问题。这里我们考虑用 $s1$ 和 $s2$ 的某个前缀是否能形成 $s3$ 的一个前缀。

这个方法的前提建立于：判断一个 $s3$ 的前缀（用下标 $k$ 表示），能否用 $s1$ 和 $s2$ 的前缀（下标分别为 $i$ 和 $j$），仅仅依赖于 $s1$ 前 $i$ 个字符和 $s2$ 前 $j$ 个字符，而与后面的字符无关。

为了实现这个算法， 我们将使用一个 2D 的布尔数组 $dp$ 。$dp[i][j]$ 表示用 $s1$ 的前 $(i+1)$ 和 $s2$ 的前 $(j+1)$ 个字符，总共 $(i+j+2)$ 个字符，是否交错构成 $s3$ 的前缀。为了求出 $dp[i][j]$ ，我们需要考虑 2 种情况：

 1. $s1$ 的第 $i$ 个字符和 $s2$ 的第 $j$ 个字符都不能匹配 $s3$ 的第 $k$ 个字符，其中 $k=i+j+1$ 。这种情况下，$s1$ 和 $s2$ 的前缀无法交错形成 $s3$ 长度为 $k+1$ 的前缀。因此，我们让 $dp[i][j]$ 为 $False$。

2. $s1$ 的第 $i$ 个字符或者 $s2$ 的第 $j$ 个字符可以匹配 $s3$ 的第 $k$ 个字符，其中 $k=i+j+1$ 。假设匹配的字符是 $x$ 且与 $s1$ 的第 $i$ 个字符匹配，我们就需要把 $x$ 放在已经形成的交错字符串的最后一个位置。此时，为了我们必须确保 $s1$ 的前 $(i-1)$ 个字符和 $s2$ 的前 $j$ 个字符能形成 $s3$ 的一个前缀。类似的，如果我们将 $s2$ 的第 $j$个字符与 $s3$ 的第 $k$ 个字符匹配，我们需要确保 $s1$ 的前 $i$ 个字符和 $s2$ 的前 $(j-1)$ 个字符能形成 $s3$ 的一个前缀，我们就让 $dp[i][j]$ 为 $True$ 。

可以用下面的例子进行说明：

```
s1="aabcc"
s2="dbbca"
s3="aadbbcbcac"
```

<![image.png](https://pic.leetcode-cn.com/617399ffd2e766b27898847c9941dae3dc1a82ccfe8123cb4590bfe9518b7cf7-image.png),![image.png](https://pic.leetcode-cn.com/d36ef66f33c0e99d4a9df2dfd2e0aea88d36072a987da07a4f9d7f4ec0e1fbda-image.png),![image.png](https://pic.leetcode-cn.com/9ccb967ea67a9fa84a19f0a79d92ddbdb6e7139eb247cc3be5b675b6e73f9df6-image.png),![image.png](https://pic.leetcode-cn.com/60e346eb704c1504d358f09df3ee1ead2eec77a80d9d8b9771fb2710db9e4e32-image.png),![image.png](https://pic.leetcode-cn.com/da3f627e58e94ae4086823fa960aece3a7d60a925eb93bc0d41c9f172204d817-image.png),![image.png](https://pic.leetcode-cn.com/f0e37131f6b1a374317d9f2a875054610bfc00721f9f5d2b426348978b0a3bc8-image.png),![image.png](https://pic.leetcode-cn.com/761a3e2a679ff75e847cde0573831f52b094412dd32546b9a8e9aec08848b311-image.png),![image.png](https://pic.leetcode-cn.com/0a04648edab30d6b4c5de28230b2dc525fa2887fa7f4afe6f4bf7d39409c50b2-image.png),![image.png](https://pic.leetcode-cn.com/795ea6996c20d7f0bec97f7de8072c0c291edd36c024119f19694a5a0e3c039f-image.png),![image.png](https://pic.leetcode-cn.com/8f340aad2958933660d3911fef68aa35fa688877fe9c64cccaeabff927d2fd02-image.png),![image.png](https://pic.leetcode-cn.com/27923f1a62c87b5d1e43da62c992f4cb567c6eb400becd7088b824cc537c907d-image.png),![image.png](https://pic.leetcode-cn.com/ab9a71291173c7a8fcc225636a64dd2b33aff0f1dbca32f7b16ac4ee3dfeae10-image.png),![image.png](https://pic.leetcode-cn.com/5c311949beb71b1c96691a8fd21d45b0a7f10bf82aba3f24de4c70bb33eee991-image.png),![image.png](https://pic.leetcode-cn.com/e618fd065113f5dfbebcd83bcf95975e26567da8ce2571d2ded486f79065994a-image.png),![image.png](https://pic.leetcode-cn.com/b8d5ce69695b39a4d94692f8880f0231d993ad41240a5cac3473ddaeeaf8eef3-image.png),![image.png](https://pic.leetcode-cn.com/462d0aa3332c89f9176120dcd571a6901a833cd2c0676049a8064295ad05e68c-image.png),![image.png](https://pic.leetcode-cn.com/9092c27c51a70efdaa485b0571f1e781e5c3af16eef0e3f41cfa65b6e347da26-image.png),![image.png](https://pic.leetcode-cn.com/48563cdc3cdc7faade851c08229d491a576f03e8161adedf71fc2222a482b49b-image.png),![image.png](https://pic.leetcode-cn.com/f39d97e3bc65f33568e0571cf3bb5f1838430a0b70ef92ccdb122ac7803bda2c-image.png),![image.png](https://pic.leetcode-cn.com/7918c2c0362369bea9c5e7445e41a296f01588e18b8c3f47e3f8d66d6f2fe6ad-image.png),![image.png](https://pic.leetcode-cn.com/3ab042d1f5ae8f3fca747644552e0026c6512ee6d0a94063b7b3191491b0283d-image.png),![image.png](https://pic.leetcode-cn.com/4b5dc29bce6f98d8bb73557249ee81df87897c8f1a21f323338e429214cc5591-image.png),![image.png](https://pic.leetcode-cn.com/04bb48309fea55998983e6317f8508cefa22c20dd824c862625acfa60e2efe03-image.png),![image.png](https://pic.leetcode-cn.com/319f08416b1e5504caf71dd742fc94211ff3b43eb5b34f098ea5e7651464cfc8-image.png),![image.png](https://pic.leetcode-cn.com/a046049f67a51c94107a314ddeda6ac731c5380fa09a59357ea8d4272e2fd278-image.png),![image.png](https://pic.leetcode-cn.com/04c34de96bbc1c5b5c335d47b61c3b67d24a940177e467451796d5bf7a8f7428-image.png),![image.png](https://pic.leetcode-cn.com/e7839a16a968f0dd794256***bc0416817032bbd95cdf2c7cd3408fd0e0f5cad-image.png),![image.png](https://pic.leetcode-cn.com/5e370419425f6f0b332475352691a97f3c43d25846d7d7170f4132052b19b0fa-image.png),![image.png](https://pic.leetcode-cn.com/472fba59bc577052da3d984250224c81033ca70de3ef7e79b3154fe4308236a4-image.png),![image.png](https://pic.leetcode-cn.com/92ca926e31c800190ca7fd92590213003bb7abe4f177968911d3e5af10c0a81a-image.png),![image.png](https://pic.leetcode-cn.com/46faafa86a2946634c117a7f44e0b98faa111a6514562d43d7a3459af730d53a-image.png),![image.png](https://pic.leetcode-cn.com/b6e3050033f8cb0d1a110c95fd85d8810711966c4a0cf91fb4f2c14e9ff0ef2a-image.png),![image.png](https://pic.leetcode-cn.com/c2c00fa88c6254b4a6270383f56cf2ddd6da94fc9ffa49dcaeba243b3a6857ec-image.png),![image.png](https://pic.leetcode-cn.com/7ed0014fe86fdeb23c00f1944a8df9c054c8651a75022a86f79739e77f4cfe8a-image.png),![image.png](https://pic.leetcode-cn.com/56ca2f6201abfdac0cf71c89d8530c7a093afc28b8c512cc7b484d2980841a03-image.png),![image.png](https://pic.leetcode-cn.com/1ea87cbbf785bc31fbc4f10349545947a3bd7dd5c182ca7d038b054b2577e8e2-image.png)>

```Java []
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        boolean dp[][] = new boolean[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m \cdot n)$ 。计算 $dp$ 数组需要 $m*n$ 的时间。

* 空间复杂度：$O(m \cdot n)$。2 维的 $dp$ 数组需要 $(m+1)*(n+1)$ 的空间。 $m$ 和 $n$ 分别是 $s1$ 和 $s2$ 字符串的长度。


<br />
#### 方法 4：使用一维动态规划

**算法**

这种方法与前一种方法基本一致，除了我们仅使用一维 $dp$ 数组去储存前缀结果。我们利用 $dp[i-1]$ 的结果和 $dp[i]$ 之前的结果来计算 $dp[i]$ ，即滚动数组。

 ```Java []
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        boolean dp[] = new boolean[s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
                } else if (j == 0) {
                    dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
                } else {
                    dp[j] = (dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }
        return dp[s2.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m \cdot n)$；长度为 $n$ 的 $dp$ 数组需要被填充 $m$ 次。

* 空间复杂度：$O(n)$；$n$ 是字符串 $s1$ 的长度