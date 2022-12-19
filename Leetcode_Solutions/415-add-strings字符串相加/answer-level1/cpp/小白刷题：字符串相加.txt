模拟笔算

代码：
```
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0" && num2 == "0")
            return "0";
        else {
            string ans = "";
            int len1 = num1.length();
            int len2 = num2.length();
            if (len1 > len2)
                num2.insert(0, len1 - len2, '0');
            else
                num1.insert(0, len2 - len1, '0');
            int carry = 0;
            int len = len1 > len2 ? len1 : len2;
            for (int i = len - 1; i >= 0; i--) {
                int digit = (int)num1[i] + (int)num2[i] - 96 + carry;
                ans.insert(0, 1, (char)(digit % 10 + 48));
                carry = digit / 10;
            }
            if (carry)
                ans.insert(0, 1, '1');
            return ans;
        }
    }
};
```
