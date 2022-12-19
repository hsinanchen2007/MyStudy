- 执行用时 :4 ms, 在所有 c 提交中击败了66.88%的用户
- 内存消耗 :6.9 MB, 在所有 c 提交中击败了100.00%的用户
- 题目的提示中要求用hashmap来解决.我自己写了个简单的hash
```
char *alphabetBoardPath(char *target)
{
    typedef struct Node {
        int  x;
        int  y;
        char key;
    } HashNode;
    HashNode easyHash[26];
    char *   tmpS = (char *)malloc(1000); //这里投个巧,最多100个字符,每个字符最多9步,再加一个'!',共十步,最坏的情况了.
    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != 5; j++) {
            int pos           = 5 * i + j;
            easyHash[pos].key = 'a' + pos;
            easyHash[pos].x   = i;
            easyHash[pos].y   = j;
            if (pos == 25) { // 字母z
                break;
            }
        }
    }
    int      pos = 0;
    HashNode cur = { 0, 0, 'a' };
    while (*target) {
        int tmp = *target - 'a';
        int r   = easyHash[tmp].x - cur.x;
        int c   = easyHash[tmp].y - cur.y;
        if (cur.key == 'z' && *target != 'z') {
            while (r) {
                if (r < 0) {
                    tmpS[pos++] = 'U';
                    r++;
                } else {
                    tmpS[pos++] = 'D';
                    r--;
                }
            }
            while (c) {
                if (c < 0) {
                    tmpS[pos++] = 'L';
                    c++;
                } else {
                    tmpS[pos++] = 'R';
                    c--;
                }
            }
        } else if (cur.key != 'z' && *target == 'z') {
            while (c) {
                if (c < 0) {
                    tmpS[pos++] = 'L';
                    c++;
                } else {
                    tmpS[pos++] = 'R';
                    c--;
                }
            }
            while (r) {
                if (r < 0) {
                    tmpS[pos++] = 'U';
                    r++;
                } else {
                    tmpS[pos++] = 'D';
                    r--;
                }
            }
        } else {
            while (r) {
                if (r < 0) {
                    tmpS[pos++] = 'U';
                    r++;
                } else {
                    tmpS[pos++] = 'D';
                    r--;
                }
            }
            while (c) {
                if (c < 0) {
                    tmpS[pos++] = 'L';
                    c++;
                } else {
                    tmpS[pos++] = 'R';
                    c--;
                }
            }
        }
        tmpS[pos++] = '!';
        target++;
        cur.key = easyHash[tmp].key;
        cur.x   = easyHash[tmp].x;
        cur.y   = easyHash[tmp].y;
    }
    tmpS[pos] = 0;
    return tmpS;
}
```

