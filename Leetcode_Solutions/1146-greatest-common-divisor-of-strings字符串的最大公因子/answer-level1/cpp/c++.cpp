### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2)!=(str2+str1)) return "";
        else{
            int a= gcd(str1.length(),str2.length());
            return str1.substr(0,a);
        }
    }
    int gcd(int i, int j){
        if(j==0) return i;
        else return gcd(j,i%j);
    }
};
```