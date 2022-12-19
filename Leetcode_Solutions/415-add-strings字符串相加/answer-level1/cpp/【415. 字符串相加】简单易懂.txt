## 思路
从低位到高位相加，大数相加。
**注意：整数加到string中需要加'0'转为字符**

### 代码
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int i = len1 - 1, j = len2 - 1;
        int c = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int a = num1[i--] - '0' + num2[j--] - '0' + c;
            res += a % 10 + '0';
            c = a / 10;            
        }
        while (i >= 0) {
            int a = num1[i--] - '0' + c;
            res += a % 10 + '0';
            c = a / 10;
        }
        while (j >= 0) {
            int a = num2[j--] - '0' + c;
            res += a % 10 + '0';
            c = a / 10;
        }        
        if (c > 0) {
            res += c + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

### 简化代码
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size(), i = len1 - 1, j = len2 - 1, c = 0;
        string res;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int num = a + b + c;
            res.insert(res.begin(), num % 10 + '0');
            c = num / 10;
        }
        return c > 0 ? '1' + res : res;
    }
};
```

