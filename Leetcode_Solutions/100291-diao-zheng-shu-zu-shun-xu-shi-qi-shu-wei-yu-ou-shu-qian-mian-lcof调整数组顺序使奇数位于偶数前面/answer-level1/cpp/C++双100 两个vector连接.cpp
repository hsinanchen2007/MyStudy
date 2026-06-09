class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> ans;
        vector<int> hms;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
               ans.push_back(nums[i]);
            else
               hms.push_back(nums[i]);
        }
        ans.insert(ans.end(),hms.begin(),hms.end());
        return ans;
    }
};
![QQ图片20200212234447.png](https://pic.leetcode-cn.com/023d6799554b2f0c4666cbb336e7d7207644665c6ff3ab9595df2a1ee50c3e36-QQ%E5%9B%BE%E7%89%8720200212234447.png)
