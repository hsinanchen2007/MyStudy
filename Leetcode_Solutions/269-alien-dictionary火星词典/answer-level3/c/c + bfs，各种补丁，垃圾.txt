#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int g[26][26];
int grid[26];
int grid_temp[26];
int vist[26];
int ext[26];
int ext_num;
int q[26];
int h = -1, r = -1, n = 0;
char order[27];//26 line 146打印越界
int order_index;

void do_init()
{
    memset(g, 0, sizeof(g));
    memset(grid, 0, sizeof(grid));
    memset(grid_temp, 0, sizeof(grid_temp));
    memset(vist, 0, sizeof(vist));
    memset(ext, 0, sizeof(ext));
    memset(q, 0, sizeof(q));
    memset(order, 0, sizeof(order));
    ext_num = 0;
    h = -1;
    r = -1;
    n = 0;
    order_index = 0;
}

int init(char** words, int wordsSize)
{
    int i, j, k;

    for (i = 0; i < wordsSize; i++) {
        for (k = 0; k < strlen(words[i]); k++) {
            if (ext[words[i][k] - 'a'] != 1) {
                ext[words[i][k] - 'a'] = 1;
                ext_num++;
            }
            //printf("ext %c\n", words[i][k]);
        }
    }
    for (i = 1; i < wordsSize; i++) {
        for (j = 0; j < i; j++) {
            for (k = 0; (k < strlen(words[i])) && (k < strlen(words[j])); k++) {
                char c1 = words[i][k];
                char c2 = words[j][k];
                if (c1 != c2) {
                    if (g[c2 - 'a'][c1 - 'a'] == 1) {
                        break;
                    }
                    g[c2 - 'a'][c1 - 'a'] = 1;
//                    printf("c1 = %c, c2 = %c\n", c1, c2);
                    grid[c1 - 'a']++;
                    break;
                }
            }
            if ((k < strlen(words[j])) && (k == strlen(words[i]))) {
                return -1;
            }
        }
    }
    return 0;
}

int inque(int e)
{
    if (n == 0) {
        q[0] = e;
        h = 0;
        r = 0;
        n++;
        return 0;
    }
    if (((r + 1) % 26) == h) {
        return -1;
    }
    q[(r + 1) % 26] = e;
    r++;
    n++;
    return 0;
}

int deque()
{
    if (n == 0) {
        return -1;
    }
    int e = q[h % 26];
    h++;
    n--;
    return e;
}

int qlen()
{
    return n;
}

int bfs(int s)
{
    inque(s);
    int l = 1;
 
    while(qlen() != 0) {
        int e = deque();
        //printf("deq %c\n", 'a' + e);
        for (int i = 0; i < 26; i++) {
            if (vist[e] == 1) {
                return -1;
            }
        }
        vist[e] = 1;
        order[order_index++ % 26] = e + 'a';
        for (int i = 0; i < 26; i++) {
            if (g[e][i] == 1) {
                //printf("%c grid %d\n", 'a' + i, grid_temp[i]);
                if (grid_temp[i]-- <= 1) {
                    //printf("enq %c, grid %d\n", 'a' + i, grid_temp[i]);
                    inque(i);
                }
            }
        }
    }
    return 0;
}

char* alienOrder(char** words, int wordsSize)
{
    do_init();
    if (init(words, wordsSize) < 0) {
        return "";
    }
    memcpy(grid_temp, grid, sizeof(grid_temp));
    for (int i = 0; i < 26; i++) {
        if ((grid[i] == 0) && (ext[i] == 1)) {
            //printf("bfs %c\n", 'a' + i);
            if (bfs(i) != 0) {
                return "";
            }
        }
    }
    if (strlen(order) != ext_num) {
        //printf("order %s\n", order);
        order[0] = 0;
    }
    return order;
}