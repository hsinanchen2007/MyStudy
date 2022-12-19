### 解题思路
本题是三数之和的进阶题目，强烈建议您先看三数之和的 [解题思路](https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-tu-jie-by-ml-zimingmeng/)，看过之后再来看本题目，思路也就非常清晰了。

具体来说，对比三数之和最快的双指针方法，我们只需在外层在嵌套一层循环即可。这样时间复杂度将从 $O(N^2)$ 变为 $O(N^3)$。

### 有没有更快的解法

>[维基百科](https://en.wikipedia.org/wiki/3SUM) 中提到了三数之和小于 $O(N^2)$ 的时间复杂度的解法，因此四数之和的时间复杂度理论上可以小于 $O(N^3)$，但是我认为有些“超纲了”，没必要掌握。

我们仍然可以在 $O(N^3)$ 的时间复杂度内通过增加条件判断使得速度得到很大提升。主要考虑以下几点：

1. 指针依次是 `p,k,i,j`，如果 `nums[p] + 3 * nums[p + 1] > target`，因为 `nums` 按升序排列，所以之后的数肯定都大于 `target` ，直接 `break`；

2. 如果 `nums[p] + 3 * nums[-1] < target`，那么当前的 `nums[p]` 加其余三个数一定小于 `target`，故 `p` 直接下一位即可，`continue`；

3. `k` 和 `p` 判断完全一样，只是将 `3` 变成了 `2`，`target` 变成了 `target - nums[p]`。

同样地，为了避免结果重复，某个指针遇到相同的数需要直接跳过，这与三数之和是一样的。



### 代码

```python []
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        p = 0 # p, k, i, j
        while p < n - 3:  # 文中提到的条件1和条件2，可以直接跳过
            if nums[p] + 3 * nums[p + 1] > target: break  
            if nums[p] + 3 * nums[-1] < target:           
                while p < n - 4 and nums[p] == nums[p + 1]: p += 1
                p += 1
                continue
            k = p + 1
            while k < n - 2:   # k 和 p 的判断是一样的
                if nums[p] + nums[k] + 2 * nums[k + 1] > target: break
                if nums[p] + nums[k] + 2 * nums[-1] < target: 
                    while k < n - 3 and nums[k] == nums[k + 1]:
                        k += 1
                    k += 1
                    continue
                i = k + 1
                j = n - 1
                new_target = target - nums[p] - nums[k]
                while i < j:
                    if nums[i] + nums[j] > new_target: j -= 1
                    elif nums[i] + nums[j] < new_target: i += 1
                    else:
                        res.append([nums[p],nums[k],nums[i],nums[j]])
                        i += 1
                        j -= 1
                        while i < j and nums[i] == nums[i - 1]: i += 1 # 避免结果重复
                        while i < j and nums[j] == nums[j + 1]: j -= 1 # 避免结果重复
                while k < n - 3 and nums[k] == nums[k + 1]: k += 1
                k += 1
            while p < n - 4 and nums[p] == nums[p + 1]: p += 1
            p += 1
        return res
```

```c++ []
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
### 复杂度分析
- 时间复杂度：$O(N^3)$。
- 空间复杂度：$O(1)$。

如有您有任何想法，欢迎下方留言一起讨论~

### 相关题目

- [1.两数之和](https://leetcode-cn.com/problems/two-sum/solution/tu-jie-ha-xi-biao-by-ml-zimingmeng/)
- [15.三数之和](https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-tu-jie-by-ml-zimingmeng/)
- [454. 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)