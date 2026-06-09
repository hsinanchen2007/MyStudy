回溯找到符合条件的解，用哈希去重
```
#define MAX_SIZE 100000
int g_res[4] = {0};
int g_count = 0;
int g_index = 0;
int **g_result = NULL;
int *g_colSize = NULL;

struct hash_entry {
    int id;            /* we'll use this field as the key */
    int val;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *users = NULL;

void add_user(struct hash_entry *s) {
    HASH_ADD_INT(users, id, s);
}
struct hash_entry *find_user(int user_id) {
    struct hash_entry *s;
    HASH_FIND_INT(users, &user_id, s);
    return s;
}
int Comp(void *a, void*b) {
    return *(int*)a - *(int*)b;
}
long long GetHash(char *str, int len) {
    int seed = 13313133131;  
    long long hash = 0;
    for(int i = 0; i < len; str++, i++)   
    {   
      hash = (hash * seed) % MAX_SIZE + (*str);   
    }   
    return hash;   
}  

int SaveRes() {
    char *str = (char*)malloc(200 * sizeof(char));
    snprintf(str, MAX_SIZE, "%d,%d,%d,%d", g_res[0], g_res[1], g_res[2], g_res[3]);
    long long key = GetHash(str, strlen(str)); 
    free(str);
    struct hash_entry *s = find_user(key);
    if (s != NULL) {
        //printf("id = %d, val = %d\n", s->id, s->val);
        return 0;
    }
    s = (struct hash_entry*)malloc(sizeof(struct hash_entry));
    s->id = key;
    s->val = key;
    add_user(s);
    g_result[g_index] = (int*)malloc(g_count * sizeof(int));
    memset(g_result[g_index], 0, g_count * sizeof(int));
    g_colSize[g_index] = 4;
    for (int i = 0; i < g_count; i++) {
        g_result[g_index][i] = g_res[i]; 
    }
    g_index++;
    return 0;
}
int DFS(int* nums, int size, int target, int index) {
    if (g_count == 4) {
        if (target == 0) {
            SaveRes();
        } 
        return 0;
    }
        
    for (int i = index; i < size; i++) {
        g_res[g_count++] = nums[i];
        DFS(nums, size, target - nums[i], i + 1);      
        g_count--;
    }
    return 0;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    if (numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(nums[0]), Comp);
    g_result = (int**)malloc(MAX_SIZE * sizeof(int*));
    memset(g_result, 0, MAX_SIZE * sizeof(int*));
    returnColumnSizes[0] = (int*)malloc(MAX_SIZE * sizeof(int));
    g_colSize = returnColumnSizes[0];
    users = NULL;
    memset(g_res, 0, 4 * sizeof(int));
    g_count = 0;
    g_index = 0;
    DFS(nums, numsSize, target, 0);
    *returnSize = g_index;
    return g_result;
}
```
