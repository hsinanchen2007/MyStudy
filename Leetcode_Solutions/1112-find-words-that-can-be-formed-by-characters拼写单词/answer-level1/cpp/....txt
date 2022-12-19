### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      vector<int>char_count=count(chars);
      int res=0;
      for(string&word:words)
      {
          vector<int>word_count=count(word);
          if(contains(char_count,word_count))
           res+=word.size();
      }
      return res;
    }
    bool contains(vector<int>&cha,vector<int>&word)
    {
           for(int i=0;i<26;i++)
           {
               if(word[i]>cha[i])
               return false;
           }
           return true;
    }
    vector<int> count(string& char1)
    {
      vector<int>counter(26,0);
      for(char c:char1)
      counter[c-'a']++;   return counter;
    }
 
};
```