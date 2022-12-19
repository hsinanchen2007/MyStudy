## 解题思路

基本思想就和 [3Sum](https://leetcode-cn.com/problems/3sum/solution/) 相同

先后固定其中两个数值 $i$、$j$，再使用双指针寻找与目标合适的差值

## 算法流程

1. 判断数组大小是否符合要求

1. 对数组进行排序 --> 此处是为了方便双指针根据数值大小移动
1. 固定一个数 $nums[i]$，并判断条件是否成立 或 是否有重复项
1. 在固定 $nums[i]$ 的基础上，再次固定一个数值 $nums[j]$，同样判断条件是否成立 或 是否有重复项
1. 在 $nums[j]$ 后面两端设定两个指针 $start=j+1$, $end=nums.size()-1$, 计算 $nums[i]+nums[j]+nums[start]+nums[end]$，判断四数之和 $Sum$ 与目标值的大小关系:
    * 如果 $Sum < target$, $end$ 指针左移
    * 如果 $Sum > target$, $start$ 指针右移
    * 如果 $Sum == target$, 将四数添加进结果数组中
        * $nums[start] == nums[start - 1]$ --> 结果重复，跳过这一结果
        * $nums[end] == nums[end - 1]$ ------> 结果重复，跳过这一结果

## 复杂度分析
* 时间复杂度：$O(n^3)$
    * 数组排序： $O(nlog(n))$
    * 数组遍历两次： $O(n^2)$
    * 双指针：$O(n)$
    * 总体：$O(nlog(n)) + O(n^2) \times O(n)$
* 空间复杂度：$O(1)$

## 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
             return result;
        
        size_t n_size = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n_size-3; i++){
            // 不存在
            if(target<=0 && nums[i]>0) break;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            // 此时条件不满足
            if(nums[i]+nums[n_size-3]+nums[n_size-2]+nums[n_size-1]<target) continue;
            // 重复项
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n_size-2; j++){
                // 不存在
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                // 此时条件不满足
                if(nums[i]+nums[j]+nums[n_size-2]+nums[n_size-1]<target) continue;
                // 重复项
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int start=j+1, end=n_size-1;
                while(start<end){
                    int sum = nums[i]+nums[j]+nums[start]+nums[end];
                    if(sum<target) start++;
                    else if(sum>target) end--;
                    else{
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int last_start=start, last_end=end;
                        // 剔除重复项
                        while(start<end && nums[start] == nums[last_start]) start++;
                        while(start<end && nums[end] == nums[last_end]) end--;
                    }
                }
            }
        }
        return result;
    }
};
```

## 执行结果

![屏幕快照 2019-12-06 14.11.07.png](https://pic.leetcode-cn.com/64c117dd767bcd331b7cde0e3a1ab5d737c4eb2473a81d8df526950596c353a1-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-06%2014.11.07.png)
