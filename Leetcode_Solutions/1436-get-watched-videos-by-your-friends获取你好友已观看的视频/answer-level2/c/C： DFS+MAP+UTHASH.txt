
思路：
   1、DFS出所有好友，在最后一步前，所有Level-1步前的好友都标记到map，最后一步标记到last;
   2、遍历last, map里为0的**最短距离**为k;
   3、获取视频列表，加入hash, key为视频名称，val为观看次数；
   4、hash表按视频名称字母序排序，再按观看次数排序，这样可以达到题目要求的先次数后字母序的结果；
   5、hash表中所有key放到res 

```
typedef struct hash_entry {
    char name[9];            /* we'll use this field as the key */
    int val;
    UT_hash_handle hh; /* makes this structure hashable */
} hash;

hash *trunk = NULL;

hash *find(char *name) {
    hash *s;
    HASH_FIND_STR(trunk, name, s);
    return s;
}

void add(char *name) {
    hash *s = find(name);
    int len = 0;
    if (s == NULL) {
        hash *s = (hash *)malloc(sizeof *s);
        len = strlen(name);
        strncpy(s->name, name, len);
        s->name[len] = 0;
        s->val = 1;
        HASH_ADD_STR(trunk, name, s);
    } else {
        s->val++;
    }
}

int name_sort(hash *a, hash *b) {
    return strcmp(a->name,b->name);
}

int id_sort(hash *a, hash *b) {
    return (a->val - b->val);
}

void sort_by_name() {
    HASH_SORT(trunk, name_sort);
}

void sort_by_id() {
    HASH_SORT(trunk, id_sort);
}

void delete_all() {
  hash *cur, *tmp;
  HASH_ITER(hh, trunk, cur, tmp) {
    HASH_DEL(trunk, cur);  /* delete it (trunk advances to next) */
    free(cur);             /* free it */
  }
}

void print() {
  hash *cur, *tmp;
  HASH_ITER(hh, trunk, cur, tmp) {
    printf("name %s, val %d.\n", cur->name, cur->val);
  }
}

void dfs(char ***Videos, int **friends, int *friCol, int id, int cur, int level, int *map, int *last,int self)
{
    if (cur == level) {
        for (int i = 0; i < friCol[id]; i++) {
            //printf("id %d. friends: %d.\n", id, friends[id][i]);
            last[friends[id][i]] = 1;
        }
        return;
    }
    for (int i = 0; i < friCol[id]; i++) {
        //printf("cur %d, level %d, friends %d.\n", cur, level, friends[id][i]);
        if (friends[id][i] == self) {
            continue;
        }
        map[friends[id][i]] = 1;
        dfs(Videos, friends, friCol, friends[id][i], cur + 1, level, map, last, self);
    }
}

char ** watchedVideosByFriends(char *** Videos, int VideosSize, int* VideosCol, int** friends, int friendsSize, int* friCol, int id, int level, int* retSize)
{
    *retSize = 0;

    int map[100] = {0};
    int last[100] = {0};
    map[id] = 1;
    dfs(Videos, friends, friCol, id, 1, level, map, last, id);  
    for (int i = 0; i < 100; i++) {
        if (last[i] == 1) {
            if (map[i] == 1) {
                continue;
            } 
            for (int j = 0; j < VideosCol[i]; j++) {
                add(Videos[i][j]);
            }    
        }
    }

    sort_by_name();
    sort_by_id();

    char **res = (char **)calloc(5000, sizeof(char *));
    hash *s, *tmp;
    HASH_ITER(hh, trunk, s, tmp) {
        int len = strlen(s->name);
        res[*retSize] = (char *)calloc(9, sizeof(char));
        strncpy(res[*retSize], s->name, len);
        res[*retSize][len] = 0;
        (*retSize)++;
        HASH_DEL(trunk, s);  /* delete it (trunk advances to next) */
        free(s);             /* free it */
    }
    //printf("retSize = %d.", *retSize);
    return res;
}
```


执行用时 :
132 ms, 在所有 C 提交中击败了85.25%的用户
内存消耗 :
22.8 MB, 在所有 C 提交中击败了100.00%的用户


