![image.png](https://pic.leetcode-cn.com/c50bf40a1529eb624d1492e797f1469b3cd1c5e2838fbe05bd5601686c968c9f-image.png)

### 解题思路
利用一个变量carry将每位相加的结果累计起来，同时解决了进位问题。

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        while(carry !=0 || i >= 0 || j>=0){
            if(i >= 0) carry += (num1[i--] - '0');
            if(j >= 0) carry += (num2[j--] - '0');
            res.push_back((carry % 10) + '0');
            carry /= 10; 
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```