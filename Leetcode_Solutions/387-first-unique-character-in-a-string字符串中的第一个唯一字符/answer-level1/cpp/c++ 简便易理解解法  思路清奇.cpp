### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
      int dist[26]={0};
      for(char i:s){
          dist[i-'a']++;
      }
      for(int i=0;i<s.length();i++){
          if(dist[s[i]-'a']==1){
              return i;
              }
      }
      return -1;
    }
};
```