#### 方法 1：使用最长公共子序列 [Time Limit Exceeded]

**算法**

为了求得最少删除次数，我们可以求出串 $s1$ 和串 $s2$ 最长公共子序列，我们记为 $lcs$。如果我们能求得 $lcs$ 的值，我们可以轻易地求出答案，为 $m + n - 2*lcs$。这里 $m$ 和 $n$ 分别是给定字符串 $s1$ 和 $s2$ 的长度。

上述等价关系成立的原因是如果两个字符串完全不匹配（也就是两个字符串没有任何一个字符相同），那么总删除次数是 $m + n$。如果两个字符串存在一个公共子序列，长度为 $lcs$，两个字符串我们都可以减少 $lcs$ 次删除操作，也就是总共减少 $2lcs$ 次删除操作，也就得到了上述等式。

为了找到最长公共子序列，我们使用递归函数 `lcs(s1, s2, i, j)`，它返回 $s1$ 到第 $i$ 个位置为止， $s2$ 到第 $j$ 个位置为止的最长公共子序列。为了求出这个函数的值，我们首先比较 $s1[i-1]$ 和 $s2[j-1]$ 是否相同，如果相同，我们可以考虑两个字符串都去掉 1 个字符后的函数结果，也就是 `lcs(s1, s2, i-1, j-1)$。

如果两个字符串的最后一个字符不相等，我们有两种选择，一种是比较 $s1$ 倒数第二个字符与 $s2$ 最后一个字符是否相等， 另一种选择是比较 $s2$ 倒数第二个字符与 $s1$ 最后一个字符是否相等。我们取两者中的较大值为当前函数的结果。

通过以上的讨论，函数 `lcs(s1, s2, m, n)$ 可以返回我们需要的 $lcs$ 的值。

```Java []

public class Solution {
    public int minDistance(String s1, String s2) {
        return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length());
    }
    public int lcs(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return 1 + lcs(s1, s2, m - 1, n - 1);
        else
            return Math.max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^{max(m,n)})$。递归树的大小最多为 $2^(m+n)$，$m$ 和 $n$ 分别是 $s1$ 和 $s2$ 的字符串长度。

* 空间复杂度：$O(\text{max}(m,n))。递归树的深度最多为 $\text{max}(m,n)$。

#### 方法 2：带记忆化的最长公共子序列 [Accepted]

**算法**

我们观察到在上一种方法中，在求解 $lcs$ 值的过程中，我们做了非常多冗余的函数调用，因为相同的 $i$ 和 $j$ 值在不同的函数调用路径中会重复求解。只要相同的 $i$ 和 $j$ 对应的函数被调用一次，我们可以使用 $memo$ 数组保存相应函数的返回值来避免后续访问的冗余。$memo[i][j]$ 被用来保存函数调用 $lcs(s1, s2, i ,j)$ 的返回值。

因此，通过返回已经在 $memo$ 数组中保存的值，我们可以给搜索过程极大程度的剪枝。

```Java []
public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] memo = new int[s1.length() + 1][s2.length() + 1];
        return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length(), memo);
    }
    public int lcs(String s1, String s2, int m, int n, int[][] memo) {
        if (m == 0 || n == 0)
            return 0;
        if (memo[m][n] > 0)
            return memo[m][n];
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        else
            memo[m][n] = Math.max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));
        return memo[m][n];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m*n)$。大小为 $m * n$ 的 $memo$ 数组每个元素最多会被赋值一次。 $m$ 和 $n$ 分别是 $s1$ 和 $s2$ 字符串的长度。

* 空间复杂度：$O(m*n)$。 $memo$ 数组大小为 $m * n。同时递归树的深度最多为 $\text{max}(m,n)$。

#### 方法 3：最长公共子序列 - 动态规划 [Accepted]

**算法**

另一个获得 $lcs$ 值的办法是动态规划。我们来看看它的实现思想和具体方法。

我们使用一个二维数组 $dp$， $dp[i][j]$ 表示 $s1$ 前 $i$ 个字符和 $s2$ 前 $j$ 个字符中最长公共子序列。我们逐行填充 $dp$ 数组。

对于每一个 $dp[i][j]$，我们有 2 种选择：

1. 字符 $s1[i-1]$ 和 $s2[j-1]$ 匹配，那么 $dp[i][j]$ 会比两个字符串分别考虑到前 $i-1$ 个字符 和 $j-1$ 个字符的公共子序列长度多 1 。所以 $dp[i][j]$ 被更新为 $dp[i][j] = dp[i-1][j-1] + 1$。注意到 $dp[i-1][j-1]$ 已经被求解过了，所以可以直接使用。

2. 字符 $s1[i-1]$ 和 $s2[j-1]$ 不匹配，这种情况下我们不能直接增加已匹配子序列的长度，但我们可以将之前已经求解过的最长公共子序列的长度作为当前最长公共子序列的长度。但是我们应该选择哪一个呢？事实上此时我们有 2 种选择。我们可以删除 $s1$ 或者 $s2$ 的最后一个字符然后将对应的 $dp$ 数组的值作比较，也就是取 $dp[i-1][j]$ 和 $dp[i][j-1]$ 的较大值。

最后，与前面方法类似的，我们获得删除次数 $m + n - 2*dp[m][n]$ ，其中 $m$ 和 $n$ 分别是 $s1$ 和 $s2$ 的字符串长度,，$dp[m][n]$ 是两个字符串的最长公共子序列。

<![image.png](https://pic.leetcode-cn.com/39bba0c7b3b286b0c256d4ab0fad8d0eadcbec80bb02317e6de6ed57d685e2fe-image.png),![image.png](https://pic.leetcode-cn.com/e974fa923b7b0c86f37a01ce200140b78022fbef8fd978a6e2117771f337988e-image.png),![image.png](https://pic.leetcode-cn.com/1b938cb27e27a6db761a314083b5060df24a2eb0b21398ab45ad6cdd018f2f03-image.png),![image.png](https://pic.leetcode-cn.com/30cdcf415e67164cfbc20c2b1bfb223d2edef3c560594233f24ebe55f8d3564e-image.png),![image.png](https://pic.leetcode-cn.com/933a831747638913f8b4969c2af553ed05aa13cfcbc00fe67fd13a6d4020afec-image.png),![image.png](https://pic.leetcode-cn.com/1c4d6245723770fb7fc515462c83435e25caf45e6fdc9f79f7b009f564e83f3d-image.png),![image.png](https://pic.leetcode-cn.com/1fe057b3c254788496ba0f5ade185ff37e3cea0d5b0ce55a0adb0ab4a6b72ba4-image.png),![image.png](https://pic.leetcode-cn.com/8b51a5c57007ab792a1def76a70dce12468f7b4284e400217cdaaac127833817-image.png),![image.png](https://pic.leetcode-cn.com/f7329704a6e7c32c7b248f053f818945ed0d18057b5f629d329e26cf9e20f9b2-image.png),![image.png](https://pic.leetcode-cn.com/396a1fffdc33ad41d2c2d6be40616c0ea8bbbcc5f76a957ceeec9f4635736010-image.png),![image.png](https://pic.leetcode-cn.com/2c9ea6e6fe52c47ba9761339028c201f9c5b28d20071a70a63a659db4f4696ab-image.png),![image.png](https://pic.leetcode-cn.com/ec5064379ea87a7073a559a2cd6b726c32b1f8598ac94d712d769b35b9c6164a-image.png),![image.png](https://pic.leetcode-cn.com/8fa250279b9592b7a497f20c1e4e79394e914a4f34cf9a6dc3306462e2ffd6b6-image.png),![image.png](https://pic.leetcode-cn.com/088d7d79b6f2e2a058ac63defa6e2ff03313bf684d38d6b8e4ae53985beb4b94-image.png),![image.png](https://pic.leetcode-cn.com/6a993ab58b121f25b0046008a6e622a0202634cf863dfc3945e475e05ffd87c2-image.png),![image.png](https://pic.leetcode-cn.com/e91e27f92c98aee42b0a31907f469b7d0ba3423ff7ae139f2e8e4816a0d1e350-image.png),![image.png](https://pic.leetcode-cn.com/ce1ba49b49e96ec8c788ee5ee03aa905915a552046b78c777d2956f9ef0a1001-image.png),![image.png](https://pic.leetcode-cn.com/115bc5da4727760bf205bb08dca79ad56d7e3f7e4fac14235d523d13a1b9611c-image.png),![image.png](https://pic.leetcode-cn.com/9ba6b805cb0bf227f00aa169d5208f72ea34d02bbc82c248a39e0546e11ba0f7-image.png),![image.png](https://pic.leetcode-cn.com/0820adfbc5ee732d95d8485a740272f8af146d079fa2700becb13cb9612e914d-image.png),![image.png](https://pic.leetcode-cn.com/8b3112d850005499c4fa1fd82be4cbb0446187ea1a91f82326ac4babffe3bbd8-image.png),![image.png](https://pic.leetcode-cn.com/72ebfdfabbf243996fa68eeecc4d03119feb8b4e92b8e98e99756bdd8f623b28-image.png),![image.png](https://pic.leetcode-cn.com/b407fad018e582af0a1b65d975ed984e00d21e122082a90328d0a26086685cac-image.png),![image.png](https://pic.leetcode-cn.com/5ea767072d6cd18f03860b80c6f43223a25ddca3c8519c596ee6b9abc782b02a-image.png),![image.png](https://pic.leetcode-cn.com/cc1b174774f044d706729c0d04c2a46a6880e37c8e89c39313f6ea490f563af7-image.png),![image.png](https://pic.leetcode-cn.com/116e84c7c4404f45448e8733e0be87ca94d93389bc01eb88a4932650857a3b06-image.png),![image.png](https://pic.leetcode-cn.com/9b70c13ce8f8097ebb004979a7c27ca6bfefac2d7df66cf13519f5f34ab7d1f2-image.png),![image.png](https://pic.leetcode-cn.com/97eb524323b3d1a492de5969f9640ff7cc91dfdb57fe53772794edc81988b058-image.png)>

```Java []
public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    continue;
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return s1.length() + s2.length() - 2 * dp[s1.length()][s2.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m*n)$。我们需要填充大小为 $m * n$ 的数组 $dp$。$m$ 和 $n$ 分别是 $s1$ 和 $s2$ 字符串的长度。

* 空间复杂度：$O(m*n)$。使用了大小为 $m * n$ 的 $dp$ 数组。

#### 方法 4：不使用 LCS 的动态规划 [Accepted]:

**算法**

此方法中，我们不通过求解 LCS 再求解删除次数的方法来求解问题，我们直接使用动态规划来求解删除次数。

我们使用二维数组 $dp$，现在 $dp[i][j]$ 表示 $s1$ 串前 $i$ 个字符和 $s2$ 串前 $j$ 个字符匹配的最少删除次数。同样我们逐行求解 $dp$ 数组。为了求出 $dp[i][j]$ ，我们只考虑 2中情况：

1. $s1[i-1]$ 和 $s2[j-1]$ 匹配，那么我们只需要让 $dp[i][j]$ 赋值为 $dp[i-1][j-1]$ 即可。这是因为两个字符串能匹配的字符不需要被删除。

2. 字符 $s1[i-1]$ 和 $s2[j-1]$不匹配。这种情况下，我们需要考虑删除两个字符中的哪一个，同时需要增加一次删除操作。两种可能的选择是 $dp[i-1][j]$ 和 $dp[i][j-1]$。我们从中选择较小值。

最后，$dp[m][n]$ 就是我们需要的最少删除次数，$m$ 和 $n$ 分别是字符串 $s1$ 和字符串 $s2$ 的长度。

<![image.png](https://pic.leetcode-cn.com/7d5e9d7cb4933188d866b4cd5762bb06d65c400efae4e5c5b1c34895297a1270-image.png),![image.png](https://pic.leetcode-cn.com/36d024b5567eb85c40352def9d11a5708fda4d133a8c34ab6d80600b6bf6693a-image.png),![image.png](https://pic.leetcode-cn.com/818badb1f04235bc79a3b0304ad1046a671214465b768cc38208854197cb8075-image.png),![image.png](https://pic.leetcode-cn.com/06d50bc86e378c5446f38710bae9e7dc77c190733b0d90b5508b32c84fa07925-image.png),![image.png](https://pic.leetcode-cn.com/f18bb48593bd739ebec40ac42c810708b57c1171a20af4840f59bce5703870c6-image.png),![image.png](https://pic.leetcode-cn.com/f3e21ba3689b57b2ed792e3150d11653b79c7924c30c2ae1e037e6230c78c8f8-image.png),![image.png](https://pic.leetcode-cn.com/65a0491e906159b05977f0dc432ec1c1ba63142e601bf181af115ac72ffddcd0-image.png),![image.png](https://pic.leetcode-cn.com/ff364ba0a9819061f7ff8eaa2f103ad2cff6bd7d5fe456ac2e1f8f645ff4742f-image.png),![image.png](https://pic.leetcode-cn.com/9af85b79850a6079cbbe16e34825c9a021518b85d29b4ad01fa437605970f4db-image.png),![image.png](https://pic.leetcode-cn.com/83f3694a5e02512937213ffb75df0c168989829e556d006b20d062687e54d951-image.png),![image.png](https://pic.leetcode-cn.com/efe4cf080595524ed04f0d00f1370a110059933eb01ee7fff266bccc3c4914c8-image.png),![image.png](https://pic.leetcode-cn.com/f1bd44c162bfb05636cbb86a462144e89d2c4308ccd6a76f8ab87424b04b33d9-image.png),![image.png](https://pic.leetcode-cn.com/67e0d50e022674cf0bae562139caffa09f384fb62fd36a234da5136ce6e2e9ed-image.png),![image.png](https://pic.leetcode-cn.com/f43af3ba232591fdbfc7513e2cc5ae3e6e7d5006fd76a4204107f1c35a6d2815-image.png),![image.png](https://pic.leetcode-cn.com/5c920ff0537fda4a7e30d73d8ac5e875f7786e6591ef23377b9814ae6ec553a5-image.png),![image.png](https://pic.leetcode-cn.com/eeede8911e6ff95daac2d7926aead38c423b70db0cd2312cfb411128477ffaf7-image.png),![image.png](https://pic.leetcode-cn.com/784cdb2462569bb0bb92f060207a254dc930f5f12884062ee63a673534a3f898-image.png),![image.png](https://pic.leetcode-cn.com/1aaf971ab15827a45c3074cf8e57d5b3af36cbe3e9e7a544e1e3f948d1f5ed80-image.png),![image.png](https://pic.leetcode-cn.com/5e30953a318725f70d7be14f0a2f6e6caedce70eb93e71d517bf5d3fb5403b75-image.png),![image.png](https://pic.leetcode-cn.com/8e45968e24d9b46c1856576217ec1670df6a4371269c457dd513ffcd50b0e924-image.png),![image.png](https://pic.leetcode-cn.com/a790ef0f4f9d0a32380c2332f3e620ac8b93382ad451878e1c9733ae01c5cbfe-image.png),![image.png](https://pic.leetcode-cn.com/c248a9c93fc84e57a5d078b8b5298c081ffbb5185c5968b961b72fabca4bba7f-image.png),![image.png](https://pic.leetcode-cn.com/766304f4e3ac858014875cfbdc26e67326b2ef44067362301264801a5785b359-image.png),![image.png](https://pic.leetcode-cn.com/7e4ee4d58c4b93dba6ec2d1a26e68f150fa5f7b40b5d4a9aabdf7077ca3c3abb-image.png),![image.png](https://pic.leetcode-cn.com/0eedda543e2c05951343c8aec7dcc5e2813fc345d73cf530ba74796cc7d6f42c-image.png),![image.png](https://pic.leetcode-cn.com/e5bf1d8294cc889f23ad6ee473943262ab53cd665052a16bed5fe8fd73e31f90-image.png),![image.png](https://pic.leetcode-cn.com/10f0c5e0d8b05cb84da323e77aa7edcf34fef8a04caf721050aaaa408c41efd7-image.png),![image.png](https://pic.leetcode-cn.com/3f10db7110228564fea68bd354545749fd534c53a70d044e2696d2809ea933c1-image.png)>

```Java []
public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m*n)$。我们需要求出大小为 $m * n$ 的 $dp$ 数组，$m$ 和 $n$ 分别是两个字符串的长度。

* 空间复杂度：$O(m*n)$。使用了大小为 $m * n$ 的 $dp$ 数组。

#### 方法 5： 一维动态规划 [Accepted]

**算法**

我们观察到最后一种方法中，为了求出当前 $dp$ 元素的值，我们只需要前一行 $dp$ 数组的值，所以我们可以使用一个一维 $dp$ 数组。

现在， $dp[i]$ 代表着 $s1$ 到第 $i$ 个字符为止， $s2$ 到最近位置为止的最少删除次数。我们使用一个额外的与 $dp$ 数组同样大小的 $temp$ 数组来求解当前行的解。现在我们在 $temp$ 数组中更新当前行的解，并用 $dp$ 数组保存前一行的解。当 $temp$ 数组求解完后，我们将它拷贝到 $dp$ 数组中，这样 $dp$ 数组就保存了当前行的解。

```Java []
public class Solution {
    public int minDistance(String s1, String s2) {
        int[] dp = new int[s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            int[] temp=new int[s2.length()+1];
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    temp[j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + Math.min(dp[j], temp[j - 1]);
            }
            dp=temp;
        }
        return dp[s2.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m*n)$。我们需要求解大小为 $n$ 的 $dp$ 数组 $m$ 次。$m$ 和 $n$ 分别是字符串 $s1$ 和 $s2$ 的长度。

* 空间复杂度：$O(n)$。使用了大小为 $n$ 的 $dp$ 数组。
