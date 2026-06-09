### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int s=nums.size();
        for(i=0;i<s;i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
```