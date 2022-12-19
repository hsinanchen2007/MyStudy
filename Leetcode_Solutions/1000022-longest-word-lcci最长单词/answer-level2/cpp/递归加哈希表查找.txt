### 解题思路
- 使用哈希集合存储列表中的每一个单词，接着遍历列表的中的每个单词判断其是否由其他单词组合而成
- 递归查找时，因为不能由其自身组成，因此每次从哈希集合中删除其自身
- 递归分割查找每一种可能，当一种分割到空串时，返回`true`，所有的情况遍历完毕，返回`false`

### 代码

```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> allWords(words.begin(), words.end());
        string ans;
        for(auto word:words)
        {
            auto tmpCollects = allWords;
            tmpCollects.erase(word);
            if(isCombinated(word,tmpCollects))
            {
                if (word.size() > ans.size())ans = word;
                if (word.size() == ans.size())ans = min(ans, word);
            }
        }
        return ans;
    }
private:
    bool isCombinated(string s,unordered_set<string>& words)
    {
        if (s.size() == 0)return true;
        for(int i=1;i<=s.size();i++)
        {
            if (words.count(s.substr(0, i)) && isCombinated(s.substr(i), words))return true;
        }
        return false;
    }
};
```
![无标题.png](https://pic.leetcode-cn.com/69a01ccca316f001ec75f48b596b15c35239dda315bad36955c7737c1136b6c6-%E6%97%A0%E6%A0%87%E9%A2%98.png)
