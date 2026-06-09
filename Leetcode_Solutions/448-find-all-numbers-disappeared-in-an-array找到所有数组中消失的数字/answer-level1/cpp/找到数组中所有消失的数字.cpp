将数组元素对应为索引，将该索引处的值加n
遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在，即消失的数字
```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return nums;
        for(int i=0;i<nums.size();i++)
        {
            //因为nums[index]+n了，所以得%nums.size();
            int index=(nums[i]-1)%nums.size();
            nums[index]+=nums.size();
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=nums.size())
                res.push_back(i+1);
        }
        return res;
    }
};
```
作者：haydenmiao
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/cyuan-shu-zu-cao-zuo-by-haydenmiao/
来源：力扣（LeetCode）