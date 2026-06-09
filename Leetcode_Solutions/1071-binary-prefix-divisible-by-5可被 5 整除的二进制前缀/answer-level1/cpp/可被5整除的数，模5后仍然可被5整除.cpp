```
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int sum = 0;
        for(auto n : A)
        {
            sum = (sum * 2 + n) % 5;  // 模5，防止溢出
            if(sum%5==0)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};
```