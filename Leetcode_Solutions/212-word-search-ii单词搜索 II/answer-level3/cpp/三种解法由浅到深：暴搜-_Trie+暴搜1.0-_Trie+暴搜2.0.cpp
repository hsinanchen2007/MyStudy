## [Trie+回溯](https://leetcode-cn.com/problems/word-search-ii/description)
三种解法:  
1. 暴搜
2. Trie+回溯，结合程度低
3. Trie+回溯，结合程度高

### 暴搜TLE
枚举每个在字典中的单词，枚举每个出发点
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool visited[105][105];
    vector<string> ans;
    bool match;
    void dfs(int x, int y, string nowWord, string finalWord, vector<vector<char>> &board)
    {
        if (match)
            return;
        if (nowWord == finalWord)
        {
            ans.push_back(nowWord);
            match = 1;
            return;
        }
        visited[y][x] = 1;
        for (auto dir : dire)
        {
            int nxt_x = x + dir[0];
            int nxt_y = y + dir[1];
            if (nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n)
            {
                if (!visited[nxt_y][nxt_x])
                {
                    char nxt_ch = finalWord[nowWord.size()];
                    if (board[nxt_y][nxt_x] == nxt_ch)
                    {
                        string nxtWord = nowWord + nxt_ch;
                        dfs(nxt_x, nxt_y, nxtWord, finalWord, board);
                        visited[nxt_y][nxt_x] = 0;
                    }
                }
            }
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        n = board.size();
        m = board[0].size();
        for (auto word : words)
        {
            match = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == word[0])
                    {
                        string nxtWord(1, word[0]);
                        dfs(j, i, nxtWord, word, board);
                        visited[i][j] = 0;
                    }
                    if (match)
                        break;
                }
                if (match)
                    break;
            }
        }
        return ans;
    }
};
```
### 结合不紧密的Trie+回溯
基本等于在暴搜的基础上加上Trie模板  
用Trie来帮助暴搜剪枝

1. 不需要枚举每个在字典中的单词，直接搜索当前单词是否在字典中即可
2. 搜索当前单词是否是字典中某个单词的前缀，如果不是就可以剪枝`return`

这里有个很容易错的小细节:  
找到匹配的单词后不能`return`，因为可能有以当前单词为前缀的其他单词，如果`return`就不能找到它们了
```
e.g.
dict={"ab","abc"}
board={"a","b","c"}
如果找到"ab"的时候直接return，"abc"就永远不可能被匹配到
```

另外一个优化的点：  
题意只需要求出现的单词，不要重复的，与其用`unordered_map`这类东西来去重，不如直接在Trie中改动一下。  
在匹配单词的函数中这样写，就能使每个单词只出现一次。
```cpp
if (node->isEnd)
{
    node->isEnd = 0;
    return true;
}
```
```cpp
if (root->searchWord(nowWord))
{
    ans.push_back(nowWord);
    // return;
}
if (!root->startWith(nowWord))
{
    return;
}
```
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Trie
{
public:
    bool isEnd;
    Trie *nxt[26];
    Trie()
    {
        isEnd = 0;
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = nullptr;
        }
    }
    void insert(string word)
    {
        Trie *node = this;
        for (char each : word)
        {
            if (!node->nxt[each - 'a'])
            {
                node->nxt[each - 'a'] = new Trie();
            }
            node = node->nxt[each - 'a'];
        }
        node->isEnd = 1;
    }

    bool startWith(string word)
    {
        Trie *node = this;
        for (char each : word)
        {
            if (!node->nxt[each - 'a'])
            {
                return false;
            }
            node = node->nxt[each - 'a'];
        }
        return true;
    }

    bool searchWord(string word)
    {
        Trie *node = this;
        for (char each : word)
        {
            if (!node->nxt[each - 'a'])
            {
                return false;
            }
            node = node->nxt[each - 'a'];
        }
        // find the word and delete it
        if (node->isEnd)
        {
            node->isEnd = 0;
            return true;
        }
        return false;
    }
};
class Solution
{
public:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool visited[105][105];
    Trie *root;
    vector<string> ans;
    void dfs(int x, int y, string nowWord, vector<vector<char>> &board)
    {
        if (root->searchWord(nowWord))
        {
            ans.push_back(nowWord);
            // return;
        }
        if (!root->startWith(nowWord))
        {
            return;
        }
        for (auto dir : dire)
        {
            int nxt_x = x + dir[0];
            int nxt_y = y + dir[1];
            if (nxt_x >= 0 && nxt_x < n && nxt_y >= 0 && nxt_y < m)
            {
                if (!visited[nxt_x][nxt_y])
                {
                    string nxtWord = nowWord + board[nxt_x][nxt_y];
                    visited[nxt_x][nxt_y] = 1;
                    dfs(nxt_x, nxt_y, nxtWord, board);
                    visited[nxt_x][nxt_y] = 0;
                }
            }
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        n = board.size();
        m = board[0].size();
        root = new Trie();
        for (auto word : words)
        {
            root->insert(word);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                string nowWord(1, board[i][j]);
                visited[i][j] = 1;
                dfs(i, j, nowWord, board);
                visited[i][j] = 0;
            }
        }
        return ans;
    }
};
```
### 结合紧密的Trie+回溯
[推荐看这位大佬用`hashmap`的题解以及下面评论区使用一般前缀树的代码](https://leetcode-cn.com/problems/word-search-ii/solution/cqian-zhui-shu-ju-ta-ma-rong-yi-dong-by-chashao/)

[再看看官方题解里面给出的优化建议](https://leetcode-cn.com/problems/word-search-ii/solution/dan-ci-sou-suo-ii-by-leetcode/)

有了Trie,怎么进一步优化我们的搜索回溯呢？

答案就是直接把Trie的节点作为一个状态，放到搜索里面。

+ 判断单词是否匹配？ 看`now->isEnd==1`
+ 判断当前字符串是否是某一单词的前缀？ 看`now->nxt[board[x][y] - 'a'] == nullptr`
+ 下一个位置的字符串是？ `now = now->nxt[board[x][y] - 'a']`

另外，这里的搜索写法与之前差别比较大，而且把`visited[][]`砍掉了。
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Trie
{
public:
    bool isEnd;
    Trie *nxt[26];
    string word;
    Trie()
    {
        isEnd = 0;
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = nullptr;
        }
        word = "";
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char each : word)
        {
            if (node->nxt[each - 'a'] == nullptr)
            {
                node->nxt[each - 'a'] = new Trie();
            }
            node = node->nxt[each - 'a'];
        }
        node->isEnd = 1;
        node->word = word;
    }
};
class Solution
{
public:
    vector<string> ans;
    void dfs(Trie *now, int x, int y, vector<vector<char>> &board)
    {
        if (now->isEnd)
        {
            now->isEnd = 0;
            ans.push_back(now->word);
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;
        if (board[x][y] == '#')
            return;
        if (now->nxt[board[x][y] - 'a'] == nullptr)
            return;
        now = now->nxt[board[x][y] - 'a'];
        char cur = board[x][y];
        board[x][y] = '#';
        dfs(now, x + 1, y, board);
        dfs(now, x - 1, y, board);
        dfs(now, x, y + 1, board);
        dfs(now, x, y - 1, board);
        board[x][y] = cur;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = new Trie();
        for (auto word : words)
        {
            root->insert(word);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(root, i, j, board);
            }
        }
        return ans;
    }
};
```
### 这道题的一些延伸思考
### `nullptr`
c++11 推出的东东，表示一个空指针  
反正记住比`null`好用就对了  

[为什么建议你用nullptr而不是NULL](https://zhuanlan.zhihu.com/p/79883965)
### `a[x][y]`or`a[y][x]`
在数学里面，`(x,y)`看起来更顺眼哎

但是如果我们把数学里面的坐标系放到二维数组中来看，发现有点不对劲
```
a=[   1 2 3
   
   1 [1,2,3],
   2 [4,5,6],
   3 [7,8,9]
]
```
如果按照数学中的坐标系，第y行第x列对应的数组元素是`a[y][x]`

但是`y`在`x`前面又有点不太舒服，`a[x][y]`看起来更自然

其实两种写法都可以，关键是你要想明白`x`代表的是行数或是列数

现在发现`a[x][y]`更好一点，因为很多时候函数返回值是`(x,y)`，`unpack`不容易出错
### 搜索回溯的不同写法
1. 先进入下一个状态再判断合法性
2. 先判断下一个状态的合法性再进入

个人感觉各有千秋吧

第一种写法代码会更简洁，而且不用考虑`dfs(0,0)`搜索入口的状态

第二种写法递归调用会少一点，效率会高？（不太清楚）但是要考虑搜索入口的状态 

以该题为例：
```cpp
第一种写法的搜索入口
dfs(root, i, j, board);

第二种写法的搜索入口
string nowWord(1, board[i][j]);
visited[i][j] = 1;
dfs(i, j, nowWord, board);
visited[i][j] = 0;
```
第一种写法逻辑确实清晰很多，递归边界直接用`if return`就可以，增减逻辑都方便