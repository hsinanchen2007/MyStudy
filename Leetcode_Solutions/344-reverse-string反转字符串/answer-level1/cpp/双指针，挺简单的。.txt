### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;

        for(int i=0,j=s.size()-1;i<j;i++,j--) swap(s[i],s[j]);
        
    }
};
```