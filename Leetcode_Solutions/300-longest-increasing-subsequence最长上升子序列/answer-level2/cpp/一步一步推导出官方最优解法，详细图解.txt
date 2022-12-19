#### 本题旨在解释官方题解的 解法四 及类似动态规划解法。本题解一步步推导出最优的动态规划解法，并讨论动态规划 dp数组 的意义。
从一个例子开始。我们先考虑下面的数组的最长上升子序列：
#### [10, 9, 2, 5, 3, 7, 101, 4, 1]
首先，我们来一次最暴力的算法，即维护当前所有的递增子序列（包含一定的剪枝）。然后一个个添加元素。最后，找出最长的子序列即可。详见下面的 PPT：

<![image.png](https://pic.leetcode-cn.com/9f534c43e4703ebde2debf9631ba3727de003f8f563348a121b5cd61a6da5446-image.png),![image.png](https://pic.leetcode-cn.com/d1a326260b5a4d85bb1ae05957262ab96d5239f375e3ef520ce0ff5b8b5d3bab-image.png),![image.png](https://pic.leetcode-cn.com/be4437311cc6b1b249ebc37b476470b803b86582254e5e2f9fe65e9035073da5-image.png),![image.png](https://pic.leetcode-cn.com/94b5dbb34fbe3ef1ba8bb01a2ab0db02033bdd330166b87a8302a05abc947524-image.png),![image.png](https://pic.leetcode-cn.com/e40d35f14a5f21c442af98e0a4f1a3515f3a544876bf2ba3451af74a9da4cd97-image.png),![image.png](https://pic.leetcode-cn.com/2022895e04e887a9aebb291a695b3513c45952aeaf441a8d7a7705b077ea5c1b-image.png),![image.png](https://pic.leetcode-cn.com/0c06895eeddecaf16327ce09954e62d70d0115366c6e09f969cae8c1a88cc34e-image.png),![image.png](https://pic.leetcode-cn.com/3fa75360c11567b754400cc1f4960139821a26d40357467b47480ea80cc007bf-image.png),![image.png](https://pic.leetcode-cn.com/d1a79649ad13211fdcd2ccf30ee31fdf929a47129bc3b4c9638f4be166954a07-image.png),![image.png](https://pic.leetcode-cn.com/32b6692b974aeb0d732b24bd75cf9995b3d56c3a8b12c40902aac5f86eae46b1-image.png),![image.png](https://pic.leetcode-cn.com/b28141232c1a9eac58311547e07dffa8275e4dea8071b20016f38e7ed8887b66-image.png),![image.png](https://pic.leetcode-cn.com/12b5c51b9d6852e3885c3b624775266cd99bc5312d999cc1215efb5d086bb8c4-image.png),![image.png](https://pic.leetcode-cn.com/9c5174e6871c6a64263a4e7dcbdc444a6484e1b7fbc66cda1f0489e10f8c4785-image.png),![image.png](https://pic.leetcode-cn.com/75f3a320fe595919c6f0c7e2087f3122413781b5fbd60570f61505dfeaeb4f5d-image.png)>

#### 优化的方法：
#### 我们来看暴力法最后形成的图：
![image.png](https://pic.leetcode-cn.com/21139d6f2531808007aa8fd8f71bc54b9d4a8d451500e7e6490d650f1cc2d718-image.png)
- 假如我们要在里面新增一个元素 X，希望找出插入 X 之后的最长子序列。
- 结论一指出，我们需要在当前允许插入的 **最长** 子序列之后添加元素。
- 于是，我们可以依次检查序列长度 = 1，2，3，4 的递增子序列，然后找出最长的，尾数 < X 的序列。
- ##### 我们发现，对每一个序列长度 l，只需要检查图中的每一列的最小值（绿色的元素）是否 < X 即可。如果绿色的元素 < X，表明长度为 l 的递增子序列后可添加元素 X。
- #### 因此，我们有 **结论二**：我们只需要维护 长度为 l 的递增子序列的 最小结尾数字。
- #### 这样，我们得到了一个数组[1, 3, 4, 101]。这就是官方题解中的动态规划 dp 数组。
- #### 值得注意的是，[1, 3, 4, 101] 不是任何一个实际存在于数组的递增子序列！！。
- #### 实际上，[1, 3, 4, 101] 中的每一个数字都隐含了前述图中的 一条路径，并且 其结尾数字在当前层最小。换句话说，[1, 3, 4, 101] 中每一个数字的实际意义是，**长度为 i(下标) + 1 的递增子序列末尾的最小数字**。
- #### 对于这样的 dp 数组，我们有 结论3：dp数组一定是 **严格递增** 的。因为 dp[i] 为 长度为 i+1 的递增子序列末尾的最小数字，而当 i >= 1时，长度为 i+1 的递增子序列一定是由长度为 i 的递增子序列添加元素而来，如果长度为 i 的递增子序列的 **最小尾数** 为 X，则添加的元素一定 > X。

#### 我们应该如何实现这样的算法呢？
最简单的实现方式，当插入新元素 X 时，我们从 1 逐个枚举现有递增子序列的长度，直到找到最大可添加元素 X 的长度。与此同时，维护每个长度 l 的最小尾数：

比如前述序列 [10, 9, 2, 5, 3, 7, 101, 4, 1]，已构造 dp 数组[1, 3, 4, 101]，要添加 “6”。
- 长度 l = 1 时，长度为 1 的递增子序列末尾的最小数字为 1，6 > 1，可以添加。
- l = 2 时，6 > 3，可以添加。
- l = 3 时，6 > 4，可以添加。
- l = 4 时，6 < 101，不可添加。
- 因此，以 “6” 为结尾的递增子序列最长为 3 + 1 = 4。
- 另外，此时，**长度为 4 的递增子序列的最小尾数变成了 “6”**。因此修改 `“101” -> “6”`。数组变为 [1, 3, 4, 6]。

如果要添加 “102”呢？
- 由于 “102” > “101”，因此 “102” 可以在长度为 4 的子序列后添加，递增子序列的最大长度变成了 5。
- 由于长度为 5 的递增子序列的尾数只有 “102”，故最小尾数也是 “102”，直接在数组后添加 “102” 即可。

##### 详见 PPT，仍以序列 [10, 9, 2, 5, 3, 7, 101, 4, 1] 为例：

<![image.png](https://pic.leetcode-cn.com/e77974112c7ce35f66f8879562caa22091e4040ebe7f48878fdd6c1fc49a12e5-image.png),![image.png](https://pic.leetcode-cn.com/2a61fe7d380bdf008a39a5e5799718387c4fc9b0dc9a101b8ef8aa1a5c55698b-image.png),![image.png](https://pic.leetcode-cn.com/8e12dd8e49192b8f22ff5f8e0fb5f2a74a14dd5078959f4f4c0a57bffacce434-image.png),![image.png](https://pic.leetcode-cn.com/0420e88833a84d24c3694187e622f1c181c1a0e03ccee1b0f94f90b8bb9ae97b-image.png),![image.png](https://pic.leetcode-cn.com/6e7d705c06fdb6515b68daa3f1749d73502c25b8568aff7049fb45b4e479dfb8-image.png),![image.png](https://pic.leetcode-cn.com/597746a11283a4e49cd720f41d664b6ad63a738e9216647d1b23c833c4aad8d3-image.png),![image.png](https://pic.leetcode-cn.com/b46ebc85a1410b4ec730bc2fcbf7f06e697967a9602076a64d66b324409d7225-image.png),![image.png](https://pic.leetcode-cn.com/f752a80aaeb07698fd898d95178c09578865e59b77e176d4e8cd4755ec4be6f7-image.png),![image.png](https://pic.leetcode-cn.com/3dbcf66944338075e0bc91f2a7ff72a12b0671167133c5239e4d7dc09e115e59-image.png),![image.png](https://pic.leetcode-cn.com/1ead40b40100e1e874593288fd159f6914f92590c7d7ab20d6bc794d4dc7d2f8-image.png),![image.png](https://pic.leetcode-cn.com/08f4b6fcbdbd77b7ab324e953b1e5fd07c5ab1a8ff748e404a27e703d024b212-image.png),![image.png](https://pic.leetcode-cn.com/7164df71d7e2268120664f152e4451a08ac84ee68e95a3d14ae81fa15c9317e1-image.png),![image.png](https://pic.leetcode-cn.com/f5e0af2258ac14df237fcfd07adc051c2cd4b1d55e90c81092d86601bb84b4c0-image.png),![image.png](https://pic.leetcode-cn.com/6f8772b69c87eb364e351e35c50916f1f830f2926c47c4d535adf9235c7acd87-image.png),![image.png](https://pic.leetcode-cn.com/37e5be72dadba48b764a0a4bf4f49235046ec66235b029165ef915b7cad88a38-image.png),![image.png](https://pic.leetcode-cn.com/25c340bd7b713f2627a32a1d33d817ad006b6f80558ea240e756cfef3919bd54-image.png),![image.png](https://pic.leetcode-cn.com/2e3aa28727f6537f402f35918a2ad506e503606e60edca62264bfe4aca68462d-image.png),![image.png](https://pic.leetcode-cn.com/fc16a44360cc1c1719260629e3c12a2d091fc46e42351c3163ffb4739dfe1813-image.png),![image.png](https://pic.leetcode-cn.com/7970def47d921652070570e7a583d2a29c799bf7f7f12f5e3d5ee9a5e9b576cc-image.png),![image.png](https://pic.leetcode-cn.com/dc546186a81001ef3385093252e9076bc0b079ce2edfb210c7c6f77317139445-image.png),![image.png](https://pic.leetcode-cn.com/34e5c04aff28e436025287c8eb6a5803932968885c69b0926fec03955fb6bc9a-image.png),![image.png](https://pic.leetcode-cn.com/6e30b83475dde36018f2b417e0d6eac2103c26b487c753a912ef7130795833fc-image.png),![image.png](https://pic.leetcode-cn.com/65a12a708266ef03e2dc6f121da4d3bc2f9188f48f3a8ba907d1e98de6d22755-image.png)>

#### 优化：
- 由于数组是有序的，当要添加数 “x” 时，可以用二分搜索找出数组中小于 x 的最大数字。
- 另外，由于序列严格递增，若 a[i] < x，则 a[i+1] >= x。因此需要将 a[i+1] 修改为 x，代表长度为 i+2 的递增子序列末尾的最小数字。
- 至此，O(nlog(n)) 的算法诞生了！

### 代码
我们维护一个数组 minnums，minnums[i] 代表长度为 i+1 的递增子序列末尾的最小数字。每次添加元素 v 时，二分搜索找到 < v 的最大数字的位置 i 和 >= v 的最小数字的位置 i+1。然后，将 minnums[i+1] 修改为 v。
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> minnums;
        for(int v : nums)
        {
            if(!minnums.size() || v > minnums.back()) 
                minnums.push_back(v);
            else
                *lower_bound(minnums.begin(), minnums.end(), v) = v;
        }
        return minnums.size();
    }
};
```

#### 进阶：
如果要求 [最长递增子序列的个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)，是否可以借用上面的方法呢？
[题解](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yi-bu-yi-bu-tui-dao-chu-zui-you-jie-fa-2-zui-chang/)

#### 番外篇. 树状数组解法
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 用树状数组找到在小于当前数字的数中，递增序列长度的最大值。(类似区间极大值)
        // 树状数组求区间极大值时，只要区间是从 1 开始的，就可以直接用区间和的思路
        vector<int> numsort(nums.begin(), nums.end());
        sort(numsort.begin(), numsort.end());
        int tree[nums.size() + 1] = {0}, res = 0;
        for(int i : nums)
        {
            int before = 0;
            int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();
            for(int t = rk; t > 0; t -= ((t) & (-t))) before = max(before, tree[t]);
            res = max(res, before + 1);
            for(int t = rk + 1; t <= nums.size(); t += ((t) & (-t))) tree[t] = max(tree[t], before + 1);
        }
        return res;
    }
};
```
