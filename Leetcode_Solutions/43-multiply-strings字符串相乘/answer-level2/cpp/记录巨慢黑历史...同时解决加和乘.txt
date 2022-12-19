### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2){
        int l1 = num1.size();
        int l2 = num2.size();
        int d1,d2 = 0;
        string digit;
        string product = "0";
        string res;
        int carry = 0;
        for (int i = l1 - 1; i >= 0; i--) {
            int timesten = l1-1-i;
            for (int j = l2 - 1; j >= 0; j--) {
                d1 = num1[i]-'0';
                d2 = num2[j]-'0';
                digit = (d1*d2+carry>= 10)? to_string((d1*d2+carry)%10):to_string(d1*d2+carry);
                res = digit + res;
                carry = (d1*d2+carry)/10;
            }
            if(carry != 0){
            res = to_string(carry) + res;
            }
            for (;timesten > 0;timesten--){//add 0 to the tail for each round
                res = res + "0"; 
            }
            cout<<res<<endl;
            product = stringadd(res, product);
            res = "";//clear for next round
            carry = 0;//clear for next round
        }
        if(product[0]=='0')return "0";//consider multiple 0 due to mechanism
        return product;
    }
    string stringadd(string num1, string num2) {
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