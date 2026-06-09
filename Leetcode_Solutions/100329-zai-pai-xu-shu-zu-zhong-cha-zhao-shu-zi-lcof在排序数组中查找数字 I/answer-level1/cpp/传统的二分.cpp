### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        int left=0,right=nums.size()-1;
        int local;
        int cnt=0;
        while(1)
        {
            if(nums[left]==target)
            {
                local=left;
                break;
            }
            if(nums[right]==target)
            {
                local=right;
                break;
            }
            if(nums[left]>target||nums[right]<target||left==right||left+1==right)return 0;
            if(nums[(left+right)/2]>target)
            {
                right=(left+right)/2;
                continue;
            }
            if(nums[(left+right)/2]<target)
            {
                left=(left+right)/2;
                continue;
            }
            if(nums[(left+right)/2]==target)
            {
                local=(left+right)/2;
                break;
            }
        }
        for(int i=local;i>=0;i--)
            if(nums[i]==target)cnt++;
            else break;
        for(int i=local+1;i<nums.size();i++)
            if(nums[i]==target)cnt++;
            else break;
        return cnt;
    }
};
```