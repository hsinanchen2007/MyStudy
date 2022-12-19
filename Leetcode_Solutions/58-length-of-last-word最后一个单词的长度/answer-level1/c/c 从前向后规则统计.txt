### 解题思路
补齐最后的空格， 遇到空格统计当前的个数

### 代码

```c
#define MAX_LEN 1000000

int lengthOfLastWord(char * s){
    int count = 0;
    int num = 0;
    int len = strlen(s);
    char value[MAX_LEN] = {0};

    strcat(value, s);
    strcat(value, " ");

    for (int i = 0; i <= len; i++) {
        if (value[i] != ' ') {
            num++;
        } else {           
            count = num != 0 ? num : count;
            num = 0;
        }
    }
    return count;
}
```