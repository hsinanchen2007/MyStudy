### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int length=nums.size();
        for(int i=0;i<length;++i)
        {
            if(nums[i]==val){
                count++;
                continue;
            }
            nums[i-count]=nums[i];
        }
        return length-count;
    }
};
```