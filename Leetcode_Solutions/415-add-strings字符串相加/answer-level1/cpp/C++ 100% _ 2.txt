### 虽然啰嗦了点，可是浅显易懂
```cpp
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result;
        bool flag = 0;

        while (i >= 0 && j >= 0) {
            int sum = num1[i--] - '0' + num2[j--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        while (i >= 0) {
            int sum = num1[i--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        while (j >= 0) {
            int sum = num2[j--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        if (flag == 1) { result.push_back('1'); }

        reverse(result.begin(), result.end());

        return result;
    }
};
```
![WX20200309-234122.png](https://pic.leetcode-cn.com/38ecd41cec23f224dee5ae9c5d73ea0240cc9db5cee0219d2c0f48d2a1fe6a90-WX20200309-234122.png)
