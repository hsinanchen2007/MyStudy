
### 解题思路
![leeetcode.PNG](https://pic.leetcode-cn.com/0bb81c4e9cd45db4723b1aa673ea43eaccabf3673c0c0ade3754236a2e50a594-leeetcode.PNG)


### 代码

```c
char* replaceSpace(char* s){
    char* c = s;
    char *s1 = (char*)malloc(10000*sizeof(char));
    int index = 0;
    while(*c) {
        if(*c == ' ') {
            s1[index++] = '%';
            s1[index++] = '2';
            s1[index++] = '0';
        } else {
            s1[index++] = *c;
        }
        c++;
    }
    s1[index] = NULL;
    return s1;
}
```
