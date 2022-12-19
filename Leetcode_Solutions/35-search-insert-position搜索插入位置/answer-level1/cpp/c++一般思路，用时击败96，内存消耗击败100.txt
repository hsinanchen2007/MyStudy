### 解题思路
由于数组升序，只要找到大于等于target的位置就返回

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0]){return 0;}
        int length=nums.size();
        if(target>nums[length-1]){return length;}
        int pos;
        for(int i=1;i<length;++i)
        {
            if(nums[i]>=target){pos=i;break;}
        }
        return pos;
    }
};
```