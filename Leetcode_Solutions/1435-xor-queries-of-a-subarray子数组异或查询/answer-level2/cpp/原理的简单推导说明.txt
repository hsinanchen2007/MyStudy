## 原理
**假设**有整数b > a, f(a, b)即为题目所求， 
则根据 n^n = 0,      0^n = n，     a^b = b^a    （n,a,b为任意整数)
**立即推**（宇哥笑）： (1^2...^**a-1**) ^ (1^2^...b)  = (1^1)^(2^2)...a^a+1...b = f(a,b)

## talk is cheap, show code :
```
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> help;
        help.push_back(0); 

        int now = 0;
        for(int n :arr)
        {
            now ^= n;
            help.push_back(now);
            //cout << n << "-" << now << endl;
        }

        for(vector<int> n :queries)
        {
            ans.push_back(help[n[0]] ^ help[n[1]+1]);
        }

        return ans;        
    }
};
```
