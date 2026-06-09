```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //自己的方法，要排序，时间复杂度为O(nlog2n))
        //先排序（升序）
       sort(nums.begin(), nums.end());
       int count = 3;
       //再从尾到头查找第三大的元素
       for(int i = nums.size() - 1; i > 0; i--)
       {
           if(nums[i] != nums[i-1]) //相邻两个元素不同，count减1
                count--;
            if(count == 1)  ///找到了第三大的元素
                return nums[i-1];
       }
       return nums[nums.size() - 1];//没找到第三大的元素，返回最大值

    
    }
};
```
