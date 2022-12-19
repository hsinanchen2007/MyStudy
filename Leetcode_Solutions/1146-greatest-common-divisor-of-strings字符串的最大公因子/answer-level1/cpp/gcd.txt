### 解题思路
gcd

### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b)
    {
        while(a!=0&&b!=0)
        {
            a=a%b;
            if(a==0) break;
            swap(a,b);
        }
        return b;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        else
        {
            int res=gcd(str1.size(),str2.size());
            return str1.substr(0,res);
        }
    }
};
```