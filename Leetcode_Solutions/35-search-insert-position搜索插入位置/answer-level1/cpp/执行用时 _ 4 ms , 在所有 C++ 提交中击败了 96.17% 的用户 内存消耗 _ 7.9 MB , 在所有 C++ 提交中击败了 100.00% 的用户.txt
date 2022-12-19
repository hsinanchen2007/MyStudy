### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(target<=nums[i]) {cnt=i;break;}
            else cnt=i+1;
        }
       return cnt; 
    }
};
```