### 解题思路
此处撰写解题思路
这个问题可以归结为：
不断比较相邻两个数，如果不同，则记录此次变化，最终一共统计变化了多少次。
然后发现输出不对，回过头看 发现需要修改数组的内容，这个时候，加一个指针用来修改数组，达到输出的目的。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int j = 0;
        for(int i=1; i< nums.size(); i++)
        {
            if(nums[i] != nums[j]) 
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};


