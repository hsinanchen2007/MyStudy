1. 结果$ans$的长度最长为$a$和$b$长度最大值加一。
2. 把$a$和$b$和结果$ans$三个数字最低位对齐。
3. 某一位的值为 `int val = ai ^ bj ^ carry`; 
4. 这位产生的进位 `carry = (ai & bj) | (carry & (ai ^ bj))`;
5. 当其中一个数，比如$b$不够时，在高位补$0$。
6. 然后去掉结果$ans$高位多余的$0$。
```
class Solution {
public:
    string addBinary(const string& a, const string& b) {
        string ans(1+max(a.size(), b.size()), '0');
        int carry = 0;
        for (int i=a.size()-1, j=b.size()-1, k=ans.size()-1; 0<=k; --i,--j,--k) {
            const int ai = 0 <= i ? a[i] - '0' : 0;
            const int bj = 0 <= j ? b[j] - '0' : 0;
            const int val = ai ^ bj ^ carry;
            carry = (ai & bj) | (carry & (ai ^ bj));
            ans[k] = val + '0';
        }
        const int p = ans.find_first_not_of('0');
        return p == string::npos ? "0" : ans.substr(p);
    }
};
```
