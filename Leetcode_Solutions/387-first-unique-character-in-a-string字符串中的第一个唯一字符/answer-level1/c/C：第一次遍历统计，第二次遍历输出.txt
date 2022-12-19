思路：
因为字母只有26个，所以遍历一次，用一个哈希表统计字母出现次数很方便，
映射是直接用字母值转为从0开始的数值，
再次遍历输出第一个统计次数为1的字符对应的下标就好
```
int firstUniqChar(char * s){
    int alpha[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        alpha[s[i]-'a']++;
    }
    for(int i = 0; i < strlen(s); i++){
        if(alpha[s[i]-'a'] == 1){
            return i;
        }
    }
    return -1;
}
```
