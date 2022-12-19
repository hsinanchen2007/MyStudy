### 解题思路
只需考虑之前最近的通配符需要回溯的情况。

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
         
         int i = 0;
         int j = 0;
         int lasti = -1;
         int lastj = -1;
         int n = p.length();
         while(i<s.length() ){
            
             if(j<n && (s[i] == p[j] || p[j] == '?') ){
                 i++;
                 j++;
             }else if(j<n && p[j] == '*'){
                j++;
                if(j==n){
                    return true;
                }
                 lasti = i+1;
                 lastj = j;
             }else if(lasti != -1){
                    i = lasti++;
                    j = lastj;
             }else{
                     return false;
             }    
         }
   

         while(j<n && p[j] == '*'){
             j++;
         }

         return j==n;
    }
};
```