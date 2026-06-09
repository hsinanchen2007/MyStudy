# [惯性思维害死人](https://leetcode-cn.com/problems/count-number-of-teams/)
每 3 个士兵可以组成一个作战单位，分组规则如下：

从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]  
作战单位需满足:  
$rating[i] < rating[j] < rating[k]$ or $rating[i] > rating[j] > rating[k]$  
$0 <= i < j < k < n$

一开始我想到了这是一种偏序关系，是不是可以用LIS来求呢？  
于是走上了一条不归之路......

等价于求一个数列中，长度为3的递增序列个数

1. 一开始想，这不是很简单吗？直接套LIS模板，长度为3的递增序列个数=${LISLength}\choose{3}$。交的时候发现不对劲，因为LIS可能有多个。
2. 然后就套求LIS个数的模板了，但这样也是错的
3. 要不我们求长度等于LISLength的所有递增序列中出现过的元素个数$tot$，答案是${tot}\choose{3}$，转移的时候还要带上路径。  

估计一下这样做的时间复杂度：  
$O(n^2)$求LIS，$O(n*k)$求出现过的元素个数，其中$k=LISLength*LISNumber$  
总的时间复杂度为$O(n^2)$

看起来没问题，但其实问题很大：  
__长度为3的递增序列__可以不出现在LIS中
```
e.g.
1 1000 1001 2 3 4 5 6
(1,1000,1001)就没有出现在LIS(1,2,3,4,5,6)中
```
所以这题跟LIS一点关系都没有！

我还是去看[官方题解](https://leetcode-cn.com/problems/count-number-of-teams/solution/tong-ji-zuo-zhan-dan-wei-shu-by-leetcode-solution/)吧  
1. 暴力枚举三个数看它们是否满足关系$O(n^3)$
2. 枚举中间的数，求左侧比它大/小的元素的个数，求右侧比它大/小的元素的个数$O(n^2)$
3. 离散化树状数组优化第二种方法$O(nlogn)$

第二种方法的代码：
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int ans = 0;
        int n = rating.size();
        if (n < 3)
            return 0;
        for (int i = 1; i < rating.size() - 1; i++)
        {
            int left_less_num = 0;
            int left_bigger_num = 0;
            int right_less_num = 0;
            int right_bigger_num = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] > rating[i])
                {
                    left_bigger_num++;
                }
                else if (rating[j] < rating[i])
                {
                    left_less_num++;
                }
            }
            for (int j = i + 1; j < rating.size(); j++)
            {
                if (rating[j] > rating[i])
                {
                    right_bigger_num++;
                }
                else if (rating[j] < rating[i])
                {
                    right_less_num++;
                }
            }
            ans += left_less_num * right_bigger_num + left_bigger_num * right_less_num;
        }
        return ans;
    }
};
```
惯性思维害死人啊啊啊啊！！！！