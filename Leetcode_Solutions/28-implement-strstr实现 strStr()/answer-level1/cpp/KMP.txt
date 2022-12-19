### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
  vector<int>getNext(string pattern){
    vector<int> next(pattern.length(),0);
    int j=0;
    for(int i=2;i<pattern.length();i++){
      while(j!=0&&pattern[j]!=pattern[i-1])
        j=next[j];
      if(pattern[j]==pattern[i-1])
        j++;
      next[i]=j;
    }
    return next;
  }
public:
    int KMP(string str,string pattern){
      vector<int>next=getNext(pattern);
      int j=0;
      for(int i=0;i<str.length();i++){
        while(j!=0&&str[i]!=pattern[j])
          j=next[j];
        if(str[i]==pattern[j])
          j++;
        if(j==pattern.length())
          return i-pattern.length()+1;
      }
      return -1;
    }
    int strStr(string haystack, string needle) {
      if(!needle.length()) return 0;
      if(needle.length()==1){
        char ch=needle[0];
        int i=0;
        while(i<haystack.length()){
          if(ch==haystack[i]) return i;
          i++;
        }
        if(i==haystack.length())
          return -1;
      }
      return KMP(haystack,needle);
    }
};
```