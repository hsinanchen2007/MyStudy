代码写的太烂了，自己不想看第二遍，思路参考官解贪心算法。
```
#define MAX_SIZE 1001
#define ALPHA_NUM 26
char * smallestSubsequence(char * text){
    int len = strlen(text);
    if (len == 0) {
        return 0;
    }
    int all = 0;
    int sum = 0;
    int index = 0;
    char *res = (char*)malloc(MAX_SIZE * sizeof(char));
    memset(res, 0, MAX_SIZE * sizeof(char));
    for (int i = 0; i < len; i++) {
        if ((all & (1 << (text[i] - 'a'))) == 0) {
            all += (1 << (text[i] - 'a'));
            sum++;
        }
    }
    int pos = 0;
    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < 26; j++) {
            if (!(all & (1 << j))) {
                continue;
            }
            int flag = 0;
            int tmp = all;
            int k;
            int p = 0;
            for (int k = 0; k < len; k++) {
                if ((flag == 0 && text[k] != j + 'a') || k < pos) {
                    continue;
                }
                if (text[k] == j + 'a') {
                    if (flag == 0) {
                        p = k;
                    }
                    flag = 1;
                }
                if (tmp & (1 << (text[k] - 'a'))) {
                    tmp -= (1 << (text[k] - 'a'));
                }
            }
            if (tmp == 0) {
                res[index++] = j + 'a';
                pos = p;
                all -= (1 << j);
                break;
            }
        }
    }
    return res;
}
```
