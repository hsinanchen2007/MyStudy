### 解题思路
主体思路和官方题解差不多，首先若数组 `B` 与数组 `C` 的平均值相等，则 `B` 的均值 = `C` 的均值 = `A` 的均值。
设`A`有 N 个数， `B` 中有 K 个数, 
则 `B` 的均值 = `(b1 + b2 + ... + bk) / K` = `A` 的均值 = `(a1 + a2 + ... + an) / N`.
因此 `N * (b1 + b2 + ... + bk) = K * sum(A)`.
可得 `(N*b1 - sum(A)) + (N*b2 - sum(A)) + ... + (N*bk - sum(A)) = 0`.
于是对 `A` 进行一些处理, 令 `A[i] = N*A[i] - sum(A)`.
则只要 `A` 中存在真子集 `B`, `B` 的和为 0 即可。

#### 如何找到和为 0 的真子集？
采用枚举的思路，对于 `A` 中的每个数 `A[i]` 都有两种选择：“选取” 或 “不选取”。
完全暴力枚举的复杂度为 O(2^N).
如果采用折半查找，先寻找前半部分的**所有和** S1，再寻找后半部分的所有和 S2，
若存在 `x∈S1, y∈S2`且 `x + y = 0`, 且 x,y 不是由 `A` 的所有元素得到的，则返回 true.

#### 如何找出 A 的前半部分（或后半部分）的所有和？
首先对 `A` 进行从小到大排序。
然后，假设只寻找 `A` 的第一个元素 `A[0]` 的所有和。显然，和只有1个元素 `A[0]`。
假设 `A` 的前 i - 1 个元素的所有和包含 `{s1, s2, ..., sk}`, 
则 `A` 的前 i 个元素的所有和包含 `{s1, s2, ...sk}` 和 `{s1 + A[i], s2 + A[i], ..., sk + A[i]}` 和 `A[i]`.
假如 `{s1, s2, ..., sk}` 有序，则 `s1 + A[i], s2 + A[i], ..., sk + A[i]` 也必定有序,
因此可以采取**归并排序**的方式将 `{s1, s2, ..., sk}` 与 `s1 + A[i], s2 + A[i], ..., sk + A[i]` 归并，
再将 `A[i]` 插入即可。
每次排序的时间复杂度: O(k), k 为每次排序后的元素个数。

#### 如何从前半部分的所有和 S1 和 后半部分的所有和 S2 中找出 x + y = 0?
这里就能发挥 S1 和 S2 都是有序数组的好处了。
可以采用双指针法。初始的 `i = S1[0], j = S2[S2.size() - 1]`.
如果 `S1[i] + S2[j] > 0`, 则 `--j`; 否则 `++i`. 直到找到满足条件的值，或者到达边界为止。
另外，还需考虑 “x,y 不能由 A 的所有元素得到” 的条件。

#### 时间复杂度:
1、对 `A` 进行排序，O(Nlog(N)).
2、找出 `A` 的前半部分（或后半部分）的所有和：
`A` 的前半部分（或后半部分）的所有和（包含重复元素）有 S = 2^(N/2) 个, 
寻找的过程中，采用归并排序。
最后一次排序后有元素有 S 个，
倒数第二次排序后有元素有 (S - 1) / 2 个,
...（以此类推）
因此总共操作数 < S + S/2 + S/4 + ... < 2S = O(S)。
3、找出 x + y = 0:
设 `A` 的前半部分的所有和为 S 个, 
则 `A` 的后半部分的所有和为 S （N为偶数）或 2S 个（N为奇数）。
双指针法，时间复杂度为 O(S)。
综上，总的时间复杂度为 O(S) = O(2^(N/2)).


### 代码
![image.png](https://pic.leetcode-cn.com/6551aa0002f260783c8f358a12295b42e84182a573fef1bb2573b45df8d0f878-image.png)
```cpp
class Solution {
public:
    vector<int> t;
    bool getAll(int l, int r, int sum, int& S, vector<int>& A, vector<int>& res)
    {
        for(int i = l; i < r; ++i) // 归并排序
        {
            if(A[i] == 0) return true;
            int j = 0, j2 = 0, k = 0;
            while(j < S && j2 < S)
            {
                if(res[j] < res[j2] + A[i]) t[k++] = res[j++];
                else if(res[j] == res[j2] + A[i])
                {
                    if(res[j] == sum) return true;
                    t[k++] = res[j++]; ++j2;
                }
                else t[k++] = res[j2++] + A[i];
            }
            while(j < S) t[k++] = res[j++];
            while(j2 < S) t[k++] = res[j2++] + A[i];
            int m = 0, n = 0;
            while(m < k && t[m] < A[i]) res[n++] = t[m++]; 
            if(A[i] != t[m]) res[n++] = A[i];
            else if(A[i] == sum) return true;
            while(m < k) res[n++] = t[m++];
            S = n;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        if(A.size() <= 1) return false;

        int sum = 0, N = A.size();
        for(int x : A) sum += x;
        for(int& x : A) x = N*x - sum; // ∑(N*A[i] - sum) = 0
        sort(A.begin(), A.end());

        int sum1 = accumulate(A.begin(), A.begin() + N/2, 0);
        int sum2 = accumulate(A.begin() + N/2, A.end(), 0);
        vector<int> firsts((1 << (N/2)) - 1);
        vector<int> seconds((1 << (N/2 + N%2)) - 1);
        t = vector<int>(1 << (N/2 + N%2));

        bool found;
        int sz1 = 0, sz2 = 0;
        found = getAll(0, N/2, sum1, sz1, A, firsts);  if(found) return true;
        found = getAll(N/2, N, sum2, sz2, A, seconds); if(found) return true;

        for(int i = 0, j = sz2 - 1; i < sz1 && j >= 0;)
        {
            if(firsts[i] + seconds[j] > 0) --j;
            else if(firsts[i] + seconds[j] < 0) ++i;
            else // == 0
            {
                if(firsts[i] != sum1 || seconds[j] != sum2) return true;
                ++i;
            }
        }
        return false;
    }
};
```

### 其他解法
1、国外网站上的大神解法，首先设数组 B 中有 K 个元素， K <= N/2. 由于 `K*sum(A) == N*sum(B)`,
所以问题转化为对所有的 `K <= N/2`, 如果找到数组 B 的和为 `sum(A)*K/N`, 则返回 true.

这个解法的一个重要的优化在于，如果对于某个 K, `sum(A)*K/N` 不是整数, 则不可能存在和不是整数的数组 B.

这种解法对于随机数组很有效, 但是不能处理每个数字都是 N 的倍数的数组，如
[30,60,90,120,150,180,210,240,270,300,330,360,390,420,450,480,510,540,570,600,630,660,690,720,750,780,810,840,870,930]。

代码：
```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        sort(A.rbegin(), A.rend()); // Optimization
        for (int i = 1; i <= m; ++i) 
            if (totalSum*i%n == 0 && combinationSum(A, 0, i, totalSum*i/n)) return true;
        return false;
    }
    bool combinationSum(vector<int>& nums, int idx, int k, int tar) {
        if (tar > k * nums[idx]) return false; // Optimization, A is sorted from large to small
        if (k == 0) return tar == 0;
        for (int i = idx; i <= nums.size()-k; ++i) 
            if (nums[i] <= tar && combinationSum(nums, i+1, k-1, tar-nums[i])) return true;
        return false;
    }
};
```

2、动态规划解法。其时间复杂度为 `O(N*N*sum) = O(N*N*N*max(A[i])`. 在题目中，由于 A[i] <= 10000, 
N <= 30, 则 `30*30*30*10000` = 270000000。
而由于 N <= 30, 题解中描述的方法的复杂度为 O(2^(N/2)). 而 2^15 = 32768。
显然，由于 N 实在太小，在本题中，采用折半查找的方法最优的。
