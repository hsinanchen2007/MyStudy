### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string res="";
      int cont=0;
      for(int i=0;i<=S.size();i++)
      {   if(i==0)cont=1;
          else if(S[i]==S[i-1])cont++;
          else {
               res+=S[i-1]+to_string(cont);
               cont=1;
          }
      }
      return res.size()<S.size()?res:S;
    }
};
```