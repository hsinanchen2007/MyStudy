### 解题思路
    /*
     * 哈希表法
     *
     * 使用哈希表存储字符串中的每个字符及对应出现的次数，
     * 再次遍历字符串中的字符，判断该字符的次数是否为1，
     * 当为1时即返回该字符，始终找不到则返回空字符。
     * */
### 代码

```cpp
char firstUniqChar(std::string s) {
    if(s.empty()){
        return ' ';
    }

    std::unordered_map<char, int> unorderedMap;
    // 为每个字符存储哈希表
    for(char ch : s){
        unorderedMap[ch]++;
    }

    for(char ch : s){
        // 找到出现次数为1的字符
        if(unorderedMap[ch] == 1){
            return ch;
        }
    }

    // 找不到出现次数为1的字符
    return ' ';
}
```