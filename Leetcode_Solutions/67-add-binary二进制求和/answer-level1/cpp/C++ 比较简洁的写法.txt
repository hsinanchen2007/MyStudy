```
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        int c = 0;
        string res;
        while (len1 > 0 || len2 > 0 || c != 0) {
            int temp = c;
            if (--len1 >= 0) {
                temp += (a[len1] - '0');
            }
            if (--len2 >= 0) {
                temp += (b[len2] - '0');
            }
            c = temp >= 2 ?  1 : 0;
            res += to_string(temp % 2);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```

