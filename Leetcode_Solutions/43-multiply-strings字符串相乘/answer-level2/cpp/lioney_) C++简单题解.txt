```
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> vals(m+n);
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int p1 = i+j, p2 = i+j+1;
                int val = (num1[i] - '0') * (num2[j] - '0') + vals[p2];
                vals[p2] = val % 10;
                vals[p1] += val / 10;
            }
        }
        string res = "";
        for(int v:vals) {
            if(res.empty() && v == 0) continue;
            res += to_string(v);
        }
        return res.empty() ? "0" : res;
    }
};
```
