### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        if ( x==0 ) return 0;
        stringstream ss; string s; string s_new;
        ss << x; ss >> s; ss.clear();
        int size = (int)s.size();
        if (s[0] == '-') {
            s_new.push_back('-');
        }
        for (int i = size - 1; i >= 0 && s[i] != '-'; i--) {
            if (s[i]=='0'&& i == size - 1) continue;
            if (s_new.size()==9 && s[0] != '-') {
                int a;
                ss << s_new; ss >> a; ss.clear();
                if (a > 214748364 ||(a == 214748364 && s[i] > '7')) {
                    cout << s_new << endl;
                    cout << s[i] << "\n";
                    cout << a << endl;
                    return 0;
                }
            }
            if (s_new.size()==10 && s[0] == '-') {
                int a;
                ss << s_new; ss >> a; ss.clear();
                if (a < -214748364
                    || (a == 214748364 && s[i] > '8')) {
                    return 0;
                }
            }
            s_new.push_back(s[i]);
        }
        int a;
        ss << s_new; ss >> a;
        return a;
    }
};
```