### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 < n2) {
            string s2(n1, '0');
            s2 = s2 + num2;
            return helper(num1, s2);
        }
        string s1(n2, '0');
        s1 = s1 + num1;
        return helper(num2, s1);
    }

    string helper(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int carry = 0;
        int val = 0;
        string res(n1+n2, '0');
        for(int i = n1-1; i >= 0; --i) {
            int index = n2 + i;
            for(int j = n2-1; j >= 0; --j) {
                val = (s1[i]-'0') * (s2[j]-'0') + (res[index]-'0') + carry;
                carry = val / 10;
                val = val % 10;
                res[index--] = val+'0';
            }
        }
        //res[index] = carry + '0';
        int k = 0;
        while(k < res.size() && res[k] == '0') {
            ++k;
        }
        if (k == res.size()) {
            return "0";
        }
        return res.substr(k);
    }
};
```