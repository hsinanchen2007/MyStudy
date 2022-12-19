### 解题思路
仅供学习娱乐，完全不使用类型转换

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int d1,d2=0;
        string digit;
        string res;
        int carry = 0;
        while(l1 || l2){
            if(l1>0){
                l1--;
                d1 = num1[l1]-'0';
            }
            else d1 = 0;
            if(l2>0){
                l2--;
                d2 = num2[l2]-'0';
            }
            else d2 = 0;
            digit = (d1+d2+carry>= 10)? to_string(d1+d2+carry-10) : to_string(d1+d2+carry);
            res = digit + res;
            //cout<<res<<" "<<carry<<endl;
            carry = (d1+d2+carry)/10;
        }
        if(carry == 1){
            res = to_string(carry) + res;
        }
        return res;
    }
};
```