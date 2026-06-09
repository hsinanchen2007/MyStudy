#### 方法一：暴力法 【超时】

**直觉**

遍历所有的子序列，检查它们是否为等差数列。

**算法**

使用深度优先算法获得所有子序列，根据定义检查是否为等差数列。


```C++ [solution 1]
#define LL long long
class Solution {
public:
    int n;
    int ans;
    void dfs(int dep, vector<int>& A, vector<LL> cur) {
        if (dep == n) {
            if (cur.size() < 3) {
                return;
            }
            for (int i = 1; i < cur.size(); i++) {
                if (cur[i] - cur[i - 1] != cur[1] - cur[0]) {
                    return;
                }
            }
            ans ++;
            return;
        }
        dfs(dep + 1, A, cur);
        cur.push_back(A[dep]);
        dfs(dep + 1, A, cur);
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        n = A.size();
        ans = 0;
        vector<LL> cur;
        dfs(0, A, cur);
        return (int)ans;
    }
};

```

```Java [solution 1]

class Solution {
    private int n;
    private int ans;
    private void dfs(int dep, int[] A, List<Long> cur) {
        if (dep == n) {
            if (cur.size() < 3) {
                return;
            }
            long diff = cur.get(1) - cur.get(0);
            for (int i = 1; i < cur.size(); i++) {                
                if (cur.get(i) - cur.get(i - 1) != diff) {
                    return;
                }
            }
            ans ++;
            return;
        }
        dfs(dep + 1, A, cur);
        cur.add((long)A[dep]);
        dfs(dep + 1, A, cur);
        cur.remove((long)A[dep]);
    }
    public int numberOfArithmeticSlices(int[] A) {
        n = A.length;
        ans = 0;
        List<Long> cur = new ArrayList<Long>();
        dfs(0, A, cur);
        return (int)ans;        
    }
}
```


**复杂度分析**

* 时间复杂度：$O(2^n)$。数组中的每个元素都可能在或不在子序列中，故一共有 $O(2^n)$。

* 空间复杂度：$O(n)$。只需要存储数组的空间。
---
#### 方法二：动态规划【通过】

**直觉**

要决定一个等差数列，至少需要两个参数：序列的首（尾）项和公差。

**算法**

从这一点出发，我们可以简单地设计出状态：

> `f[i][d]` ，代表以 `A[i]` 结束且公差为 `d` 的等差数列个数。

让我们来试着列出状态转移方程。假设我们想在现有的等差数列们的基础上添加一个新元素 `A[i]` 来得到新的子序列。只有当现有的等差数列最后一项加上公差等于 `A[i]` 时，才能够将该元素添加到等差数列后。

于是，我们可以写出 关于`A[i]` 的状态转移方程:

> 对于所有 `j < i`，f[i][A[i] - A[j]] += f[j][A[i] - A[j]]。

这表示了添加新项得到新的等差数列的过程。

但问题来了。初始时所有的 `f[i][d]` 都置为 `0`，如果一开始根本就没有子序列，怎么生成新的子序列呢？

在等差数列的原定义中，子序列的长度至少为 `3`。这使得只有两个下标 `i` 和 `j` 时，很难生成新的序列。那么，能不能考虑将长度为 `2` 的序列纳入考虑呢？

我们定义`弱等差数列`：

> **弱等差数列** 是至少有两个元素的子序列，任意两个连续元素的差相等。

弱等差数列有两个十分有用的性质？

- 对于任何 `i, j (i != j)`，`A[i]` 和 `A[j]` 总能组成一个弱等差数列。

- 若在弱等差数列后添加一个元素且保持等差，则一定得到一个等差数列。

第二个性质很显而易见，因为弱等差数列和等差数列的唯一区别就是它们的长度。

于是，我们可以修改状态的定义：

> `f[i][d]`代表以 `A[i]` 结束且公差为 `d` 的弱等差数列个数。

现在状态转移方程就十分简单：

> 对于所有 `j < i`，`f[i][A[i] - A[j]] += (f[j][A[i] - A[j]] + 1)`。

这里的 `1` 是因为根据性质一，我们可以对 `(i, j)`生成一个新的弱等差数列。

所有弱等差数列的数量即为 `f[i][d]`之和。但如何从中挑选出不`弱`的那些呢？

有两种方法：

- 其一，我们可以对`真弱`等差数列的数量进行直接计数。`真弱`等差数列即为长度为 `2` 的弱等差数列，故其数量为 `(i, j)` 对的格数，即为 $\binom{n}{2} = \frac{n * (n - 1)}{2}。$

- 其二，对于 `f[i][A[i] - A[j]] += (f[j][A[i] - A[j]] + 1)`，`f[j][A[i] - A[j]]` 是现有的弱等差数列个数，而 `1` 是根据 `A[i]` 和 `A[j]` 新建的子序列。根据性质二，新增加的序列必为等差数列。故  `f[j][A[i] - A[j]]` 为新生成的等差数列的个数。

可以用下面的示例来演示整个过程：

> `[1, 1, 2, 3, 4, 5]`

计算上述序列的答案。

- 对于第一个元素 `1`，前面没有元素，答案保持 `0`。

- 对于第二个元素 `1`，该元素与上一个 `1` 可以组成公差 `0` 的弱等差数列: `[1, 1]`。

- 对于第三个元素 `2`，它无法与唯一的弱等差数列 `[1, 1]` 合并，因此答案仍为 `0`。与上一个元素类似，它也可以形成新的弱等差数列 `[1, 2]` 和 `[1, 2]`。

- 对于第四个元素 `3`，若我们将它添加到最后元素为 `2` 的序列中，则其公差必为 `3 - 2 = 1`。`[1, 2]` 和 `[1, 2]` 符合要求，故将 `3` 添加到这些序列后，答案增加 `2`。Similar to above, 与上一个元素类似，它也可以形成新的弱等差数列 `[1, 3]，[1, 3]` 和 `[2, 3]`。

- 其他元素以此类推，可参见下图。红色括号表示长度为 `2` 的弱等差数列，黑色括号表示等差数列。答案为黑色括号的数量。

![image.png](https://pic.leetcode-cn.com/8676ec75b73cbc7a211fea8f7cf57d01a9704f3318ad33f9b5999775ab3c7462-image.png){:width=600}
{:align=center}



```C++ [solution 1]

#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        LL ans = 0;
        vector<map<LL, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                LL delta = (LL)A[i] - (LL)A[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) {
                    sum = cnt[j][delta];
                }
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};
```

```Java [solution 1]

class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        long ans = 0;
        Map<Integer, Integer>[] cnt = new Map[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = new HashMap<>(i);
            for (int j = 0; j < i; j++) {
                long delta = (long)A[i] - (long)A[j];
                if (delta < Integer.MIN_VALUE || delta > Integer.MAX_VALUE) {
                    continue;
                }
                int diff = (int)delta;
                int sum = cnt[j].getOrDefault(diff, 0);
                int origin = cnt[i].getOrDefault(diff, 0);
                cnt[i].put(diff, origin + sum + 1);
                ans += sum;
            }
        }
        return (int)ans;        
    }
}
```


**复杂度分析**

* 时间复杂度：$O(n ^ 2)$。可以使用两重循环来计算全部状态。

* 空间复杂度 : $O(n ^ 2)$。对每个 `i`，最多需要存储 `n` 个公差。