```C++ []
class Solution {
public:
    string add(string num1, string num2) {
        int pos1 = num1.size() - 1;
        int pos2 = num2.size() - 1;
        string sum = "";
        string num = "";
        int jinwei = 0;
        int p1, p2;
        p1 = p2 = 0;
        while (pos1 >= 0 && pos2 >= 0) {
            p1 = num1[pos1--] - '0';
            p2 = num2[pos2--] - '0';
            num = (jinwei + p1 + p2) % 10 + '0';
            jinwei = (jinwei + p1 + p2) / 10;
            sum = num + sum;
        }
        while (pos1 >= 0) {
            p1 = num1[pos1--] - '0';
            num = (jinwei + p1) % 10 + '0';
            jinwei = (jinwei + p1) / 10;
            sum = num + sum;
        }
        while (pos2 >= 0) {
            p2 = num2[pos2--] - '0';
            num = (jinwei + p2) % 10 + '0';
            jinwei = (jinwei + p2) / 10;
            sum = num + sum;
        }
        if (jinwei) {
            sum = "1" + sum;
        }
        return sum;
    }
    string multiply(string num, int now) {
        int pos = num.size() - 1;
        int jinwei = 0;
        string ret = "";
        string nu;
        int p = 0;
        while (pos >= 0) {
            p = num[pos--] - '0';
            nu = (jinwei + p * now) % 10 + '0';
            jinwei = (jinwei + p * now) / 10;
            ret = nu + ret;
        }
        if (jinwei) {
            nu = jinwei + '0';
            ret = nu + ret;
        }
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int pos = num2.size() - 1;
        int now = 0;
        string zore = "";
        string ret = "";
        while (pos >= 0) {
            now = num2[pos--] - '0';
            ret = add(ret, multiply(num1, now) + zore);
            zore += "0";
        }
        return ret;
    }
};
```
