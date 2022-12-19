### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       int res=0;
       unordered_map<char,int> count;
       for(char c:chars)
       {
           ++count[c];
       }
       for(auto word:words)
       {
          unordered_map<char,int> wordcount;
          for(char c:word)
          {
              ++wordcount[c];
          } 
          bool isans=true;
          for(char c:word)
          {
              if(count[c]<wordcount[c])
              {
                  isans=false;
                  break;
              }
          }  
          if(isans) res+=word.length();        
       }
       return res;
    }
};

```