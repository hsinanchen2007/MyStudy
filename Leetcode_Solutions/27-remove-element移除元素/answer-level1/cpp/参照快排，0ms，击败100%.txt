### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int i=0,j=nums.size()-1;
        while(i<=j){
            while(i<=j && nums[i]!=val)i++;
            while(i<=j && nums[j]==val)j--;
            if(i<j) nums[i++]=nums[j--];
        }
        return i;
    }
};
```