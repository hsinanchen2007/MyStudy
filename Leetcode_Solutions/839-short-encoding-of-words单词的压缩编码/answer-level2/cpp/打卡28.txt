### 解题思路
 直接暴力，一开始没把后缀保留下来，而且一个一个的对比过去。超时了，所以就尝试了把后缀保留下来，看是否是之前的字符串的后缀。如果是就跳过，否则把后缀留下了。
  为了保证后面的字符串要不就是前者的后缀，要不就是。因此，需要把字符串从长到短排序。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        if(n == 0)return 0;
        if(n == 1)return words[0].size() + 1;
        sort(words.begin() , words.end() , [](const string a , const string b){
            return a.length() > b.length();
        });
        int s = 0;
        map<string,int> m;
        for(auto x : words){
            int t = x.length();
            if(m[x])continue;
            s += t + 1;
            for(int i = 0 ; i < t - 1 ; i++){
                m[x.substr(i , t - i)] = 1;
            }
        }
        return s;
    }

};
```