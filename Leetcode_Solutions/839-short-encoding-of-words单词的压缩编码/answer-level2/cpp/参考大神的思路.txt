### 解题思路
先将每个单词逆序，之后对words排序，比较相邻两个单词，前一个是否与后一个的前n个字符相等即可。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(string &s : words){
            reverse(s.begin(),s.end());
        }
        sort(words.begin(),words.end());

        int res = 0;
        for(int i = 0; i < words.size() - 1; i++){
            int n = words[i].size();
            if(words[i] == words[i + 1].substr(0,n))
                continue;
            res += n + 1;
        }
        //for(int i = 0; i < words.size(); i++)
       // cout<<words[i];
        return res + words.back().size() + 1;
    }
};
```