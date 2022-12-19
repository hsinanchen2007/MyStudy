### 解题思路


### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        int j = 0;
        ostringstream os;
        int flag = 0;
        vector<pair<char, char>> v{{'0', '1'},{'0', '0'},{'1', '0'},{'1', '1'}};
        char x;
        char y;
        while (i < a.size() || j < b.size()) {
            if (i < a.size()) {
                x = a[i];
            } else {
                x = '0';
            }
            if (j < b.size()) {
                y = b[j];
            } else {
                y = '0';
            }
            pair<char, char> p = {x, y};
            if (flag == 0) {
                if (p == v[0] || p == v[2]) {
                    os << '1';
                } else if (p == v[1]) {
                    os << '0';
                } else {
                    os << '0';
                    flag = 1;
                }
            } else {
                if (p == v[0] || p == v[2]) {
                    os << '0';
                    flag = 1;
                } else if (p == v[1]) {
                    os << '1';
                    flag = 0;
                } else {
                    os << '1';
                    flag = 1;
                }
            }
            i++;
            j++;
        }	
        if (flag == 1) {
            os << '1';
        }
        string res = os.str();
        reverse(res.begin(), res.end());
        return res;
    }
};
/*class Solution {
public:
    string addBinary(string a, string b) {
		bitset<128> aa(a);
		bitset<128> bb(b);
        unsigned long long x = aa.to_ullong();
        unsigned long long y = bb.to_ullong();
        unsigned long long z = x + y;
        if (z == 0) {
            return "0";
        }
        bitset<256> f(z);
		string str = f.to_string();
		ostringstream os;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '1') {
				for (int k = i; k < str.size(); k++) {
					os << str[k];
				}
                break;
			}
		}
	    return os.str();
    }
};*/
```