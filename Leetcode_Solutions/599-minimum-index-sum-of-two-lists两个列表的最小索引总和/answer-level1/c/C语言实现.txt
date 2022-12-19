### **方法一：先排序，再双指针搜索**

执行用时: 124 ms, 在所有 C 提交中击败了100.00%的用户
先把两个字符串列表排序，然后双指针排查相同的字符串，记录索引和最小的相同字符串。
```C []
typedef struct _Data{
    int index;
    char *info;
}Data;

int cmp(const void *a, const void *b){
    
    int ret = strcmp(((Data*)a)->info, ((Data*)b)->info);    
    return ret;
}

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    *returnSize = 0;
    char** res = (char**)malloc((list1Size > list2Size ? list2Size : list1Size) * sizeof(char*));
    Data *src1 = (Data*)malloc(list1Size * sizeof(Data));
    Data *src2 = (Data*)malloc(list2Size * sizeof(Data));
    int i, j = 0, val, max = list1Size + list2Size, sum;
    for (i = 0; i < list1Size; ++i) {
        src1[i].index = i;
        src1[i].info = list1[i];
    }
    for (i = 0; i < list2Size; ++i){
        src2[i].index = i;
        src2[i].info = list2[i];
    }
    qsort(src1, list1Size, sizeof(Data), cmp);
    qsort(src2, list2Size, sizeof(Data), cmp);
    
    i = 0, j = 0;
    while (i < list1Size && j < list2Size){
        val = strcmp(src1[i].info, src2[j].info);
        if (val < 0){
            ++i;
        } else if (val == 0){
            sum = src1[i].index + src2[j].index;
            if (sum < max){
                max = sum;
                *returnSize = 0;
                res[(*returnSize)++] = src1[i].info;
            } else if (sum == max){
                res[(*returnSize)++] = src1[i].info;
            }
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    free(src1);
    free(src2);
    return res;
}
```
### **方法二：Hash 映射**
执行用时: 64 ms, 在所有 C 提交中击败了100.00%的用户
先对第一个字符串列表进行hash映射，然后在第二个字符串列表中查找相同字符。
```C []
struct hash_node{
    char *key;
    int val;
    struct hash_node* next;
};
struct hash_table{
    struct hash_node** head;
    int hash_width;
};
int hash_init(struct hash_table* table, int hash_width){
    if (hash_width <= 0) return -1;
    table->head = (struct hash_node**)malloc(hash_width * sizeof(struct hash_node*));
    if (!table->head) return -1;
    memset(table->head, 0, hash_width * sizeof(struct hash_node*));
    table->hash_width = hash_width;
    return 0;
}
void hash_free(struct hash_table* table){
    if (table->head){
        for (int i = 0; i < table->hash_width; ++i){
            struct hash_node* p = table->head[i];
            while (p){
                struct hash_node* tmp = p;
                p = p->next;
                free(p);
            }
        }
        free(table->head);
        table->head = NULL;
    }
    table->hash_width = 0;
}
int hash_addr(int hash_width, char *key){
    int k = 0;
    while (*key) k += *key++;
    return k % hash_width;
}
int hash_insert(struct hash_table* table, char* key, int val){
    int k = hash_addr(table->hash_width, key);
    struct hash_node* p = (struct hash_node*)malloc(sizeof(struct hash_node));
    if (!p) return -1;
    p->key = key;
    p->val = val;
    p->next = table->head[k];
    table->head[k] = p;
    return 0;
}
struct hash_node* hash_find(struct hash_table* table, char* key){
    int k = hash_addr(table->hash_width, key);
    struct hash_node* p = table->head[k];
    while (p){
        if (0 == strcmp(p->key, key)) return p;
        p = p->next;
    }
    return NULL;
}
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
{
    char** res = NULL;
    *returnSize = 0;
    int i, minVal = list1Size + list2Size;
    struct hash_table table;
    hash_init(&table, 100);
    for (i = 0; i < list1Size; ++i){
        hash_insert(&table, list1[i], i);
    }
    for (i = 0; i < list2Size; ++i){
        struct hash_node* p = hash_find(&table, list2[i]);
        if (p) {
            if (i + p->val < minVal){
                minVal = i + p->val;               
                res = (char**)realloc(res, sizeof(char*));
                *returnSize = 0;
                res[(*returnSize)++] = list2[i];
            } else if (i + p->val == minVal){
                res = (char**)realloc(res, (1 + *returnSize) * sizeof(char*));
                res[(*returnSize)++] = list2[i];
            }
        }
    }
    return res;
}
```