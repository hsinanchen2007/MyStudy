先将两数对齐，之后从末位开始加，可以利用真值表抽象出逻辑关系式，利用逻辑运算得出结果与进位情况

对了，两个0的特殊情况不要忘了

代码：
```
class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0")
            return "0";
        else {
            string ans = "";
            bool carry = false;
            int la = a.length();
            int lb = b.length();
            if (la > lb)
                b.insert(0, la - lb, '0');
            else
                a.insert(0, lb - la, '0');
            int len = a.length();
            for (int i = len - 1; i >=0; i--) {
                bool da = a[i] == '1';
                bool db = b[i] == '1';
                char digit = (da & (!db) & (!carry)) | ((!da) & db & (!carry)) | ((!da) & (!db) & carry) | (da & db & carry) ? '1' : '0';
                ans.insert(0, 1, digit);
                carry = ((!da) & db & carry) | (da & (!db) & carry) | (da & db);
            }
            if (carry)
                ans.insert(0, 1, '1');
            return ans;
        }
    }
};

```
