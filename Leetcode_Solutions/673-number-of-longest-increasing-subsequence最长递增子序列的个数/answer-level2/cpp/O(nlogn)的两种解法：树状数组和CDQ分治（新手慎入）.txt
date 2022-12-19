# [求LIS个数：O(nlogn)的两种解法（知乎）](https://www.zhihu.com/question/34905638)
## [1. 用树状数组维护LIS个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yi-bu-yi-bu-tui-dao-chu-zui-you-jie-fa-2-zui-chang/)
树状数组部分是摘录[newhar的题解](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yi-bu-yi-bu-tui-dao-chu-zui-you-jie-fa-2-zui-chang/)
![20200317170811.png](https://pic.leetcode-cn.com/9970ce5aed18da146aab5fe252f514f5b3379a2b77754fc2209f84de0ce13f67-file_1584698528497)

```cpp
class Solution
{
    class Node
    {
    public:
        int maxlength, cnt;
        Node()
        {
            maxlength = 1;
            cnt = 0;
        }
        // 区间合并法则
        // override: +=
        Node operator+=(Node &b)
        {
            if (b.maxlength == this->maxlength)
            {
                this->cnt += b.cnt;
            }
            else if (b.maxlength > this->maxlength)
            {
                this->maxlength = b.maxlength;
                this->cnt = b.cnt;
            }
            return *this;
        }
    };

    int lowbit(int x)
    {
        return x & (-x);
    }

    // 更新一个点后向上更新
    void add(Node nodes[], int rank, Node now, int size)
    {
        for (; rank <= size; rank += lowbit(rank))
        {
            nodes[rank] += now;
        }
    }

    // 单点查找
    Node query(Node nodes[], int rank)
    {
        Node res;
        while (rank)
        {
            res += nodes[rank];
            rank -= lowbit(rank);
        }
        return res;
    }

public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        vector<int> sortnums(nums);
        sort(sortnums.begin(), sortnums.end());
        Node nodes[nums.size() + 1] = {Node()};
        Node ans = Node();
        // 按nums[]顺序遍历，保证j<i这个条件,同时又用二分查找找出当前数num的下界nums[rank]
        // 以nums[rank]结尾的LIS是最长的（之一）,长度为lmax
        // 长度为lmax的LIS个数已经在树状数组中，查询后可得到
        // 把当前数num加到树状数组里面
        for (auto num : nums)
        {
            // 二分搜索当前数的下界排名
            int rank = lower_bound(sortnums.begin(), sortnums.end(), num) - sortnums.begin();
            Node now = query(nodes, rank);
            now.maxlength++;
            now.cnt = max(now.cnt, 1);
            ans += now;
            add(nodes, rank + 1, now, nums.size());
        }
        return ans.cnt;
    }
};
```
## [2. 什么是CDQ分治](https://oi-wiki.org/misc/cdq-divide/)

LIS是一个二维偏序问题。  
来看看LIS的状态转移方程：  
`Lis[i]=max{Lis[j]+1}   j<i && nums[j]<nums[i]`    
此处的点对是`(i,nums[i])`

![20200316093244.png](https://pic.leetcode-cn.com/99a2d255dddfe5f7e1724be1445a52a9eb30712b10e5ff4dc2e857458ef46068-file_1584698528489)

![20200316093734.png](https://pic.leetcode-cn.com/19d86de5d4818cdaec81753811f5b9adfcdcd30ee7ede01d7c15642c843c9487-file_1584698528495)



### cdq求LIS长度
__cdq的本质：分治过程中用左边的信息更新右边的__
### 状态定义
`Length_Lis[i]`表示以第`i`个元素为结尾的LIS长度
```cpp
bool cmp(int a, int b)
{
    if (nums_copy[a] == nums_copy[b])
        return a > b;
    return nums_copy[a] < nums_copy[b];
}
void cdq(int left, int right)
{
    if (left == right)
    {
        if (!Length_Lis[left])
        {
            Length_Lis[left] = 1;
        }
        return;
    }
    int mid = (left + right) >> 1;
    cdq(left, mid);
    // 用左边的信息更新右边的
    for (int i = left; i <= right; i++)
    {
        id[i] = i;
    }
    sort(id + left, id + right + 1, cmp);
    int len = 0;
    // 排序后的nums[left,right]单调递增
    for (int i = left; i <= right; i++)
    {
        // 当前数在左边，左边已经有解，更新当前LIS长度
        if (id[i] <= mid)
        {
            len = max(len, Length_Lis[id[i]]);
        }
        // 当前数在右边，更新LIS
        // 满足二维偏序：id[i]<id[j] and nums[i]<nums[j]
        else
        {
            Length_Lis[id[i]] = max(Length_Lis[id[i]], len + 1);
            if (Length_Lis[id[i]] > Maxlen)
            {
                Maxlen = Length_Lis[id[i]];
            }
        }
    }
    cdq(mid+1,right);
}
```

那怎么求LIS个数呢？  
### 定义状态
`Num_Lis[i]`表示以第`i`个元素为结尾的LIS的个数  
在cdq递归结束后，再统计所有元素中的LIS的个数`Maxnum`
### 转移状态（用左边更新右边）的条件
首先一定要满足LIS的条件`id[i]<id[j] and nums[i]<nums[j]`（二维偏序）

满足二维偏序后的两种转移方式：
1. 以右边元素为结尾的LIS长度=以左边元素为结尾的LIS长度+1 --> 以右边元素为结尾的LIS个数+=以左边元素为结尾的LIS个数
2. 以右边元素为结尾的LIS长度<以左边元素为结尾的LIS长度+1 --> 以右边元素为结尾的LIS个数=以左边元素为结尾的LIS个数；以右边元素为结尾的LIS长度=以左边元素为结尾的LIS长度+1

### 最长上升序列
特判一下以左边元素为结尾的LIS长度为0的情况，不转移  
这一道题求的是最长上升序列的个数    
__最长上升序列!=最长不下降序列__  
```
[2,2,2,2,2]
LIS长度为1，个数为5
```
### code
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int nums_copy[2005];
bool cmp(int a, int b)
{
    if (nums_copy[a] == nums_copy[b])
        return a > b;
    return nums_copy[a] < nums_copy[b];
}

class Solution
{
public:
    int Num_Lis[2005], id[2005], Length_Lis[2005];
    int Maxnum = 0;
    int Maxlen = 0;
    void cdq(int left, int right)
    {
        if (left == right)
        {
            if (!Length_Lis[left])
            {
                Length_Lis[left] = 1;
                Num_Lis[left] = 1;
            }
            return;
        }
        int mid = (left + right) >> 1;
        cdq(left, mid);
        // 用左边的信息更新右边的
        for (int i = left; i <= right; i++)
        {
            id[i] = i;
        }
        sort(id + left, id + right + 1, cmp);
        int len = 0;
        int num = 0;
        // 排序后的nums[left,right]单调递增
        for (int i = left; i <= right; i++)
        {
            // 当前数在左边，左边已经有解，更新当前LIS长度
            if (id[i] <= mid)
            {
                if (len < Length_Lis[id[i]])
                {
                    len = Length_Lis[id[i]];
                    num = Num_Lis[id[i]];
                }
                else if (len == Length_Lis[id[i]])
                {
                    num += Num_Lis[id[i]];
                }
            }
            // 当前数在右边，更新LIS
            // 满足二维偏序：id[i]<id[j] and nums[i]<nums[j]
            else
            {
                // len=0表示没有信息可以转移
                if (!len)
                {
                    continue;
                }
                if (Length_Lis[id[i]] == len + 1)
                {
                    Num_Lis[id[i]] += num;
                }
                else if (Length_Lis[id[i]] < len + 1)
                {
                    Length_Lis[id[i]] = len + 1;
                    Num_Lis[id[i]] = num;
                }
            }
        }
        cdq(mid + 1, right);
    }

    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            nums_copy[i] = nums[i];
        }
        cdq(0, nums.size() - 1);
        Maxnum = 0;
        Maxlen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Length_Lis[i] > Maxlen)
            {
                Maxlen = Length_Lis[i];
                Maxnum = Num_Lis[i];
            }
            else if (Length_Lis[i] == Maxlen)
                Maxnum += Num_Lis[i];
        }
        return Maxnum;
    }
};
```
### 题后思考：为什么让相等的两个元素按原始位置倒序排列？
```cpp
bool cmp(int a, int b)
{
    // Why?
    if (nums_copy[a] == nums_copy[b])
        return a > b;
    return nums_copy[a] < nums_copy[b];
}
```

如果正序会怎么样？

让我们对比两种排序方式产生的效果：
```
e.g.
1,2a,2b,4
(用a,b记录它们的原始位置)

1st: 
if (nums_copy[a] == nums_copy[b])
    return a > b;
1,2b,2a,4

2nd:
if (nums_copy[a] == nums_copy[b])
    return a < b;
1,2a,2b,4

因为这道题求的是最长上升序列，所以2a的状态不能转移给2b。
按正序排列，2a的状态会转移给2b。
那如果我们特判在左边的前一个元素是否与当前右边的元素相等，也就是2a==2b?，这样是否可行呢？
if (pre == nums_copy[id[i]])
    continue;
答案是不行，因为这样1的信息会丢失，无法转移到2b上。
```

## 写在最后
有一说一，cdq分治确实有点难度，我花了几天的时间在上面。  
难点就在于怎么用左边的信息更新右边的，什么时候更新，而且不能用右边的信息更新右边的信息。  
这种分治的思想确实很神奇。

当然，树状数组的解法也很神奇，[这位大佬的题解](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yi-bu-yi-bu-tui-dao-chu-zui-you-jie-fa-2-zui-chang/)值得一看。

[拓展：CDQ多维分治](https://zhuanlan.zhihu.com/p/55322598)