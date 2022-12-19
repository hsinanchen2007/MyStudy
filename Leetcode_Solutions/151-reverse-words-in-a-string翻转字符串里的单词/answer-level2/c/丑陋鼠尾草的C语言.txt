### 解题思路
暴力解决

### 代码

```c
char * reverseWords(char * s){
    
    int len = strlen(s);
    if (len == 0) {
        return "";
    }

    int x = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            x = i;
            if (x == len - 1) {
                return "";
            }
        }
        if (s[i] != ' ') {
            break;
        }
    }

    
    printf("\n[1]%d", s[len-1]);
    char* temp = (char*)malloc(sizeof(char) * (len + 10));
    char* ret = (char*)malloc(sizeof(char) * (len + 10));
    memset(ret, 0, sizeof(char) * (len + 10));

    int idx = 0;
    int index = 0;
    
    for (int i = len - 1; i >= x; i--) {

        while (s[i] == ' ' && i >= x) {
            i--;
        }
        index = 0;
        while (i >= x) {
            if (s[i] == ' ') {
                break;
            }
            temp[index++] = s[i];
            i--;
        }
        if (index > 0) {
            for (int j = index - 1; j >= 0; j--) {
                ret[idx++] = temp[j];
                
            }
            ret[idx++] = ' ';
        }
    }
    if (idx > 0) {
        ret[idx - 1] = '\0';
    }
    return ret; 
}

```