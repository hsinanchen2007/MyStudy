```
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> num;
        vector<vector<int>> nums;
        vector<string> ret;
        int n = 0;
        for(int i=0; i<A.size(); i++)
        {
            num = vector<int>(26, 0);
            for(auto c:A[i])
            {
                num[c-'a']++;
            }
            nums.push_back(num);
        }
        for(int i=0; i<26; i++)
        {
            n = INT_MAX;
            for(int j=0; j<A.size(); j++)
            {
                if(nums[j][i] < n)
                    n = nums[j][i];
            }
            for(int k=0; k<n; k++)
            {
                ret.push_back(string(1,'a'+i));
            }
        }
        return ret;
    }
};
```
