### 算法简介
将区间等分。最大子序和要么是左半区间的子序和，要么是右半部分的子序和，要么横跨两端。
因此为了计算横跨两端的子序和，一共需要计算的有：
1. 左半区间包含其右端点的最大子序和`rmax`
2. 右半区间包含其左端点的最大子序和`lmax`
3. 区间内部子序和`dat`

因此递归计算每一个变量
对于`lmax`，有两种可能情况
1. 完全位于其左半区间`left.lmax`
2. 横跨左半区间到达右半区间`left.sum+right.lmax`

对于`rmax`，有两种可能情况
1. 完全位于其右半区间`right.rmax`
2. 横跨右半区间到达左半区间`right.sum+left.rmax`

根据上面的推导，我们还需要动态维护整个区间的和`sum`

### 与线段树的关系

如果学习过线段树的话，可以想到这里实际上是一个线段树的建树过程。线段树的节点需要维护四个变量：`sum dat lmax rmax`。
这里采用自顶向下的建树方式，递归过程分为三部：
1. 建立左子树
2. 建立右子树
3. 建立根节点

### 时间复杂度分析
线段树的每个节点会被计算一次，不存在重复计算，所以一共最多会有`O(n)`个节点，所以时间复杂度是`O(n)`的。


### 代码如下
```
class Solution {
public:
    struct Node {
        int lmax,rmax,sum,dat;
    };
    
    Node dfs(vector<int>& nums, int l, int r)
    {
        if(l==r) return {nums[l],nums[l],nums[l],nums[l]};
        
        int mid = l+r>>1;
        auto left = dfs(nums,l,mid);
        auto right = dfs(nums,mid+1,r);
        
        return {
            max(left.lmax, left.sum+right.lmax),
            max(right.rmax, left.rmax + right.sum),
            left.sum + right.sum,
            max(left.rmax+right.lmax, max(left.dat,right.dat))
        };
    }
    int maxSubArray(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1).dat;
    }
};
```

## 反正都写了，就顺便把DP的也写上吧(主要说一下思路)

### 算法简介
动态规划的难点在于集合的划分，对于连续子数组问题，每一个连续子数组对应于一个区间$[i,j]$，其中$0 \le i \le j \le n-1$，这里可以简单介绍一下那个及其简单的最终解法是怎么想出来的。

#### 第一步
区间和转变为前缀和相减：
对于求取子数组和的问题，可以很容易的采用前缀和的方式进行优化，这样用$O(n)$的时间就可以预处理出前缀和$prefix[n] = a[0] + a[1] + \cdots + a[n]$。然后利用$sum[l \cdots r] = prefix[r] - prefix[l-1]$，在$O(1)$的时间内求出任意一个前缀和。
这样很容易得到该问题的第一个优化：
暴力穷举每一对$[i,j]$，依次求取$prefix[j]-prefix[i-1]$，并求最大值。
时间复杂度$O(n^2)$。
至此问题变成了求前缀和数组中的两个不同数差值的最大值。

#### 第二步
求解$max(prefix_j-prefix_i) ,0 \le i \le j \le n-1$
动态规划问题的难点在于状态的划分，对于子数组的问题，其实是有一个子集划分的定式的：固定子数组末尾，在这里可以看成是固定`prefix[j]`，对于某个固定的$j$，则需要求解：
$prefix_j+ max(-prefix_i) ,0 \le i \le j$，即
$prefix_j-min(prefix_i) ,0 \le i \le j$
这里可以知道，对于某一个$j$,子序和取得最大值的情况是其前缀和减去它前面的前缀和的最小值。
也就是说，我们只需要动态维护前缀和的最小值即可。
此步的代码：
```
int p_min = 1e9;
int ans = -1e9;
for(int i = 0 ; i <= n ; i++) {
    ans = max(ans,prefix[i]-p_min);
    p_min = min(p_min,prefix[i])
}
```
时间复杂度$O(n)$，空间$O(n)$

#### 第三步
优化空间存储,动态计算前缀和，这时候p_min初始值置为0，代表咩有前缀。
这里可以得到我们的第三个优化：
```
int prefix = 0;
int p_min = 0;
int ans = -1e9;
for(int i = 0 ; i < n ; i++) {
    prefix += a[i];
    ans = max(ans,prefix-p_min);
    p_min = min(p_min,prefix);
}
```
时间复杂度$O(n)$，空间$O(1)$，其实这里渐进复杂度已经优化到极致了，但是空间复杂度在常数意义上还能继续优化。

#### 第四步
将`max`和`min`做等价变形
```
prefix += a[i];
if(prefix-p_min < ans) ans = prefix-p_min;
if(prefix < p_min) p_min = prefix;
```
可以看到prefix-p_min总是一起出现，他们可以优化成为一个变量x:
```
x += a[i];
if(x<ans) ans = x;
if(x<0) x = 0;
```
优化完成。
其实第三步到第四步的优化让代码更难看懂了。我觉得大家也没有必要去优化这一步了，因为前面的第一步到第三部的优化都是比较显然，而且多少有点用。第四步虽然写起来酷炫，然鹅并不能优化多少。

# 以上就是最大子序和这题的题解啦。有什么问题可以在评论区留言，同时欢迎大家的点赞！这对我真的很重要（划掉）。谢谢！