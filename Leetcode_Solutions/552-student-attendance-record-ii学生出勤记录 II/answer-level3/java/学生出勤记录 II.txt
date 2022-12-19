#### 方法 1：暴力[Time Limit Exceeded]

在暴力方法中，我们生成所有由 "A", "P" 和 "L" 组成的字符串并根据题目的规则检查每个字符串是否是可奖励的。生成每个可能字符串的方法是使用递归函数 `gen(string,n)` 。在递归函数的每一层，我们分别在输入字符串的最后面加上字母 "A", "P" 和 "L"，然后将剩余长度减少 1 ，再分别对 3 个字符串调用同一个函数。

<![image.png](https://pic.leetcode-cn.com/470b8a1fb43bc854224fe58076925caa442a8b43453184a295f4434ca6cad7ce-image.png),![image.png](https://pic.leetcode-cn.com/f11c47386df72e17b3e99d4039dbb3e3ef124406b0e5626c47623f3fc58655ee-image.png),![image.png](https://pic.leetcode-cn.com/6f3a1acb2f983f52dad9449e00def5838e2953cc8f252ddd66bdfc9bb8bfb5da-image.png),![image.png](https://pic.leetcode-cn.com/9f4e9587be95792c973cc391639d44916689dbd9d8707b0a3f8497da80f960e1-image.png),![image.png](https://pic.leetcode-cn.com/d22436d07562959f4e130f49a6a3fb5632a287d6923d0525f9b81481c1ae513d-image.png),![image.png](https://pic.leetcode-cn.com/a8296cac53fff3d7dc639573d8117acd9a743a5e91c832b900710beb6a1e3819-image.png),![image.png](https://pic.leetcode-cn.com/7f6742b081267a8927e74c186dfebf1b0f94099014574f748123d99f2006909c-image.png),![image.png](https://pic.leetcode-cn.com/a004755998bd20b9f3311315b9e829551529b2e831b3276c66b814a5b07bd0eb-image.png),![image.png](https://pic.leetcode-cn.com/007450b10a8f9838dd8254d86218135ab3e37fe86dbc62edba1655c16a81ca53-image.png),![image.png](https://pic.leetcode-cn.com/c881c67219d42721feb1adc11e4647e02f0fc0f59c993e82298ab38032066be4-image.png),![image.png](https://pic.leetcode-cn.com/dff8782800151c4eddb33fc3a186fd097b4d173641334fa404e8d92975c40c41-image.png),![image.png](https://pic.leetcode-cn.com/2d55889e7d89f2595bc9006270321c04f00dd9f82e3e1922d7f2d79014655b2d-image.png),![image.png](https://pic.leetcode-cn.com/808a8fe266f0734e9d04e13c967915e645d7a4fceb6d89da160b42bd9cbbbd7e-image.png),![image.png](https://pic.leetcode-cn.com/c412fd3fc0195049b80d1fd27d83e4c1e9d0689ab0ee81b20ace72db1b431ecc-image.png),![image.png](https://pic.leetcode-cn.com/1f93e400842c281f48a95af4b009bafa2594a702527d8c4c76e3c03e35b5b8fe-image.png),![image.png](https://pic.leetcode-cn.com/3dc6575a9a0083d53b6f14bdb810c3a5382f5741f6a1a6d5dfdaf1cee798ea46-image.png)>


```Java []
public class Solution {
    int count,M=1000000007;
    public int checkRecord(int n) {
        count = 0;
        gen("", n);
        return count;
    }
    public void gen(String s, int n) {
        if (n == 0 && checkRecord(s))
            count=(count+1)%M;
        else if (n > 0) {
            gen(s + "A", n - 1);
            gen(s + "P", n - 1);
            gen(s + "L", n - 1);
        }
    }
    public boolean checkRecord(String s) {
        int count = 0;
        for (int i = 0; i < s.length() && count < 2; i++)
            if (s.charAt(i) == 'A')
                count++;
        return s.length() > 0 && count < 2 && s.indexOf("LLL") < 0;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(3^n)$。需要搜索所有的 $3^n$ 种组合。
* 空间复杂度： $O(n^n)$。递归树的深度最多为 $n$ 层，每个节点包含长度为 $O(n)$ 的字符串。

#### 方法 2：使用递归公式 [Time Limit Exceeded]

**算法**

如果我们可以想出它的递归关系，这个问题将变得十分容易。

首先，假设此问题只要考虑字符 $L$ 和 $P$，也就是说字符串只包含字母 $L$ 和 $P$。$A$ 产生的影响稍后我们再考虑。

为了得到这样的关系，我们假设 $f[n]$ 表示长度为 $n$ 的可奖励字符串的数目（只包含字母 $L$ 和 $P$)。然后，我们可以利用小于 $n$ 的字符串数目，算出 $f[n]$。下图说明了计算的过程：

![image.png](https://pic.leetcode-cn.com/4da23842398602783e4b4e60fafb800aa8e33fa17814083493882d19270e6e28-image.png){:width=500px}

上图解释了如何将长度为 $n$ 的可奖励字符串拆成结尾是 $L$ 或者 $P$ 的长度为 $n-1$ 的 2 个字符串。如果长度为 $n-1$ 的字符串是可奖励的，那么将 $P$ 接在这个字符串后面，得到长度为 $n$ 的字符串，一定也是可奖励的。因此，每一个长度为 $n-1$ 的字符串后面接上 $P$ 都可以对应一个长度为 $n$ 的字符串，这使得 $f[n-1]$ 对 $f[n]$ 可以产生贡献。

对于以 $L$ 结尾的字符串，是否可奖励取决于对应的长度为 $n-3$ 的字符串。所以我们需要考虑所有长度为 $n-3$ 的可奖励字符串。在 4 种可能的组合中，第四种也就是以 $LL$ 开始的会导致一个不可奖励字符串。由于我们在考虑长度为 $n-3$ 的可奖励字符串，为了避免在 $n-1$ 的时候已经是不可奖励的，如果倒数第三和倒数第二是 $LL$ 结尾的，那么长度为 $n-4$ 的字符串必须以 $P$ 结尾。

所以，回到最终的字符串，除了接在长度为 $n-4$ 的可奖励字符串后面的 $PLL$ 的可奖励字符串，其他所有长度为 $n-1$ 的可奖励字符串都可以对长度为 $n$ 的可奖励字符串做出贡献。所以 $f[n-1] - f[n-4]$ 会对 $f[n]$ 产生贡献。

所以，递归表达式为：

$$f[n] = 2f[n-1] - f[n-4]$$

我们将所有的 $f[i]$ 保存在一个数组里，为了计算 $f[i]$，我们使用一个递归函数 `func(n)` 并利用上面的递归关系求解。

现在，我们需要考虑加入字符 $A$ 造成的影响。我们知道最多可以将 1 个 $A$ 放入一个可奖励字符串中，所以我们考虑如下两种情况：

1. 没有 $A$: 那么可奖励字符串的数目就是 $f[n]$。
2. 有一个 $A$: 这个 $A$ 可能出现在 $n$ 个位置中的任何一个位置。如果 $A$ 出现在字符串的位置 $i$，形如 "<(i-1) 个字符>, A, <(n-i) 个字符>"，可奖励字符串的总数为：$\sum_{i=1}^{n} (f[i-1] * f[n-i])$。

```Java []
public class Solution {
    int M=1000000007;
    public int checkRecord(int n) {
        int[] f =new int[n+1];
        f[0]=1;
        for(int i=1;i<=n;i++)
            f[i]=func(i);
        int sum=func(n);
        for(int i=1;i<=n;i++){
            sum+=(f[i-1]*f[n-i])%M;
        }
        return sum%M;
    }
   public int func(int n)
   {    
       if(n==0)
            return 1;
        if(n==1)
            return 2;
        if(n==2)
            return 4;
        if(n==3)
            return 7;
        return (2*func(n-1) - func(n-4))%M;
   }
}
```

**复杂度分析**

* 时间复杂度： $O(2^n)$。函数 $func$ 最多需要花费 $2^n$ 的时间。

* 空间复杂度： $O(n)$。$f$ 数组的大小为 $n$。

#### 方法 3：使用动态规划 [Accepted]

**算法**

在上一种方法中，我们每次计算 $f[i]$ 都需要使用递归函数，直到走到字符串最开始的位置。如果我们使用记录下来的 $f[j]$ 去更新 $f[i]$，我们可以节省非常大量的计算时间，递推公式为 $f[i] = 2f[i-1] + f[i-4]$。

```Java []
public class Solution {
    long M = 1000000007;
    public int checkRecord(int n) {
        long[] f = new long[n <= 5 ? 6 : n + 1];
        f[0] = 1;
        f[1] = 2;
        f[2] = 4;
        f[3] = 7;
        for (int i = 4; i <= n; i++)
            f[i] = ((2 * f[i - 1]) % M + (M - f[i - 4])) % M;
        long sum = f[n];
        for (int i = 1; i <= n; i++) {
            sum += (f[i - 1] * f[n - i]) % M;
        }
        return (int)(sum % M);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$。一遍循环计算 $f$ 数组，另一遍循环计算 $sum$。

* 空间复杂度： $O(n)$。 $f$ 数组使用了大小为 $n$ 的空间。

#### 方法 4：常数空间的动态规划 [Accepted]

**算法**

我们可以发现 $P$ 的数目和位置在字符串中是无关紧要的。我们利用这个规律，可以发现一些转移的状态模式，如下图所示：

![image.png](https://pic.leetcode-cn.com/7379a9ce47ab22e041019b8021b162044522def1f0bf40c4f98aa31077be54b0-image.png){:width=400}

这个状态转移图仅依据 $A$ 是否包含在字符串中以及 $L$ 在目前字符串结尾出现的次数来划分状态。当我们给字符串结尾添加新的字符时会发生状态转移。

基于上面的状态图，我们记录可奖励状态之间不同的转移。我们从长度为 $0$ 的字符串开始，并不断添加新的字符到字符串的末尾，直到字符串的长度为 $n$。最后，我们把所有可能的可奖励状态数加起来得到我们想要的答案。

我们可以用变量来记录每一种状态的方案数， $axly$ 表示长度为 $i$ 包含 $x$ 个 $a$ 并以 $y$ 个$l$ 结尾的字符串数目。

下面的代码由 [@stefanpochmann](http://leetcode.com/stefanpochmann) 提供。

```Java []
public class Solution {
    long M = 1000000007;
    public int checkRecord(int n) {
        long a0l0 = 1;
        long a0l1 = 0, a0l2 = 0, a1l0 = 0, a1l1 = 0, a1l2 = 0;
        for (int i = 0; i < n; i++) {
            long new_a0l0 = (a0l0 + a0l1 + a0l2) % M;
            long new_a0l1 = a0l0;
            long new_a0l2 = a0l1;
            long new_a1l0 = (a0l0 + a0l1 + a0l2 + a1l0 + a1l1 + a1l2) % M;
            long new_a1l1 = a1l0;
            long new_a1l2 = a1l1;
            a0l0 = new_a0l0;
            a0l1 = new_a0l1;
            a0l2 = new_a0l2;
            a1l0 = new_a1l0;
            a1l1 = new_a1l1;
            a1l2 = new_a1l2;
        }
        return (int)((a0l0 + a0l1 + a0l2 + a1l0 + a1l1 + a1l2) % M);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$。只需要一遍循环来更新答案。

* 空间复杂度： $O(1)$。只需要常数的额外空间。

#### 方法 5：使用更少的变量 [Accepted]

**算法**

在上面提到的最后一种方法中，我们使用了 6 个额外的变量来记录当前状态的改变。我们可以用更少的变量来获得相同的结果。

```Java []
public class Solution {
    long M = 1000000007;
    public int checkRecord(int n) {
        long a0l0 = 1, a0l1 = 0, a0l2 = 0, a1l0 = 0, a1l1 = 0, a1l2 = 0;
        for (int i = 0; i <= n; i++) {
            long a0l0_ = (a0l0 + a0l1 + a0l2) % M;
            a0l2 = a0l1;
            a0l1 = a0l0;
            a0l0 = a0l0_;
            long a1l0_ = (a0l0 + a1l0 + a1l1 + a1l2) % M;
            a1l2 = a1l1;
            a1l1 = a1l0;
            a1l0 = a1l0_;
        }
        return (int) a1l0;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$。只循环了一遍。

* 空间复杂度： $O(1)$。只是用了常数的额外空间。
