### 解题思路
此处撰写解题思路
遍历数组，计算非重复元素个数len，如果当前元素与前一个元素不同，则用当前元素覆盖数组中len位置的元素
遍历结束后，删除掉len-1位置之后的元素
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;    //非重复元素个数
        int size = nums.size();
        if(size <= 1)
        {
            return size;
        }
        
        int pre = nums[0];
        len = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != pre)
            {
                pre = nums[i];
                nums[len] = nums[i];
                len++;
            }
        }
        nums.erase(std::begin(nums)+len-1,std::end(nums));

        return len;
    }
};
```