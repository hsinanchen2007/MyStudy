思路：
因为全小写字母，直接统计出现频率，然后判断是否重复
```
bool isUnique(char* astr){
    int hash[26] = {0};
    int len = strlen(astr);
    for (int i = 0; i < len; i++) {
        hash[astr[i] - 'a']++;
        if (hash[astr[i] - 'a'] > 1) {
            return false;
        }
    }
    return true;
}
```
