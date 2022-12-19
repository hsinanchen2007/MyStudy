### 解题思路
此处撰写解题思路
全网最土的方法
执行用时 :704 ms, 在所有 C++ 提交中击败了21.24% 的用户
内存消耗 :276.8 MB, 在所有 C++ 提交中击败了15.79%的用户
### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string S ="";
        if(words.size() == 1)
           return words[0].size()+1;
        else
        {
            sort(words.begin(), words.end(), [](string &a, string &b)
            {  return a.size() > b.size();  });
            for(int i =0;i<words.size();i++)
               { 
                    string::size_type index;
                    index=S.find(words[i]+"#");
                    if(index == string::npos)  //未找到
                        S=S+words[i]+"#";
                }
            return S.size();
        }
    }
};
```