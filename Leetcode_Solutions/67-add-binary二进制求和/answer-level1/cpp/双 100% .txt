### 解题思路
先补全两个字符串较短的一个，即前面补全'0',方便计算；采用carry标记每一位计算是否进位,res为返回的结果字符串，sum记录每一位相加的结果；最后结果需要判断res[0]这一位是否进位，若进位则在res[0]前加一个'1',否则的话直接返回res。代码如下

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
     int i,carry = 0,sum = 0,a_len = a.size(),b_len = b.size();
     while(a_len < b_len)
     {
         a = '0'+a;
         ++a_len;
     }
     while(b_len < a_len)
     {
         b = '0'+b;
         ++b_len;
     }
     string res(a_len,'0');
     i = a_len-1;
     while(i>=0)
     {
         sum = a[i]+b[i]-'0'-'0'+carry;
         carry = sum/2;
         res[i] = sum%2+'0';
         i--;
     }
     if(carry > 0)
        return '1'+res;
     else
     return res;
    }
};
```