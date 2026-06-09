### 解题思路
    /*
     * 哈希表计数
     *
     * 对chars中的字母使用哈希表进程存储，记录每个字母的数量。
     * 在查找words中的每个字符串w中的每个字母是否存在于哈希表中，
     * 如果存在，就将该字母的数量减一，不存在或该字母的数量为0，
     * 就继续遍历下一个字符串w，直到遍历所有字符串。
     * 当遍历一个字符串w结束后，计数count的值与该字符串的大小相等，
     * 表示该字符串符合条件，则将该字符串的大小加到结果中。
### 代码

```cpp
int countCharacters(std::vector<std::string> &words, std::string chars) {
    int ans = 0;

    std::unordered_map<char, int> unorderedMap;
    std::unordered_map<char, int> tempMap;

    // 将chars中的字母存入哈希表中计数
    for (auto ch : chars) {
        unorderedMap[ch]++;
    }

    // 遍历字符串数组的字符串
    for (auto w : words) {
        // 记录匹配的字符数
        int count = 0;
        int i = 0;
        // 临时哈希表，每次还原
        tempMap = unorderedMap;
        // 如果在哈希表中能够找到该字符且在该字符的数量大于1
        while ((chars.find(w[i]) != std::string::npos) && (tempMap[w[i]] != 0)) {
            // 数量减一
            tempMap[w[i]]--;
            i++;
            // 匹配数加1
            count++;
        }

        // 如果当前字符串匹配数等于字符串长度
        if (count == w.size()) {
            // 将字符串长度加入结果中
            ans += w.size();
        }
    }

    return ans;
}
```


    /*
     * 哈希表计数
     *
     * 对于单词word，只要其中每个字母的数量都不大于chars中对应的字母的数量，
     * 那么就可以用chars中的字母拼写出word。所以只需要用一个哈希表存储chars中每个字母的数量，
     * 再用一个哈希表存储word中每个字母的数量，最后对两个哈希表的键值对逐一进行比较即可。
     * */
### 代码

```cpp
int countCharacters2(std::vector<std::string> &words, std::string chars) {
    int ans = 0;

    std::unordered_map<char, int> chars_cnt;
    // 将chars中的字母存入哈希表中计数
    for (char ch : chars) {
        chars_cnt[ch]++;
    }

    // 遍历字符串数组的字符串
    for (std::string word : words) {
        std::unordered_map<char, int> word_cnt;
        // 将每个字符串的字母存入哈希表中计数
        for (char ch : word) {
            word_cnt[ch]++;
        }

        // 判断是否匹配
        bool right = true;
        for (char ch : word) {
            // 如果字符串中的字符数量都大于chars中的字符数量，
            // 则该字符串不匹配
            if (chars_cnt[ch] < word_cnt[ch]) {
                right = false;
                break;
            }
        }

        // 如果匹配，将字符串长度加入结果中
        if (right) {
            ans += word.size();
        }
    }
    
    return ans;
}
```