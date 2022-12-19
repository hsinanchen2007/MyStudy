### 解题思路
建立哈希对应表；考虑相邻两个字符的大小关系；

### 代码

```c
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int romanToInt(char * s) {
    int len;
    int i;
    int hash[26];
    int integer = 0;
    int tmp;

    len = strlen(s);

    hash['I' - 'A'] = 1;
    hash['V' - 'A'] = 5;
    hash['X' - 'A'] = 10;
    hash['L' - 'A'] = 50;
    hash['C' - 'A'] = 100;
    hash['D' - 'A'] = 500;
    hash['M' - 'A'] = 1000;

    while (*s != '\0') {
        if (*(s + 1) == '\0') {
            integer += hash[*s++ - 'A'];
        }
        else {  
            if (hash[*s - 'A'] >= hash[*(s + 1) - 'A']) {
                integer += hash[*s++ - 'A'];
            }         
            else {
                integer += (hash[*(s + 1) - 'A'] - hash[*s - 'A']);
                s += 2;
            }
        }
    }

    return integer;
}
```