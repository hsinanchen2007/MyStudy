### 解题思路
此处撰写解题思路
最笨的办法，三重循环。。。每个单词的每个字母和字母表中每个词比较

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
     if(!words.empty()&&!chars.empty())
     {
      string::iterator it;
     // string s;
     string com=chars;
     string temp;
     int num,sum=0;
      bool check[chars.length()];
      for(int i=0;i<words.size();i++)
       {
        //  s=words[i];
          for(int j=0;j<words[i].size();j++)
          {
              for(int k=0;k<chars.length();k++)
              {
                  if(words[i][j]==chars[k])
              {
                  it=chars.begin()+k;
                 chars.erase(it);
                  num++;
          //        temp=chars;
                  break;
              }
              else continue;
              }
           
          }

       if(num==words[i].size())
       {   sum+=num;
           chars=com;
           num=0;
           continue;
       }
       else 
       {
        num=0;  
        chars=com; 
       }
       }
       return sum;
     }
    else return 0;
    }
};
```
