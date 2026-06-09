### 解题思路
奇数偶数分解

### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        string res = "";
       if (n==0) return res;
       if (n&1) {
           res += "a";
           for (int i=0; i<n-2; i++){
               res += "b";
           }
           if (n!=1) res += "c";
       }else{
           res += "a";
           for (int i=0; i<n-1; i++){
               res += "b";
           }
       }
       return res;
    }
};
```