- ### 解题思路
此处撰写解题思路

### 代码

```c
bool isSubsequence(char * s, char * t){
    bool ret = true;

    while ('\0' != *s) {
        ret = false; 
        
        while('\0' != *t) {
            if (*s == *t++) {
                ret = true;
                break;
            }
        }

        s++;
    }

    return ret;
}
```