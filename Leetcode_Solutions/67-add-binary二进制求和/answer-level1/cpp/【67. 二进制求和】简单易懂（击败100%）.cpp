## 思路
### 代码
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        string str;
        int c = 0, i = len1 - 1, j = len2 - 1;
        while (i >= 0 && j >= 0) {
            int t = a[i--] - '0' + b[j--] - '0' + c;
            str += t % 2 + '0';
            c = t / 2;
        }
        while (i >= 0) {
            int t = a[i--] - '0' + c;
            str += t % 2 + '0';
            c = t / 2;
        }
        while (j >= 0) {
            int t = b[j--] - '0' + c;
            str += t % 2 + '0';
            c = t / 2;
        }
        if (c > 0) {
            str += '1';
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
```
#### 简化代码
补0法。
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        string str;
        int c = 0, i = len1 - 1, j = len2 - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            str += (c % 2) + '0';
            c = c / 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
```

