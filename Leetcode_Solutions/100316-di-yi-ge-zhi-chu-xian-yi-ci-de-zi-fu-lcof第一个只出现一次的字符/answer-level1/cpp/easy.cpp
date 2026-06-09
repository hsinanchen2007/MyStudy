### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> d(128,0);
        int i=0,j=0;
        for(int i=0;i<s.length();i++){
            d[s[i]]++;
            while(d[s[j]]>1)j++;
        }
        if(j<s.length())return s[j];
        return ' ';
    }
};
```