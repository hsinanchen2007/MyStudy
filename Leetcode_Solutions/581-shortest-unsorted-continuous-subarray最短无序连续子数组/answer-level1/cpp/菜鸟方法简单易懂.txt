### 解题思路
创建一个数组保存排序后的nums数组，分别找到第一个和最后一个同下标却不同值的元素，两个下标的差-1就是最短子数组长度。

### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> v(nums);
        
        sort(v.begin(),v.end());
        
        int start=0;
        int end=nums.size()-1;
        
        while(start<end)
        {
            if(nums[start]==v[start])
            {
                start++;
            }
            else
            {
                break;
            }
        }
        
        while(start<end)
        {
            if(nums[end]==v[end])
            {
                end--;
            }
            else
            {
                break;
            }
        }
        
        if(start>=end)
        {
            return 0;
        }
        
        return end-start+1;

    }
};
```