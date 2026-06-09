### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_len=0;
        int j=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            while(j<nums.size() && (nums[i]-nums[j]>1))
            {
                //nums[i]-nums[j]>1说明j太小，即离i太远，i一直往右滑动
                j++;
            }
            if(nums[i]-nums[j]==1)
            {
                max_len=max(max_len,i-j+1);
            }
        }
        return max_len;
    }
};
```未来再用哈希试试