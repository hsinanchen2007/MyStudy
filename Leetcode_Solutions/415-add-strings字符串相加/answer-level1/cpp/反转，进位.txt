### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {

        int t = 0;//进位
        string res = "";
        //反转
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0 ;i < num1.length() || i < num2.length();i++)
        {
            if(i < num1.length()) t += num1[i] - '0';
            if(i < num2.length()) t += num2[i] - '0';
            res +=to_string(t % 10);
            t = t / 10;
        }
        if(t) 
        res +=to_string(t);
        reverse(res.begin(),res.end());
        return res;

    }
};
```