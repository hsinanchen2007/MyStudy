### 解题思路
1. 定义两个字母计数表
2. 分别计数字母
3. 比较两个字母计数表

### 代码

```c
bool isAnagram(char * s, char * t){
    int *table_one = (int *)calloc(26, sizeof(int));
    int *table_two = (int *)calloc(26, sizeof(int));

    int len1 = strlen(s);
    int len2 = strlen(t);

    for (int i=0; i<len1; i++){
        table_one[s[i]-'a']++;
    }
    for (int i=0; i<len2; i++){
        table_two[t[i]-'a']++;
    }
    for (short i=0; i<26; i++){
        if (table_one[i] != table_two[i]){
            return false;
        }
    }
    return true;
}
```