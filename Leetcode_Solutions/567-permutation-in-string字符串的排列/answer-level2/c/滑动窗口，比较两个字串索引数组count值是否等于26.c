### 解题思路
比较两个字串索引值是否等于26
1、生成s1的索引数组，长度26，对应26个字母
2、不断滑动窗口生成s2的索引数组
3、比较两个索引数组是否完全相等，count值等于26

### 代码

```c
bool checkInclusion(char * s1, char * s2){
    int s1Map[26] = {0};
    int s2Map[26] = {0};
    int count = 0;

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len2 - len1;

    if (len < 0)
        return false;
    
    for (int i = 0; i < len1; i++) {
        s1Map[s1[i] - 'a']++;
    }

    char *tmp = s2;
    for (int j = 0; j <= len; j++) {
        tmp = s2 + j;
        
        for (int k = 0; k < len1; k++) {
            s2Map[tmp[k] - 'a']++;
        }
        
        for (int m = 0; m < 26; m++) {
            if (s1Map[m] == s2Map[m])
                count++;
            s2Map[m] = 0;
        }
        //printf("count: %d", count);

        if (count == 26)
            return true;
        else
            count = 0;
    }
    return false;
}
```