```c
int lengthOfLongestSubstring(char* s){
    int count[95]; // ASCII中存在95个可打印的字符，记录遍历s时遇到的字符
    memset(count, 0, 95 * sizeof(int)); // 将count的值全部置为0
    int max_lenght = 0; // 不含重复字符的子字符串的最大长度
    int temp = 0; // 存储遍历s时所寻找到的不含重复字符的子字符串的长度
    int p1 = 0, p2 = 0;
    while(s[p1] != '\0' && s[p2] != '\0'){

        if(count[s[p2] - ' '] == 0){ // 没有遇到重复字符
            count[s[p2] - ' '] = 1; // 记录遇到的字符
            p2 += 1;
            temp = p2 - p1;
        }
        else{ // 遇到重复字符
            temp = p2 - p1;
            count[s[p1] - ' '] = 0; // 删除对p1位置字符的记录
            p1 += 1; // p1右移
        }

        if(temp > max_lenght){
            max_lenght = temp;
        }
    }
    return max_lenght;
}
```
