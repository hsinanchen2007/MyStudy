### 解题思路
同67、989题类似

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int a=num1.size();int b=num2.size();
        while(a<b){
            num1='0'+num1;
            a++;
        }
        while(a>b){
            num2='0'+num2;
            b++;
        }
        string str=num1;//很关键，不要对控制符串操作
        int carry=0;
        for(int i=a-1;i>=0;i--){
            int sum=num1[i]-'0'+num2[i]-'0'+carry;
            str[i]=sum%10+'0';
            carry=sum/10;
        }
        if (carry>0) str=to_string(carry)+str;
        return str;
    }
};
```