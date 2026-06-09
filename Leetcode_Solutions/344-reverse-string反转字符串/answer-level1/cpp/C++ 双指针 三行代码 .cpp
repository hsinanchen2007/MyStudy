注意while循环的条件是`l<r`不是`l<=r`

```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r=s.size()-1;
        while(l<r)
            swap(s[l++], s[r--]);
    }
};
```
