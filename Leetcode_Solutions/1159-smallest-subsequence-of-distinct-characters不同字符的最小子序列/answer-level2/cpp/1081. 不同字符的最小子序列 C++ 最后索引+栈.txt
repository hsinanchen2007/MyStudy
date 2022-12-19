### 解题思路
要满足两个条件：
1.最小子序列
2.每个字符都出现一次

因此，我们利用栈思想：
1）用map获得字符最后一次出现的位置i；
2）栈中字符小于第i个字符，且栈中字符在i后面仍然存在时，可以将栈中字符弹出；
3）将当前字符压入栈；

对于栈中已有的重复字符，由于当前栈中已经是最小排序，因此，重复字符需要丢弃；

确保

### 代码

```cpp
class Solution {
public:
    string smallestSubsequence(string text)
    {
        unordered_map<char, int> indexmap;
        unordered_set<char> charset;
        string result;
        for (int i = 0; i < text.size(); i++) {
            indexmap[text[i]] = i;
        }

        for (int i = 0; i < text.size(); i++) {
            if (charset.count(text[i])) {
                continue;
            }

            while (!result.empty() && text[i] < result.back() && i < indexmap[result.back()]) {
                charset.erase(result.back());
                result.pop_back();
            }

            result.push_back(text[i]);
            charset.insert(text[i]);
        }

        return result;
    }
};
```