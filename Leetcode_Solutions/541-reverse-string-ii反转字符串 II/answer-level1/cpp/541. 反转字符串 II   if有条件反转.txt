### 解题思路
也就是在i+k<s.length()就可以反转，即剩余长度大于k，那么即使+2k之后跑出循环了，依然已经换完了
剩余长度小于k，直接全反转

### 代码

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+=2*k){
            if(i+k<s.length()){
               reverse(s.begin() + i, s.begin() + i + k);
            }
            else
                 reverse(s.begin() + i, s.end());
            }
            return s;
        }
    
};



```