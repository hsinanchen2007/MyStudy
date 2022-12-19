## 思路
![image.png](https://pic.leetcode-cn.com/989258022c4219f65eebe8f80b3d32115feeb43385eeacd2dc78871a86a537e3-image.png)

从beginWord开始，从第一个字母开始查找替换一个字母后是否在单词列表中。
- 如果在单词列表中并且等于endWord，则在替换前单词路径长度上加 1。
- 如果在单词列表中但不在转换路径中，则放入队列，并设置新单词路径长度为替换前单词路径长度加 1。

### 代码
```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) {
            return 0;
        }
        unordered_map<string, int> pathCnt = {{beginWord, 1}};
        queue<string> q{{beginWord}};
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) > 0 && newWord == endWord) {
                        return pathCnt[word] + 1;
                    }
                    if (wordSet.count(newWord) > 0 && !pathCnt.count(newWord)) {
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
```
