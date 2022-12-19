### 解题思路   先对所有相等的组合“染色”，然后再用不等去验证！
此处撰写解题思路

### 代码

```c

int ranse[26];
int temp1 = 0;
bool equationsPossible(char ** equations, int equationsSize){
    int i = 0;
    int j = 0;
    for (i = 0; i < 26; i++) {
        ranse[i] = -1;
    }
    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] != '=') {
            continue;
        }
        if (ranse[equations[i][0] - 'a'] == -1 && ranse[equations[i][3] - 'a'] == -1) {
            ranse[equations[i][0] - 'a'] = equations[i][0] - 'a';
            ranse[equations[i][3] - 'a'] = equations[i][0] - 'a';
        } else {
            if (ranse[equations[i][3] - 'a'] == -1) {
                ranse[equations[i][3] - 'a'] = ranse[equations[i][0] - 'a'];
            } else if (ranse[equations[i][0] - 'a'] == -1) {
                ranse[equations[i][0] - 'a'] = ranse[equations[i][3] - 'a'];
            } else {
                temp1 = ranse[equations[i][3] - 'a'];
                //printf("temp:%d\n", temp1);
                for (j = 0; j < 26; j++) {
                    if (ranse[j] == temp1) {
                        ranse[j] = ranse[equations[i][0] - 'a'];
                    }
                }
            }
        }
    }
    /*
    for (i = 0; i<26;i++) {
        printf("ra[%d]=%d  ", i, ranse[i]);
    }
    */
    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            if (equations[i][0] == equations[i][3]) {
                return false;
            }
            if (ranse[equations[i][0] - 'a'] == ranse[equations[i][3] - 'a']) {
                if (ranse[equations[i][3] - 'a'] != -1 && ranse[equations[i][0] - 'a'] != -1) {
                    return false;
                }
            }
        }
    }
    
    return true;
}
```