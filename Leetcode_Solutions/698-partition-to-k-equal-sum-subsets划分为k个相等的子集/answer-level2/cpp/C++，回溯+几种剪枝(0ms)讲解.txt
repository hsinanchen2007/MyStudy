![image.png](https://pic.leetcode-cn.com/13359c5fe71da4a9c1b0cbefd82fb06ca76a4449397e8f6ecc86bd0281dbc4cf-image.png)

# 思路
>首先k个子集的长度可以预先计算出来,于是可以用个dfs凑这个长度len。
>数组中的每个元素必然属于某个子集，只要全部的元素都能装到对应
>每个子集中则必然可以合法地凑出一种合法的k个子集。
>剪枝
>1,当第一个子集枚举最大的元素不能形成合法序列显然全体都不能凑成合法序列，因为这个最大元素显然不能凑到任何一个子集中
>2,当所有的数都装到子集中后显然找到一组合法序列
>3,当某一种方案不能凑给当前子集显然同大小的数也不可能凑给当前子集
**注意以上的三个剪枝即可高效地解决问题**

# 实现
```cpp
class Solution {
public:
    int n, len;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        vector<bool> vis(n, false);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) len += nums[i];
        if(len%k!=0) return false;
        len=len/k;
        return dfs(n-1, len, n, nums, vis);
    }
    
    //当前从id位置开始枚举,还有有个sz子集未合法是否能够使所有子集合法
    bool dfs(int id, int cur, int sz, vector<int>& arr, vector<bool>& vis) {
        if(sz == 0) return true; //n个数全部装下
        bool isok = false;
        for(int i=id; i>=0; i--) {
            if(!vis[i] && cur>=arr[i]) { //当前的数能够装入当前子集中
                vis[i]=true;
                isok = cur^arr[i] ? dfs(i-1, cur-arr[i], sz-1, arr, vis) : dfs(n-1, len, sz-1, arr, vis);
                if(isok || !cur) return isok;
                vis[i] = false;
                while(i>0 && arr[i-1]==arr[i]) i--; //判重剪枝
            }
        }
        return isok;
    }
};
```