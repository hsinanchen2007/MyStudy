### 解题思路
两个哈希表，一个存储禁用词，一个用来存储段落中出现的每个单词出现的次数

遍历段落，右指针指向特殊字符的时候，获得单词（遍历的过程中将大写转换为小写）
左右指针同时指向特殊字符的时候，左右指针都移动

最后循环外要判断下left != right, 把最后一个单词加入进来

最后遍历一下存储单词出现次数的哈希表，如果不在禁用词列表中，并且出现次数比当前最大出现次数大，就更新一下结果

### 代码

```cpp
class Solution {
public:
    bool isValid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string, int> wordCount;
        
        unordered_map<string, bool> bannedWords;
        
        for (int i = 0; i < banned.size(); i++) {
            bannedWords[banned[i]] = true;
        }
        
        int size = paragraph.size();
        
        
        string s = paragraph;
        int left = 0;
        int right = 0;
        while (right < size) {
            if (!isValid(s[right]) && !isValid(s[left])) {
                left++;
                right++;
            } else if (isValid(s[right])) {
                // 大小写字符
                // 如果是大写的话，转换为小写
                if (s[right] >= 'A' && s[right] <= 'Z') {
                    s[right] = s[right] + 32;
                }
                right++;
            } else {
                string tmp = s.substr(left, right - left);
                wordCount[tmp]++;
                left = right + 1;
                right++;
            }
        }
        if (left != right) {
            string tmp = s.substr(left, right - left);
            wordCount[tmp]++;
        }
        unordered_map<string, int>::iterator it;
        string result = "";
        int maxCount = INT_MIN;
        for (it = wordCount.begin(); it != wordCount.end(); it++) {
            if (it->second > maxCount && bannedWords.count(it->first) == 0) {
                maxCount = it->second;
                result = it->first;
            }
        }
        return result;
    }
};
```