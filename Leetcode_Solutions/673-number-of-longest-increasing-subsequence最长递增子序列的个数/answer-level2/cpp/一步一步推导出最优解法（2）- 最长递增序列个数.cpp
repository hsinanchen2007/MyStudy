### 一、准备工作
**建议先做题目 [300-最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)**
**下面的题解部分参考我之前写的 [300.最长上升子序列题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/yi-bu-yi-bu-tui-dao-chu-guan-fang-zui-you-jie-fa-x/)，和 [英文 leetcode 讨论区的解法](https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107295/9ms-C%2B%2B-Explanation%3A-DP-%2B-Binary-search-%2B-prefix-sums-O(NlogN)-time-O(N)-space)**
**提示：如果 [英文 leetcode 讨论区的解法](https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107295/9ms-C%2B%2B-Explanation%3A-DP-%2B-Binary-search-%2B-prefix-sums-O(NlogN)-time-O(N)-space) 打开后跳转国区，请关闭页面，重新点击链接。**

### 二、解法推导
回忆一下题目 300-最长上升子序列 的解法：
- 首先，维护 **所有的** 上升子序列，然后找出 最长的长度，即为答案。
- 然后，基于贪心思想，对于长度为 $l$ 的上升子序列，仅仅保留其 **最小尾数**，当再添加新的数时，只需大于 最小尾数，即可形成 长度为 $l + 1$ 的上升子序列。

本题与 300 题相比，不仅要求最长上升序列的 **长度** (这是显然的，长度都不知道怎么求个数呢?)，还要求 **个数**。
那么，**本题是否有类似 300 题的，复杂度为 $O(nlog(n))$ 的解法呢**？
答案是有。让我们来顺着下面动图的思路，来推导 $O(nlog(n))$ 解法。


#### 下面以示例 [10,2,5,3,7,101,4,6,5] 开始。

<![image.png](https://pic.leetcode-cn.com/e7da38f4dbb80ea82a5bdef8d45e33c288ffb1b36dc70bfc4e8c21ce594e3e43-image.png),![image.png](https://pic.leetcode-cn.com/76d61b6481c2de38e5fcd4df6bef2c472f20bc64a5af8e5236e4f19233f14da6-image.png),![image.png](https://pic.leetcode-cn.com/f05b59eddd5b410ce827e37d2e96b4dac686d6e20469153b81ae7f2926b4ec72-image.png),![image.png](https://pic.leetcode-cn.com/918e0767ee8f8c961e12eb675572c485b9bfe02c5689e6415c0269f65d9fb5fc-image.png),![image.png](https://pic.leetcode-cn.com/106ad4e3319a93772ac21558e0735623c28d244533832f1b9f1b08a7a325cfb0-image.png),![image.png](https://pic.leetcode-cn.com/1c2842861107d7475566fdfc2a0b253c904a35b45a425e5d089172328dce7ea6-image.png),![image.png](https://pic.leetcode-cn.com/b89031679f45ddabd5dedafbb03683b1e877452ee28aeb5f68de5a454233c72e-image.png),![image.png](https://pic.leetcode-cn.com/8ba39b619110c30c3c7e7613c87b8e62695c5d0dd38e3e18cc2068ba644e0f1b-image.png),![image.png](https://pic.leetcode-cn.com/2011d0498d3477f5d0b38ef02d2ec5ed62583f26f77d994b1d9343384fd128cd-image.png),![image.png](https://pic.leetcode-cn.com/bb5031c3b9c542b5198bbd1e8dd9ee4d396da9c0ccc676d54e18f171ae59d7b0-image.png),![image.png](https://pic.leetcode-cn.com/cdeb1c5a0b5ff8ce3c0a08250fcfc0552807e2feaf7c9f6822cb2cc88e692ba2-image.png),![image.png](https://pic.leetcode-cn.com/afeb7d0a0586ff6e8aa57c8adabd16280a49f327e5174e75d9bbffa1fe3aebb9-image.png),![image.png](https://pic.leetcode-cn.com/2075a685049d5b897244580bd5cadf60a5c8c34651b9173dfd6688f023dbcba3-image.png),![image.png](https://pic.leetcode-cn.com/4920d19ec984add6d38f0c36a93fcb345c8041d374ac25487779cdd5c0734297-image.png),![image.png](https://pic.leetcode-cn.com/3647f917f02431a7eb4870eaf3ed495bde888e43697a6175a9bd40fb9d9f8e5f-image.png),![image.png](https://pic.leetcode-cn.com/7843bcbf2d9bd1258982a495f358f2d1986dd5adfc60c0da44288a0b633051f2-image.png),![image.png](https://pic.leetcode-cn.com/b27f9d2cdd7d23715becc207de2ea25e3800f3e376010dba4a2efa4da45ea42e-image.png),![image.png](https://pic.leetcode-cn.com/2439892659fbcfb94ada4abef539c76d3a984d2df3f8c0b8f922b3c4c620c43f-image.png),![image.png](https://pic.leetcode-cn.com/243d5b1348f769c8434efb9667a15db64b0c250d529f4bd91baba46f50169776-image.png),![image.png](https://pic.leetcode-cn.com/188f2a3ec1dc561cd0a46c182ddd3c63d38b1c0c7b05c74651738a243f435132-image.png),![image.png](https://pic.leetcode-cn.com/e84f8b46548b983220dda7251c5877d68ece7d338a253e60033aaae2b13c2be9-image.png),![image.png](https://pic.leetcode-cn.com/0ff0b79e028e905ea21fae8416a2af60ac49f17faa2e7a8540fc70f98d700fe6-image.png),![image.png](https://pic.leetcode-cn.com/95f7360ee77f0419cd9a8271e931e44f2d459e645f52528b09a93bfbd8665368-image.png),![image.png](https://pic.leetcode-cn.com/f325a33b5a471ff7fb2d1f19dcdbe246b7b9cb4ba85751a97572daffaa3878c5-image.png),![image.png](https://pic.leetcode-cn.com/21d3c71dd9fb499fc9ba4363e52956c10d1d91b8c341d6635e128b51970841ce-image.png),![image.png](https://pic.leetcode-cn.com/97b96a384a3282834e30605a4e56302b8f78f61c77b6d6a02f6945fdccb80f2f-image.png),![image.png](https://pic.leetcode-cn.com/b49675d0ec7256288a950df71919c8e3168cea50f1b833274001967af771306c-image.png),![image.png](https://pic.leetcode-cn.com/7566efa55f3fb63ea85601d4bd3d39c61b3f97247b7b618add0b47598364aea9-image.png),![image.png](https://pic.leetcode-cn.com/c6e5dd1691c21518a6ca91f8f3896cf9927663532129599640a73ed86b3b7138-image.png)>

#### 我们来看上面算法最后形成的图：
![image.png](https://pic.leetcode-cn.com/7ba9cdab9402ede8a3ffb2854234d1ee3b94de72741736766eb623ef5cf6469f-image.png)
- #### 上面每一列，包含了相同上升序列长度下，能够对最长上升子序列做出贡献的 *所有尾数*。
- #### 上面的每个元素的意义：以第二列，第二个元素 3,2 为例，代表了在长度为 2 的递增子序列中，尾数 ≥ 3 的上升子序列的个数 总和 为 2（2->5 和 2->3）。
- #### 规律一（也是 300-最长上升子序列的规律）：对于每一行，每一列的末尾数字是递增的（2，3，4，5）。
- #### 规律二：对于每一列，元素大小自上向下递减。
- #### 因此，我们在插入一个新元素时，可以首先寻找“生长点”，（类似300题的思路），二分查找 *每一列的尾数*，找到可以延长的 *最长序列*。
- #### 然后，在找到的列中，二分查找 *可以插入的最大尾数*。则新插入的数字可以在 *可以插入的最大尾数* 和 *比它小的任意数字* 之后插入。将这些序列个数求和即可。
- #### 下面的动图描述了 在之前序列 [10,2,5,3,7,101,4,6,5] 的基础上，再插入 ‘7’ 的算法流程：

<![image.png](https://pic.leetcode-cn.com/119e1142d0e26fd502b150b49ea1b35c2d628fea6f60b1ccd4f3e83ab44be6f5-image.png),![image.png](https://pic.leetcode-cn.com/1b8534b36869608b8d0c77e33727149e5ea0da75a4eadc67deb64e19d1c2e44c-image.png),![image.png](https://pic.leetcode-cn.com/e28f9db734b6d173b741623c1d870f202341a784dd26ed320a6f87eb2727e5cb-image.png),![image.png](https://pic.leetcode-cn.com/209a3f4bf94872c1cf03dc103890f3b0be08e25914ac8cbe9171ffd16f2d514e-image.png),![image.png](https://pic.leetcode-cn.com/40c2e16538dd0de0a157fe46f4fb938d584b0a0e71defe88e25d85c785a9565b-image.png)>


### 三、代码实现
我们定义两个矩阵。其中：
- $elms[i]$ 表示长度为 $i+1$ 的递增序列中，*可能为最长递增序列做出贡献* 的 **所有尾数（降序排列）**。
- $ops[i][j]$ 表示在长度为 $i+1$ 的递增序列中，$尾数 ≥ elms[i][j]$ 的 **所有上升子序列的个数总和**。

二分查找用 STL 库函数 lower_bound 和 upper_bound。

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> elms, ops;

        for(int v : nums) {
            int pos, paths = 1;

            /* 一、二分查找 “生长点”。 */
            if(elms.size() == 0 || v > elms.back().back()) {
                pos = elms.size();
            } else {
                pos = lower_bound(elms.begin(), elms.end(), v, [](vector<int> &a, const int &b){
                    return a.back() < b;
                }) - elms.begin();
            }

            /* 二、二分查找 “可以插入的最大尾数”。*/
            if(pos > 0) {
                int pre = pos - 1;
                int p2 = upper_bound(elms[pre].begin(), elms[pre].end(), v, greater<int>()) - elms[pre].begin();
                paths = ops[pre].back() - (p2? ops[pre][p2-1] : 0);
            }

            /* 三、计算以元素 v 结尾的, 长度为 pos + 1 的上升子序列个数，并累加前缀和。*/
            if(pos == elms.size()) {
                elms.push_back({v}), ops.push_back({paths});
            } else {
                elms[pos].push_back(v);
                ops[pos].push_back(paths + ops[pos].back());
            }
        }

        return ops.size()? ops.back().back() : 0;
    }
};
```

时间复杂度：$O(nlog(n))$。
空间复杂度：$O(n)$。
实际运行时间：$20ms$。

### 四、神奇的树状数组
这部分内容是为想进一步研究该题目，且了解树状数组的读者准备的。有了树状数组，不需要奇技淫巧，直接根据题意写代码即可。

我们注意到，在求 **最长递增子序列的个数** 的过程中，每添加一个元素，我们需要知道：
1. 在该元素之前，比该元素小的元素中，以其为结尾的递增子序列的 **最大长度 $lmax$**；
2. **长度 == 最大长度所对应的序列个数 $cnt$**。

则添加该元素后，以该元素为结尾的递增子序列的最大长度 = $lmax + 1$，最大长度对应的个数 = $cnt$。

这和树状数组有什么关系呢？
我们定义在区间 $[l,r]$ 中的一种“值”，它包含：
1. 区间 $[l,r]$ 的最大值 $max$。
2. 区间 $[l,r]$ 的最大值出现的次数 $cnt$。

现在，考虑两个区间 $[l_1,r_1]$ 和 $[l_2,r_2]$，两个区间没有重叠部分，两个区间的值分别为 $V_1$ 和 $V_2$。如果将两个区间合并，则合并后的区间的值 $V_{12}$ 为多少？
1. 如果 $V_1.max == V_2.max$，
则 $V_{12}.max = V_1.max = V_2.max$，$V_{12}.cnt = V_1.cnt + V_2.cnt$
2. 如果 $V_1.max > V_2.max$，
则 $V_{12}.max = V_1.max$，$V_{12}.cnt = V_1.cnt$
2. 如果 $V_1.max < V_2.max$，
则 $V_{12}.max = V_2.max$，$V_{12}.cnt = V_2.cnt$

基于上述做法，我们定义一个新运算：$V_{12} = V_1 ⊕ V_2$。
该运算有一个**重要性质**：
- 假设互不重叠的三个区间 $[l_1,r_1]$，$[l_2,r_2]$和 $[l_3,r_3]$ 上的值分别为 $V_1,V_2$ 和 $V_3$，
则 $V_{123} = (V_1 ⊕ V_2) ⊕ V_3 = V_1 ⊕ (V_2 ⊕ V_3)$。即 $“⊕”$ 运算满足 **结合律**。

这样，我们就可以用类似 **区间和** 的思路来处理 将互不重叠的 $N$ 个区间的值的合并。

#### 代码：
```cpp
class Solution {
    class Node { 
        public:
        int m, c;
        Node() : m(0), c(0) {}
        Node& operator+=(Node& b) {
            if(b.m > m)
                m = b.m, c = b.c;
            else if(b.m == m)
                c += b.c;
            return *this;
        }
    };
    void add(Node nodes[], int rk, Node &val, int N) {
        for(; rk <= N; rk += (rk & (-rk))) nodes[rk] += val;
    }
    Node query(Node nodes[], int rk) {
        Node res;
        for(; rk; rk -= (rk & (-rk))) res += nodes[rk];
        return res;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        /* 离散化, 并用树状数组求解 */
        vector<int> numsort(nums.begin(), nums.end());
        sort(numsort.begin(), numsort.end());
        Node nodes[nums.size() + 1] = {Node()}, res = Node();

        for(int i : nums) {
            /* 离散化, 求出当前数字的 排名 - 1 */
            int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();

            /* 求出当前尾数的 最长序列长度 和 个数 */
            Node cur = query(nodes, rk);
            cur.m++, cur.c = max(cur.c, 1); 

            /* 更新全局 最长序列长度 和 个数 */
            res += cur;

            /* 更新树状数组 */
            add(nodes, rk + 1, cur, nums.size());
        }

        return res.c;
    }
};
```
时间复杂度：$O(nlog(n))$。
空间复杂度：$O(n)$。
实际运行实际：$8ms$。



