菜鸡根本不会字典树，只是想到短的字符串里肯定不可能有长的字符串，所以肯定是要在长的字符串里寻找短的字符串，所以需要先排个序。如果在S中没找到当前字符串，就把words[i]+"#"接到S后，最后输出S的大小。
刚开始因为偷懒不想写比较函数错了两次，写比较函数了之后提交发现又错了，然后才意识到**不应该S.find(words[i])，而应该S.find(words[i]+"#")** 


```cpp
class Solution {
public:
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        string S;
        sort(words.begin(), words.end(), cmp);
        for(int i=0; i<words.size(); i++)
        {
            if(S.find(words[i]+"#") == string::npos)
            {
                S += words[i] + "#";
            }
        }
        return S.size();
    }
};
```

执行用时 :804 ms, 在所有 C++ 提交中击败了18.19%的用户
内存消耗 :12.5 MB, 在所有 C++ 提交中击败了83.16%的用户