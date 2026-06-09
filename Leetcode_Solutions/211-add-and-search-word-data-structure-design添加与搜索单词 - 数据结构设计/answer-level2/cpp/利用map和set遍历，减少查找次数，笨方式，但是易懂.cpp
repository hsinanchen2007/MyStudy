### 解题思路
普通遍历超时，想到减少查找次数。
减少查找次数通过两个方式筛选：1、单词长度 2、去重
利用map存储set，map看做一个大字典，set看作小字典。每个set中的单词的长度相同。
查找时根据目标单词word的长度选出对应的小字典set，再遍历set进行查找。
笨，但是简单易懂O(∩_∩)O。
![image.png](https://pic.leetcode-cn.com/a569e0752840a09386a2e46792119034677d635732bfbebf7ee709ed1181907f-image.png)

### 代码

```cpp
class WordDictionary {
public:
    map<int, set<string> > words;   // 大字典
    WordDictionary() {}
    void addWord(string word) {     // 添加操作，每个单词按照长度存到对应的set中
        words[word.length()].insert(word);
    }
    bool search(string word) {      // 从大字典中找单词
        set<string> set_words = words[word.length()];   // 首先找到对应的长度，拿出对应的小字典
        for(string des : set_words){                    // 遍历小字典找单词
            int i = 0;
            while(i < min(des.length(), word.length())){
                if(word[i] == '.' || (des[i] == word[i]))i++;
                else break;
            }
            if(i == des.length() && i == word.length())return true;
        }
        return false;
    }
};
```