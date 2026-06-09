### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j,n=0;
        for(j=0;j<nums.size()-n;j++)
        {
            if(nums[j]==val)
            {
                for(int t=j;t<nums.size()-1;t++)
                    nums[t]=nums[t+1];
                j--;
                n++;
            }
            else i++;
        }
        return i;
    }
};
```