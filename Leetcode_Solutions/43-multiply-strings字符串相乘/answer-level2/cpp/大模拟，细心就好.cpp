### 解题思路


### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0")
            return num1;
        if(num2 == "0")
            return num2;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());  //为了方便运算
        if(num1.length() > num2.length())   //保证短的在前面
            swap(num1, num2);
        string ans = "", temp = "";
        for(int i = 0 ; i < num1.length() ; ++i)
        {
            int carry = 0;
            temp = "";
            for(int j = 0 ; j < num2.length() ; ++j)
            {
                int multi = (num1[i] - '0') * (num2[j] - '0');  //计算num1第i个数与整个num2的乘积
                multi += carry;
                if(multi >= 10)
                {
                    carry = multi / 10;
                    multi %= 10;
                }
                else
                    carry = 0;
                if(i == 0)
                    ans += multi + '0';
                else
                    temp += multi + '0';
            }
            if(i == 0 && carry)
                ans += carry + '0';
            else if(i > 0 && carry)
                temp += carry + '0';
            cout<<ans<<" "<<temp<<endl;
            if(i > 0)   //累加乘积
            {
                carry = 0;
                int j = i, k = 0;
                while(j < ans.length() && k < temp.length())
                {
                    int tempNum = ans[j] - '0' + temp[k] - '0' + carry;
                    if(tempNum >= 10)
                    {
                        carry = 1;
                        tempNum %= 10;
                    }
                    else
                        carry = 0;
                    ans[j] = tempNum + '0';
                    j++;
                    k++;
                }
                while(k < temp.length())
                {
                    int tempNum = temp[k] - '0' + carry;
                    if(tempNum >= 10)
                    {
                        carry = 1;
                        tempNum %= 10;
                    }
                    else
                        carry = 0;
                    ans += tempNum + '0';
                    k++;
                }
                if(carry)
                    ans += carry + '0';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```