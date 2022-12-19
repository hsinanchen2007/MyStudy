### 解题思路
假设str1是N个x，str2是M个x，那么str1+str2肯定是等于str2+str1的。
之后用辗转相除法求最大公因子的长度。也就是str1的长度和str2长度的最大公约数。
### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b){
        if(a % b == 0) return b;//最大的就是b
        return gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1){
            return "";
        }
        int maxlen = gcd(str1.length(),str2.length());
        return str1.substr(0,maxlen);
    }
};
```