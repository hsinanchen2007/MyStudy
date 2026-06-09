### 解题思路
这道题实际上是统计字符出现频率然后按照出现次数从高到低重新排列。我们首先就能想到hashMap和优先队列priority_queue<int,char>的方法。
首先hashMap统计字符出现频率，其次用优先队列priority_queue最大堆。
最后，从堆顶弹出对子，用string函数 append（char，count）构造字符串。

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto a : m) q.push({a.second, a.first});
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
};
```