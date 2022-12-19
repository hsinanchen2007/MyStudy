### 解题思路
去掉字符串中首尾及中间的空格，翻转字符串，翻转单词

### 代码

```c
void reverse(char *start, char *end) {
    if (start == NULL || end == NULL) {
        return;
    }
    
    //翻转字符
    while (start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;

        start++;
        end--;
    }
}

char * reverseWords(char * s){
    if (s == NULL) {
        return '\0';
    }

    //去除多余空格
    char *str = s;
    //去除首部空格
    while(*str != '\0') {
        if (*str != ' ') {
            s = str;
            break;
        }
        str++;
    }
    str = s;
    int i,j;
    i = 0;
    j = 0;
    //去除中间或尾部空格
    while(*(str+i) != '\0') {
        if (*(str+j) == ' ') {
            if (*(str+j+1) == ' ') {
                j++;
                continue;
            } else if (*(str+j+1) == '\0' ) {
                //去掉尾部空格
                *(str+i) = '\0';
                break;
            }
        } else if (*(str+j) == '\0' ) {
                //去掉尾部空格
                *(str+i) = '\0';
                break;
        } 
        if (*(str+i) != *(str+j)) {
            *(str+i) = *(str+j);
        }
        i++;
        j++; 
    }
    char *start,*end;
    start = s;
    end = s;
    
    while(*end != '\0') {
        end++;
    }
    end--;

    reverse(start,end);

    //翻转单词
    start = s;
    end = s;

    while (*start != '\0') {
        if (*start == ' ') {
            start++;
            end++;
        } else if (*end == ' ' || *end == '\0'){
            end--;
            reverse(start,end);
            start = ++end;
        } else {
            end++;
        }
    }
    
    return s;
}
```