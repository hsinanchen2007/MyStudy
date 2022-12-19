### 解题思路
先判断两个字符串是否长度为0；都不为0时长度用零补全；然后一位位相加；若相加结果大于10，则取余进一。

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len_num1 = num1.size(),len_num2 = num2.size();
        if (len_num1 == 0) {
            return num2;
        }
        if (len_num2 == 0) {
            return num1;
        }
        while(len_num1<len_num2){
            num1 = '0'+num1;
            ++len_num1;
        }
        while(len_num1>len_num2){
            num2 = '0'+num2;
            ++len_num2;
        }
        for(int i = len_num1-1;i>0;i--){
            num1[i] = num1[i] - '0' + num2[i];
            if((num1[i]-'0')>=10){
                num1[i] = (num1[i]-'0')%10+'0';
                num1[i-1] = num1[i-1]+1;
            }
        }
        num1[0] = num1[0] - '0' +num2[0];
        if((num1[0]-'0')>=10){
            num1[0] = (num1[0]-'0')%10+'0';
            num1 = '1' + num1;
        }
        return num1;
    }
};
```