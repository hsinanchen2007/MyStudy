## [Trie匹配后缀](https://leetcode-cn.com/problems/short-encoding-of-words/)
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 `["time", "me", "bell"]`，我们就可以将其表示为 `S = "time#bell#"` 和 `indexes = [0, 2, 5]`。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

### 题目分析
要让索引字符串长度最小，就要尽量利用单词的公共部分。

一个单词时另一个单词的前缀时，不能缩短索引字符串长度
```
bell
be
be#bell#
```
发现只有一个单词是另一个单词的后缀时，才能缩短索引字符串长度
```
time
me
time#
```
所以，对于每一个单词，我们希望找到以它为后缀的另一个单词，如果能找到，就能够将这两个单词叠加起来，不需要增加额外长度。

### 暴力$O(n^2)$
先按单词长度从大到小排序，从第二个单词开始遍历，判断当前单词是否为之前的某一个单词（长度大于等于当前单词）的后缀  
如果是，索引字符串长度不变  
如果不是，索引字符串长度加上当前单词长度再加1`word#`
```cpp
class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return a.length() > b.length();
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        ans += words[0].length() + 1;
        for (int i = 1; i < words.size(); i++)
        {
            // cout << words[i] << endl;
            bool ismatch = 0;
            int len = words[i].size();
            for (int j = i - 1; j >= 0; j--)
            {
                if (words[j].compare(words[j].size() - len, len, words[i]) == 0)
                {
                    ismatch = 1;
                    break;
                }
            }
            if (!ismatch)
            {
                ans += len + 1;
            }
        }
        return ans;
    }
};
```
### Trie $O(?)$ 反正比暴力快
求一个单词的后缀=求这个单词反过来之后的前缀  
这不是可以用Trie吗？

还是要先按单词长度从大到小排序，再将倒置的单词一个个加入到Trie中  
如果不这么做，`me`先被加到树中，不能被`time`匹配到

如果当前单词是某一单词的前缀，那么当前单词肯定在Trie中  
如果不是，就更新Trie
```cpp
class Trie
{
private:
    bool isEnd;
    Trie *nxt[26];

public:
    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = nullptr;
        }
    }

    bool searchPrefixAndInsert(string s)
    {
        auto node = this;
        bool match = 1;
        for (auto ch : s)
        {
            if (!node->nxt[ch - 'a'])
            {
                node->nxt[ch - 'a'] = new Trie;
                match = 0;
            }
            node = node->nxt[ch - 'a'];
        }
        return match;
    }
};
class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie *root = new Trie();
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        for (auto word : words)
        {
            reverse(word.begin(), word.end());
            if (!root->searchPrefixAndInsert(word))
                ans += word.size() + 1;
        }
        return ans;
    }
};
```