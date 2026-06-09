### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int a[300]={0};
        int res=0;
        int flag=0;
    for(int i=0;i<s.size();i++){
        a[s[i]]++;
    }
    for(int j=0;j<sizeof(a)/sizeof(a[0]);j++){
        if(a[j]%2!=0) flag=1;
            res+=a[j]/2*2;
        }
    return res+flag;
    }
};
```