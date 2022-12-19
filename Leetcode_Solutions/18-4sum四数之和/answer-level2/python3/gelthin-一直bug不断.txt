### 解题思路
参照题解 [双指针解法。参照三数之和，嗝。](https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/), 首先固定两个指针在开头，然后只遍历两个指针

>使用四个指针(a<b<c<d)。固定最小的a和b在左边，c=b+1,d=_size-1 移动两个指针包夹求解。
>保存使得nums[a]+nums[b]+nums[c]+nums[d]==target的解。偏大时d左移，偏小时c右移。c和d相
>遇时，表示以当前的a和b为最小值的解已经全部求得。b++,进入下一轮循环b循环，当b循环结束后。
>a++，进入下一轮a循环。 即(a在最外层循环，里面嵌套b循环，再嵌套双指针c,d包夹求解)。

这里就是调节 i,j 指针去重， 写代码要细致小心。

if (i>0) and (nums[i]==nums[i-1]):
    continue

if j>i+1 and (nums[j]==nums[j-1]): # bug 对 j>0 [0,0,0,0] 出错 j>1 [-4,-1,-1,0,1,2] 出错
    continue

准备工作：

 因为要使用双指针的方法，排序是必须要做der~。 时间复杂度O(NlogN).

解决重复解：

 上面的解法存在重复解的原因是因为移动指针时可能出现重复数字的情况。所以我们要确保移动指针后，
 对应的数字要发生改变才行哦。

看了下别人的代码，[更加紧凑](https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/189146)

参照另一个题解 [击败99.94%的用户，有代码，有注释](https://leetcode-cn.com/problems/4sum/solution/ji-bai-9994de-yong-hu-you-dai-ma-you-zhu-shi-by-yo/) 可以加入一些计算 min, max 的代码，直接跳过，一部分计算，节省时间。


``` java
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size=nums.size();
        for(int a=0;a<size-3;++a)
        {
            if(a>0&&nums[a]==nums[a-1])continue;
            for(int b=a+1;b<size-2;++b)//以下代码与三数之和一样的
            {
                if(b>a+1&&nums[b]==nums[b-1])continue;//仅当 b>a+1跳过重复数, 若 b==a+1, nums[b] = nums[a]不算重复
                int i=b+1,j=size-1;
                while(i<j)
                {
                    int sum=nums[a]+nums[b]+nums[i]+nums[j];
                    if(sum<target)
                        while(i<j&&nums[i]==nums[++i]); // 跳过重复
                    else if(sum>target)
                        while(i<j&&nums[j]==nums[--j]); // 跳过重复
                    else{
                        result.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                        while(i<j&&nums[i]==nums[++i]); // 跳过重复
                        while(i<j&&nums[j]==nums[--j]); // 跳过重复
                    }
                }
            }
        }
        return result;
    }
};
```

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        n = len(nums)
        if n<4:
            return []
        
        nums.sort()
        result = []
        for i in range(0, n-3):
            if (i>0) and (nums[i]==nums[i-1]):
                continue
            # 未来所有的最小值都大于 target
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target:
                break
            # 以 nums[i] 为第一个元素的最大值都小于 target， 跳过 i, 继续对 i+1 进行搜索
            if nums[i] + nums[n-3]+nums[n-2]+nums[n-1] < target:
                continue
            for j in range(i+1, n-2):
                if j>i+1 and (nums[j]==nums[j-1]): # bug 对 j>0 [0,0,0,0] 出错 j>1 [-4,-1,-1,0,1,2] 出错
                    continue
                # 未来所有的可能的值都大于 target， 这里应该直接跳过两重循环，但 break 只能跳过一重。
                if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target:
                    break
                # 以 nums[i], nums[j] 为第一、二个元素的最大值都小于 target， 跳过 j, 继续对 j+1 进行搜索
                if nums[i] + nums[j]+nums[n-2]+nums[n-1] < target:
                    continue
                
                k, m = j+1, n-1
                val = nums[i]+nums[j]
                while k<m:
                    
                    sum_4 = val + nums[k] + nums[m]
                    if sum_4 == target:
                        result.append([nums[i],nums[j],nums[k],nums[m]])
                        k += 1
                        m -= 1
                        while k<m and nums[k] == nums[k-1]:
                            k += 1
                        while m>k and nums[m] == nums[m+1]:
                            m -= 1
                    elif sum_4 < target:
                        k += 1
                        while k<m and nums[k] == nums[k-1]:
                            k += 1
                    else:
                        m -= 1
                        while m>k and nums[m] == nums[m+1]:
                            m -= 1

        return result
```