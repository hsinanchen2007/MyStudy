str2，str2/2,str2/3 ... str2/n， 挨个试呗~

```
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 < str2) {
            str1.swap(str2);
        }
        string res = str2;
        int n = 1;
        while (n++ <= str2.size()) {
            string resTmp;
            for (int i = 1; i < n; i++) {
                resTmp += res;
            }
            if(resTmp == str2) {
                string tmp = res;
                while (tmp.size() <= str1.size()) {
                    if (tmp == str1) {
                        return res;
                    }
                    tmp += res;
                }
            }
            res = str2.substr(0, str2.size() / n);
        }
        return "";
    }
};
```
