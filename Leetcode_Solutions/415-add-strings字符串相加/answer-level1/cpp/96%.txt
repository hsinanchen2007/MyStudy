```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        // 126 + 79 == >  1 9 15
        if (num1.length() < num2.length()) swap(num1, num2);
        for (int i = num1.length() - 1, j = num2.length() - 1; j >= 0; i --, j --) 
            num1[i] += num2[j] - '0';
        for (int i = num1.length() - 1; i > 0; i --) {
            num1[i-1] += (num1[i] - '0') / 10;
            num1[i] = (num1[i] - '0') % 10 + '0';
        }
        int pre = num1[0] - '0';
        return to_string(pre) + num1.substr(1);
    }
};
```