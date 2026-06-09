但是需要用char的数组转换一下，有没有类似但是不用转换的方法？
```
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int al, ar;
        int bl, br;
        sscanf(a.c_str(), "%d+%di", &al, &ar);
        sscanf(b.c_str(), "%d+%di", &bl, &br);
        char ansC[50];
        sprintf(ansC, "%d+%di", al*bl-ar*br, al*br+ar*bl);
        string ans(ansC);
        return ans;
    }
};
```
