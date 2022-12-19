### 解题思路
模拟乘法，将所有数据不进位直接存入数组，最后统一进位即可。

![QQ截图20200218205851.png](https://pic.leetcode-cn.com/7a0312b065ec0660752ef5c5451b59711b054d595fccb13191c62f736c045458-QQ%E6%88%AA%E5%9B%BE20200218205851.png)


### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int s1 = num1.size(), s2 = num2.size();

        int ans[s1 + s2] = {0};
        for(int i = 0; i < s1; i++) {
            for(int j = 0; j < s2; j++) {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for(int i = 0; i < s1 + s2; i++) {
            if(ans[i] > 9) {
                int t = ans[i];
                ans[i] = t % 10;
                ans[i + 1] += (t / 10);
            }
        }

        int pos = (ans[s1 + s2 - 1] == 0 ? s1 + s2 - 2 : s1 + s2 - 1);

        string aa = "";
        for(; pos >= 0; --pos) {
            aa += (ans[pos] + '0');
        }
        return aa;
    }
};

```