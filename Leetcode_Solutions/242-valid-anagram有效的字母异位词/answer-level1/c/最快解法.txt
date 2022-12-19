```
执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.7 MB
, 在所有 C 提交中击败了
100.00%
的用户
#define SYM_NUM 26

bool isAnagram(char * s, char * t){
    int hash[SYM_NUM] = {0};
    int lens = strlen(s);
    int lent = strlen(t);
    if (lent != lens) {
        return false;
    }
    for (int i = 0; i < lens; i++) {
        hash[s[i] -'a']++;
        hash[t[i] -'a']--;
    }

    for (int i = 0; i < SYM_NUM; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }

    return true;
}
```
