**用一个数组p保存magazine中每个字符出现的次数，然后遍历ransomNote，若某一个字符在p中为0，返回false,否则将出现次数减1。**
```c
bool canConstruct(char * ransomNote, char * magazine)
{
    int i, l1 = strlen(ransomNote), l2 = strlen(magazine);
    int p[26]; //保存每个字母的出现次数
    memset(p, 0, sizeof(int) * 26);
    for(i = 0; i < l2; i++){
        p[magazine[i] - 'a']++;
    }
    for(i = 0; i < l1; i++){
        if(p[ransomNote[i] - 'a'] == 0)
            return 0;
        p[ransomNote[i] - 'a']--;
    }
    return 1;
}
```