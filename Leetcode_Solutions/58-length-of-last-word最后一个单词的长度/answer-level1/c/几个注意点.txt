### 解题思路
此处撰写解题思路
1）判断位置的条件应该是“空格+字母”；
2）统计字符长度时，应该注意后面还有空格的情况；
3）空字符串的情况；

### 代码

```c
int lengthOfLastWord(char * s){
    int i = 0;
    int w = -1;   //记录位置
    int count = 0;

    if (strlen(s) == 0) {
        return 0;
    }

    for (i=0; i<strlen(s)-1; i++) {
        if (s[i] == ' ' && s[i+1] != ' ') {
            w = i;
        }

    } 

    for (i=w+1; i<strlen(s); i++) {
        if (s[i] == ' ') {
            break;
        }
        else {
            count++;
        }
    }

    return count;

}
```