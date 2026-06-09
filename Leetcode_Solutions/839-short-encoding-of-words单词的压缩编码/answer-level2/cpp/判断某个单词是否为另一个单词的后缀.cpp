如果某单词是后缀，那么该单词就不用存储

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
            unordered_set<string>  sp;
            sp.insert(words.begin(),words.end());  //存储所有单词
            for(const string &s :words)
            {
                for(int k=1;k<s.size();k++)
                sp.erase(s.substr(k));  //如lite.substr(1)===>ite.如果该单词的某个后缀单词在sp中，则把它删除掉

             }

      int res=0;
      for(const string &s:sp)
      {
          res+=s.size()+1;  //+1====>加分隔符#
      }
return res;

    }
};
```