### 解题思路
1.  为了后面方便运算，先确保num2的字符串长度比num1的长
2.  为了后面方便运算，如果两个字符串不等长，在短的字符串前补'0'
3.  用flag标记是否进位，从后往前加

4ms,        95.19%
25.9 MB,    20.62%

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::ios::sync_with_stdio(0);
        if(num2.length()>num1.length()) swap(num1, num2);   // 确保num1的长度大于num2

        int diff = num1.length()-num2.length();
        while(diff-->0) num2 = '0'+num2;          // 如果两个字符串不等长，在短的字符串前补'0'

        int flag = 0, j = num2.length()-1, sum;   // flag标记是否进位

        for(int i = num1.length()-1; i>=0; i--){
            sum = (num1[i]-'0') + (num2[j--]-'0') + flag;
            if(sum>9) flag = 1;
            else flag = 0;
            num1[i] = sum%10 + '0';
        }

        if(flag==1) num1 = '1'+num1;

        return num1;
    }
};

```