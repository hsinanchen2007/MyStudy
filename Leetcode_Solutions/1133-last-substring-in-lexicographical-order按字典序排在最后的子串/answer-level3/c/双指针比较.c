### 解题思路
1、双指针，从右往左，移动left
2、如果left的字符大于right，就将right移动到left
3、如果left 的字符== right，就比较两个位置开头的字符串大小，但这种方式会超时，因此需要先忍住别立即比较, 而是往left -1 处窥视一下，如果也是相同字符，就continue 移动left。

如果是从右往左，会出现一个问题就是当出现left 和right字符相等进行right +1窥视时，会导致无法找到第一个相等字符的位置被丢弃。

### 代码

```c

char * lastSubstring(char * s){
    if (s == NULL) {
        return s;
    }
    int len = strlen(s);
    if (len < 2) {
        return s;
    }
    char *left = NULL;
    char *right = NULL;

    for (left = s + len - 2, right = s + len - 1; (left >= s) && (right >= s + 1);  left--) {
        //printf("%s %s \n", left, right);
        if (*left > *right) {
            right = left;                    
            continue;
        }           
        if (*left == *right) {
            if ((left - 1 >= s) && (*(left - 1) == *right)) {
                //printf("%s %s \n", left, right);
                continue;
            } 
            //printf("--%s %s \n", left, right);
            if (strcmp(left, right) > 0) {
                right = left;                
                continue;
            }                            
        }         
    }
    return right;
}
```