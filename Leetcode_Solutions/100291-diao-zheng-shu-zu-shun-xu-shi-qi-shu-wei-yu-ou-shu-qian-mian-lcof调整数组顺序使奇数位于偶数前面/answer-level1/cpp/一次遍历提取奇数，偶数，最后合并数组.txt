三个容器，先奇数，在偶数，最后合并
执行用时 :20 ms, 在所有 C++ 提交中击败了91.08% 的用户
内存消耗 :21.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2 == 1)
            {
                odd.push_back(nums[i]);
            }
            if(nums[i]%2 == 0)
            {
                even.push_back(nums[i]);
            }
        }
        vector<int> output;
		output.insert(output.end(),odd.begin(),odd.end());
		output.insert(output.end(),even.begin(),even.end());
    return output;
    }
};