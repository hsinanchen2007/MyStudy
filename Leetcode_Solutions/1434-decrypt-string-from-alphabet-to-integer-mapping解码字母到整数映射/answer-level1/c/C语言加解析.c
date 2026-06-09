#include <string.h>

// 遍历字符串，若当前元素不是'#'，判断后2位有没有'#'，
// if有, 将前面的数字根据ascii码转成字母，然后从 i+3 继续遍历
// else 直接用ascii码转为字母。

```
char * freqAlphabets(char * s){
    int length = strlen(s);
    int i = 0, j=0;
    char *op = (char*)calloc(length, sizeof(char));         // 这一行要这样，而不是 char op[1000]的数组
    for(i = 0; s[i]!='\0'; ){       // 没有对 i 处理
        if(s[i]!='#'){
            if(i+2<length && s[i+2] == '#'){
                op[j++] = (s[i] - '0') * 10 + (s[i+1] - '0') + 'a'-1;     // 26 -> z（122） 
                i += 3;
            }else
                op[j++] = s[i++] -'0' + 'a' - 1;
        }
    }
    return op;
}
```