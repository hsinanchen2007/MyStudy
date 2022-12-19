### 解题思路
1.双指针从尾向前做十进制加法运算，carry位进制位。

### 代码

```cpp
class Solution {
public:



string addStrings(string num1, string num2) {
    string result = "";

    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0){
        int n1 = i >= 0 ? num1.at(i) - '0' : 0;
        int n2 = j >= 0 ? num2.at(j) - '0' : 0;
        int tmp = n1 + n2 + carry;
        carry = tmp / 10;
        result = to_string(tmp % 10) + result;
        i--;
        j--;
    }
    if(carry == 1) result = to_string(1) + result;
    return result;
}

};
```