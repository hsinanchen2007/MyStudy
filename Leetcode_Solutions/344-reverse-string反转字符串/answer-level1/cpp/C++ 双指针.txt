```
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() < 1) {
            return;
        }
        vector<char>::iterator p = s.begin();
        vector<char>::iterator q = s.end() - 1;
        while (p < q) {
            *q = *p + *q;
            *p = *q - *p;
            *q = *q - *p;
            p++;
            q--;
        }
    }
};
```


