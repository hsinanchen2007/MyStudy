### 解题思路
注意点：
最后的几个元素要删除！

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int count = 1;
        int i, j = 1;

        for(i = 1;i < nums.size();i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
                count = 1;
        
            if(count < 3)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        while(j < i)
        {
            nums.pop_back();
            j++;
        }
        return nums.size();
    }
};
```