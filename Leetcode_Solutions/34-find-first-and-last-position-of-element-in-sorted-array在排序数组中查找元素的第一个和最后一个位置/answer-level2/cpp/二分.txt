### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);ans.push_back(-1);
        if(nums.empty())return ans;
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
            if(nums[left]>target||nums[right]<target||left==right||left+1==right)return ans;
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
        //cout<<local<<endl;
        for(int i=local;i>=0;i--)
            if(nums[i]==target)
                ans[0]=i;
            else break;
        for(int i=local;i<nums.size();i++)
            if(nums[i]==target)
                ans[1]=i;
            else break;
        return ans;
    }
};
```