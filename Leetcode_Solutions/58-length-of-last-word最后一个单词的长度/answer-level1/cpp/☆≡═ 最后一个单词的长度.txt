1. 因为要找最后一个单词的长度，从前往后找要判断目前的单词是否是最后一个。
2. 但是从后往前找，找到的第一个单词就是要求的单词，迭代器 first 指向最后一个单词的最后一个字母。
3. 然后从这个位置，迭代到字符串开头，或者到中间的一个空格，迭代器 last 指向最后一个单词第一个字母前的一个位置。
4. 然后计算 first 和 last 的距离。

```c++ []
class Solution {
public:
    int lengthOfLastWord(const string& s) {
        auto first = find_if_not(s.rbegin(), s.rend(), ::isspace);
        auto last = find_if(first, s.rend(), ::isspace);
        return distance(first, last);
    }
};
```
```c []
int lengthOfLastWord(char *s){
    int i = strlen(s) - 1;
    while (0 <= i && s[i] == ' ') --i;
    int j = i;
    while (0 <= j && s[j] != ' ') --j;
    return i - j;
}
```