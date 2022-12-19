感觉算是中等难度中很简单的一道题了吧，题目要求原地修改数组，那我们只需要在遍历的时候，判断某个数是否出现了三次就行了。
首先排除掉数组长度小于3的情况（必定满足条件）。
由于数组的前两个无论是想不想同都满足题目要求的条件，所以我们只需要初始化左指针left = 1；右指针指向待插入的元素；遍历判断，当右指针right指向的元素！=left-1的元素时，可知这个元素时可以插入的。相反，则证明这三个元素相同，不进行操作，直接right++，相当于删除了这个元素。
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int left = 1;
        int right = 2;
        while(right < nums.size()) {
            if(nums[right] != nums[left-1]) {
                left++;
                nums[left] = nums[right];
            }          
            right++;
        }
        return left + 1;
    }
};
```
