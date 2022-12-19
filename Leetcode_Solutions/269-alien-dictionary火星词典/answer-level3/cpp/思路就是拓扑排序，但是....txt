## 大概思路

`words` 中每个单词 `words[i]` 都可以和 `words[i-1]` 相比较，如果二者不同，就肯定可以得到一个 `pair<char, char> entry` ，表示 `entry.first` 一定会排在 `entry.second` 前面。

例如：`[wrt, wrf, ...]` 的前两个元素就可以得出 `{t, f}`，因为在这个外星语言中，`t` 肯定小于 `f`，也就是说排在 `f` 前面。

如果两个元素相同，那自然就得不到了，跳过就好。
我们遍历一遍所有的元素，就能得到一个有向图。然后在这个基础上做拓扑排序。
拓扑排序的思路就不多说了，个人偏向用 BFS，入度表 + 队列。

## 问题1 - 所有出现过的 char 都要出现在最后结果中

这里有一个大坑。题目说的是：

> 您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

但实际上，即使你不确定的顺序，也需要加进去。

例如，我的有向图中有两个 cluster，

```
a < b < c
d < e
```

此时我只能确定 abc 的相对顺序，或者 de 的相对顺序。我以为随便选一串输出就好，但实际商要求的答案是，你要把这两个串搞在一起。至于怎么搞就无所谓了，反正要搞在一起。

```
错误： "abc"
正确： "deabc" or "abcde" or "abdce"
```

再比如，输入是 `words = [zab]`。没了。此时，你需要把 `z`, `a`, `b` 这三个字符也都搞在一起，随便输出一个 `zab` 的排列。

如何处理这个问题？把每个 `words` 元素的每个字母都搞到一个 `allNodes` 里面。做拓扑排序初始化队列的时候，从这个 `allNodes` 里面选。

## 问题2 - 如何判断输入顺序是否非法

按照开始所说的思路生成 `pair`，如果输入非法，肯定会出现环。
如果在拓扑排序遍历的过程中，无法访问到所有的 char，那么肯定是有环了。
所以，得到最后的字符串以后，和 `allNodes.size()` 比较一下。如果对不上，就返回空字符串。

## 代码

```c++
class Solution {
public:
  string alienOrder(vector<string>& words) {
    vector<int> inDegrees(26, 0);
    vector<vector<char>> dependency(26, vector<char>());
    unordered_set<char> allNodes(words[0].begin(), words[0].end());
    set<pair<char, char>> seen;
    for (int i = 1; i < words.size(); ++i) {
      const string& first = words[i-1];
      const string& second = words[i];
      allNodes.insert(second.begin(), second.end());
      int len = min(first.size(), second.size());
      int j = 0;
      while (j < len && first[j] == second[j]) ++j;
      if (j == len) continue;
      pair<char, char> entry = {first[j], second[j]};
      if (seen.count(entry)) continue;
      seen.insert(entry);
      ++inDegrees[entry.second - 'a'];
      dependency[entry.first - 'a'].push_back(entry.second);
    }

    // Topo Sort.
    queue<char> todo;
    for (char x : allNodes)
      if (inDegrees[x - 'a'] == 0)
        todo.push(x);

    string res;
    res.reserve(allNodes.size());
    while (!todo.empty()) {
      char cur = todo.front();
      todo.pop();
      res.push_back(cur);
      for (char dep : dependency[cur - 'a']) {
        --inDegrees[dep - 'a'];
        if (inDegrees[dep - 'a'] == 0)
          todo.push(dep);
      }
    }
    if (res.size() != allNodes.size()) return "";
    return res;
  }
};
```