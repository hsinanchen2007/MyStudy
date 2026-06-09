
```
struct frac {
    int num; 
    int deno;
};

static int cmp_frac(const void *p1, const void *p2)
{
    const struct frac *t1;
    const struct frac *t2;
    
    t1 = (const struct frac *)p1;
    t2 = (const struct frac *)p2;
    
    if (t1->deno == t2->deno)
        return t1->num - t2->num;
    
    
    return t1->num * t2->deno - t2->num * t1->deno;
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* A, int ASize, int K, int* returnSize){
    int room;
    struct frac *k_set;
    struct frac *k_tmp;
    int i, j, k;
    int tmp;
    int *answer;
    
    room = ASize * (ASize - 1) / 2;
    k_set = (struct frac *)malloc(sizeof(struct frac) * room);
    if (NULL == k_set)
    {
        return NULL;
    }  
    
    k = 0;
    k_tmp = k_set;
    for (i = 0; i < ASize; i++)
    {
        tmp = A[i];
        for (j = ASize - 1; j > i; j--)
        {
            k_tmp->num = tmp;
            k_tmp->deno = A[j];
            k_tmp++;
        }
    }
    
    qsort(k_set, room, sizeof(struct frac), cmp_frac);
    answer = malloc(sizeof(int) * 2);
    answer[0] = k_set[K - 1].num;
    answer[1] = k_set[K - 1].deno;
    *returnSize = 2;
    free(k_set);
    
    return answer;
}
```
