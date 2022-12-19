### 解题思路
My solution：（long time no see c++）
count来记录总的长度之和，用words<vector>中的每一个字符串去和chars匹配，匹配成功增加当前words的长度给count，不匹配则不记录。
匹配的方法如下：拿到一个具体的words[i]后，取words[i]的第一个元素拿到chars中遍历，匹配到就将chars当前位置元素置空，并break掉该循环（关键）。
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       int count=0;
       for(int i=0;i<words.size();i++)
       {
           int p = 0;
           string temp = chars;
           string t = words[i];
           for(int j=0;j<t.size();j++)
           {
               for(int k=0;k<temp.size();k++)
               {
                   if(t[j]==temp[k])
                   {
                       temp[k]=' ';
                       p++;
                       break;
                   }
               }
           }
           if(p==t.size())
           {
               count+=t.size();
           }
       }
       return count;
    }
};
```