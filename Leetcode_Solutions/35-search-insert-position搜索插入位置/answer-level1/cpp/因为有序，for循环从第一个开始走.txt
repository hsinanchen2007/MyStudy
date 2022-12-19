### 
遍历一遍，从第一个开始查找，不好的就是我的这个太占内存……
### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int position;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<target)
            {
                position=i+1;
            }
            else if(nums[i]==target)
            {
                position=i;//直接返回位置
                break;
            }
            else if(nums[i]>target)
            {
                position=i;
                break;
            }
        }
        return position;
    }
};
```