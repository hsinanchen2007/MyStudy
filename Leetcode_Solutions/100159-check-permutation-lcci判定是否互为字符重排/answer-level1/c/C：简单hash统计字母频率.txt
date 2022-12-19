思路：
简单用字母值-'a'哈希，分别统计两个字符串的字符个数，然后遍历比较，不同则false
加了打印可以看具体的统计数据
```
#define MAX 26
bool CheckPermutation(char* s1, char* s2){
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int hash1[MAX] = {0};
    int hash2[MAX] = {0};
    int i;
    for (i = 0; i < strlen(s1); i++) {
        hash1[s1[i] - 'a']++;
        hash2[s2[i] - 'a']++;
    }
    for (i = 0; i < MAX; i++) {
        //printf("%c %d %d\n", (i + 'a'), hash1[i], hash2[i]);
        if (hash1[i] != hash2[i]) {
            return false;
        }
    }
    return true;
}
```
