```
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> mb;
        int suma = 0;
        int sumb = 0;
        int n;
        vector<int> res;
        for(auto a:A)
            suma += a;
        for(auto b:B)
        {
            sumb += b;
            mb.insert(b);
        }
        for(auto a:A)
        {
            n = a - (suma - sumb)/2;
            if(mb.count(n) > 0)
            {
                res.push_back(a);
                res.push_back(n);
                break;
            }
        }
        return res;
    }
};
```
