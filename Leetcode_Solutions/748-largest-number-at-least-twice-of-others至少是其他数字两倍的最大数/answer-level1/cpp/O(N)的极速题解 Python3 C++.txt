贪心算法，只要遍历一遍，遍历第一项的时候即把它当作最大项，以后如果出现更大的，再将最大项设置为它。同时有一个flag记录是否符合大两倍的条件。


C++代码实现如下

```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        int max_index = 0;
        bool flag = true;
        for (int i=1;i<nums.size();i++){
            if (nums[max_index] > nums[i]){
                if (flag)
                    flag = nums[max_index] >= 2 * nums[i];
            }
            else{
                flag = nums[i] >= 2 * nums[max_index];
                max_index = i;
            }

        }
        if (!flag) return -1;
        else return max_index;
    }
};
```

Python3 实现如下：

```
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums)== 0:
            return -1 
        if len(nums) == 1:
            return 0 
        max_index = 0
        flag = True
        for i in range(1,len(nums)):          
            if nums[max_index] > nums[i]:
                if flag:
                    flag = nums[max_index] >= 2 * nums[i] 
            else:
                flag = nums[i] >= 2 * nums[max_index]
                max_index = i
        if not flag:
            return -1 
        else:
            return max_index
```