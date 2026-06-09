```
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1 = stoi(a), b1 = stoi(b);
        int i = 0, j = 0;
        while (a[i] != '+') i++;
        while (b[j] != '+') j++;
        a = a.substr(i + 1), b = b.substr(j + 1);
        int a2 = stoi(a), b2 = stoi(b);
        string res1 = to_string(a1 * b1 - a2 * b2);
        string res2 = to_string(a1 * b2 + a2 * b1);
        return res1 + "+" + res2 + "i";
    }
};
```

