### 解题思路
1、把S1中字符出现的次数记录到map中，以字符作为下标记录；
2、从前往后遍历S2,遍历S1的长度，遇到存在的，计数减一，遇到计数为0的表示不符合；遍历S1长度均符合则找到；
2、S2遍历到最后

### 代码

```c

#define CHAR_MAX 26

bool checkInclusion(char * s1, char * s2){
    int map[CHAR_MAX] = {0};
    int tem[CHAR_MAX] = {0};
    int i = 0;
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int j = 0;

    if (len_s1 > len_s2) {
        return false;
    }
    if (len_s1 == 0) {
        return true;
    }
    for (i = 0; i < len_s1; i++) {
        map[*(s1 + i) - 'a']++;
    }

    for(i = 0; i <= len_s2 - len_s1; i++) {
        memcpy(tem, map, CHAR_MAX * sizeof(int));
        for (j = i; j < i + len_s1; j++) {
            if (tem[*(s2 + j) - 'a'] <= 0) {
                break;
            }
            tem[*(s2 + j) - 'a']--;
        }
        if (j == i + len_s1) {
            return true;
        }
    }

    return false;
}
```