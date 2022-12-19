### 解题思路
双指针i，j 判断首先分两种情况：
1、s[i]!=s[j] 则前面的指针i++;直到i<j不成立
2、s[i]=s[j]  则长度为j-i

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        if(s.size()==2) { if(s[0]==s[1]) return 1;else return 2;}
        int i=0,j=1;
        int maxlength=0;
        for(;j<s.size();) {
            int l_i=i;
            for(;l_i<j;) {
                if(s[l_i]==s[j]) {
                    maxlength=max(maxlength,j-i);
                    i=l_i+1;
                    j++;
                    break;
                }
                else {
                    l_i++;
                }
            }
            if(l_i==j&&j==s.size()-1) {
              maxlength=max(maxlength,j-i+1);  
              break;
            }
            else if(l_i==j) {
                j++;
            }
        }
        return maxlength;
    }
};
```