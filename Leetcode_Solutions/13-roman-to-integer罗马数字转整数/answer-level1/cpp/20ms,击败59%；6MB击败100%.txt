### 仿照12题的解法，算是比较容易理解
有点贪心的思想，只是12题比较的是数，这里比较的是字符串

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        if (s == "") {
            return 0;
        }
        int a[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        char ss[13][3] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        int ans = 0;
        char* p = &s[0];
        for (int i = 0; i < 13; i++) {
            string m = p;
            while (!strcmp(ss[i], m.substr(0, strlen(ss[i])).c_str()) && *p !='\0') {
                p += strlen(ss[i]);
                m = p;
                ans += a[i];
            }
        }
        return ans;
    }
};
```