### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了62.55% 的用户
内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

我发现dfs理解起来很简单，我的测试用例一下子就过了很多。因为有一个用例爆TLE，所以增加了对于是否判断过的剪枝。应该会很快。 
根据我学的编程语言，我先把regex处理成一个token array这样我就不用重复去判断这个事情。

大致的思路：
token包含两个部分，一个是这个字母，另一个是这个字母可以不可以重复出现。如果可以重复出现，这个字母实际上是可以跳过的。
我用注释解释一下dfs部分在干什么就很清晰了。


### 代码

```cpp
class Solution
{
public:
    bool dfs(const string &s, const vector<pair<char, bool>> &tokens, int i, int j)
    {
        // 是否访问过该节点
        if (visited[i][j])
            return false;
        visited[i][j] = true;

        // 边界条件
        if (i == s.length() || j == tokens.size())
            // 没有更多的字符，并且剩余的token都是*，都可以跳过，那么我们可以说这个表达式是有效的。
            return i == s.length() && (j == tokens.size() || all_of(tokens.begin() + j, tokens.end(), [](const pair<char, bool> &el) { return el.second; }));

        // 如果这个token是可以多匹配，那么我们可以跳过这个，直接从下个字母开始匹配
        // 如果从下个字母成功匹配， 那么我们可以说这个匹配是成功的（因为这个字母可以跳过）
        if (tokens[j].second && dfs(s, tokens, i, j + 1))
            return true;
        // 尝试匹配这个字母和这个token
        else if (s[i] == tokens[j].first || tokens[j].first == '.')
            // 匹配成功，我们尝试匹配下个字母和下个token
            // 如果这个字母是多匹配的，那么我们也可以用这个token来匹配下个字母
            return dfs(s, tokens, i + 1, j + 1) || (tokens[j].second && dfs(s, tokens, i + 1, j));

        return false;
    }
    bool isMatch(string s, string p)
    {
        // 初始化token array
        auto token = getTokens(p);
        // 创建一个全空的visited的array
        visited = vector<vector<bool>>(s.length() + 1, vector<bool>(token.size() + 1, false));
        // 深度优先搜索，第一个是原字符串，第二个是生成你的token array， 初始条件， s的index和token array的index
        return dfs(s, token, 0, 0);
    }
    vector<pair<char, bool>> getTokens(string p)
    {
        // deque比vector在push_back上效率高，因为vector会触发malloc
        deque<pair<char, bool>> ret;
        for (int i = 0; i < p.length(); i++)
        {
            if (i + 1 < p.length() && p[i + 1] == '*')
                // 这个字符的下个字符是*，说明这个token是多匹配的，并且下个字符不是token不参与比较。
                ret.push_back({p[i++], true});
            else
                // 这个token一定要对应s里的一个字符
                ret.push_back({p[i], false});
        }
        return vector<pair<char, bool>>(ret.begin(), ret.end());
    }

private:
    vector<vector<bool>> visited;
};
```