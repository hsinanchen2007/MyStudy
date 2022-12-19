### 解题思路
使用uthash函数。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct my_struct {
    char ikey[100];
    int number;
    UT_hash_handle hh;
};

struct my_struct *g_users = NULL;

struct my_struct *finde_user(int ikey) {
    struct my_struct *s;
    HASH_FIND_INT(g_users, ikey, s);
    return s;
}
#if 0
void add_user(int ikey, char *value_buf) {  
    struct my_struct *s;  
    HASH_FIND_INT(g_users, &ikey, s);  /* 插入前先查看key值是否已经在hash表g_users里面了 */  
    if (s==NULL) {  
      s = (struct my_struct*)malloc(sizeof(struct my_struct));  
      s->ikey = ikey;  
      HASH_ADD_INT(g_users, ikey, s);  /* 这里必须明确告诉插入函数，自己定义的hash结构体中键变量的名字 */  
    }  

    strcpy(s->number, value_buf);  
}
#else
void add_user(char *ikey, int value) {  
    struct my_struct *s;  

    HASH_FIND_STR(g_users, ikey, s);  /* 插入前先查看key值是否已经在hash表g_users里面了 */

    if (s == NULL) {
      s = (struct my_struct*)malloc(sizeof(struct my_struct));
      strcpy(s->ikey, ikey);
      s->number = 1;
      HASH_ADD_STR(g_users, ikey, s);  /* 这里必须明确告诉插入函数，自己定义的hash结构体中键变量的名字 */  
      return;
    }  
    s->number++;
    printf("2 s->ikey=%s s->number=%d\n", s->ikey, s->number);
    return;
}
#endif

void delete_user(int ikey) {
    struct my_struct *s = NULL;
    HASH_FIND_INT(g_users, ikey, s);
    if (s!=NULL) {
      HASH_DEL(g_users, s);
      free(s);          
    }
}
#if 0
int name_sort(struct my_struct *a, struct my_struct *b) {  
    return strcmp(a->name,b->name);  
}  
  
int id_sort(struct my_struct *a, struct my_struct *b) {  
    return (a->ikey - b->ikey);  
}
  
void sort_by_name() {  
    HASH_SORT(g_users, name_sort);  
}
void sort_by_id() {  
    HASH_SORT(g_users, id_sort);  
} 
#else

  
int id_sort(struct my_struct *a, struct my_struct *b) {  
    return strcmp(a->ikey,b->ikey); 
}

int number_sort(struct my_struct *a, struct my_struct *b) { 
    if (b->number == a->number) {
        return strcmp(a->ikey, b->ikey); 
    }
    return (b->number - a->number);
}

void sort_by_number() {  
    HASH_SORT(g_users, number_sort);  
}
void sort_by_id() {  
    HASH_SORT(g_users, id_sort);  
}
#endif

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    unsigned int num_users;
    char **returnWords;
    int i, j;
    struct my_struct *s, *tmp;
    //申请前K个字符串
    returnWords = (char **)malloc(sizeof(char *) * k);
    for (i = 0; i < k; i++) {
        returnWords[i] = (char *)malloc(sizeof(char) * 100);
    }
    if (wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    //添加节点
    for (i = 0; i < wordsSize; i++) {
        add_user(words[i], 1);
    }
    //排序
    sort_by_number();
    j = 0;
    //取前K个值。
    HASH_ITER(hh, g_users, s, tmp) {
        strncpy(returnWords[j], s->ikey, (strlen(s->ikey) + 1));
        j++;
        if (j >= k) {
            break;
        }
    }
    * returnSize= k;
    /* free the hash table contents */  
    HASH_ITER(hh, g_users, s, tmp) {  
      HASH_DEL(g_users, s);  
      free(s);  
    }
    g_users = NULL;
    return returnWords;
}
```