### 解题思路
有点捞，思路简单，效率低；
### 代码

```cpp
class Solution {
public:
    static bool cmp(string& str1, string& str2)
    {
        return str1.size() > str2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        //按照字符串大小进行排序，保证子串在父串之后；
       sort(words.begin(),words.end(), cmp);
       string tmp;
       for(auto&e : words)
       {
           e += '#';
           if(!tmp.empty())
           {
                int index = tmp.find(e);
                //e不再tmp中
                if(index == string::npos)
                {
                     tmp += e;
                }
           }else
           {
               //首次插入
               tmp += e;
           }
       } 
       return tmp.size();
    }
};
```