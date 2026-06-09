### 解题思路
这是easy的难度吗。。。。

### 代码

```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans = "";
        for(auto s:words)
        {
            int len = s.length();
            int now = 0;
            int flag = true;
            for(int i = 0 ; i < len ; ++i)
            {
                if(Trie[now].nxt[s[i] - 'a'] == 0)
                {
                    if(i < len - 1) //如果最后一个字符之前的字符没有匹配到
                    {
                        flag = false;
                        break;
                    }
                    Trie[now].nxt[s[i] - 'a'] = ++nodecnt;
                    now = nodecnt;
                }
                else
                {
                    now = Trie[now].nxt[s[i] - 'a'];
                }
            }
            if(flag && s.length() > ans.length())
                ans = s;
        }
        return ans;
    }

private:
    struct trie
    {
        int nxt[26];
    };
    trie Trie[10005];
    int nodecnt = 0;
};
```