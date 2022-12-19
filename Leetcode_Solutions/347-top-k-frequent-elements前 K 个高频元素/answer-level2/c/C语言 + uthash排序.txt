```
struct HASH_NODE{
    int key;
    int count;
    UT_hash_handle hh;
};
int compfunc(struct HASH_NODE* a, struct HASH_NODE* b){
    return b->count - a->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int i;
    struct HASH_NODE *head = NULL;
    struct HASH_NODE *pNode = NULL, *p = NULL,*s = NULL;

    pNode = (struct HASH_NODE*)malloc(numsSize * sizeof(struct HASH_NODE));

    for(i = 0; i< numsSize;i++){
        pNode[i].count = 1;
        pNode[i].key = nums[i];

        HASH_FIND_INT(head,&nums[i],p);
        if(p == NULL){
            p = &pNode[i];
            HASH_ADD_INT(head,key,p);
        } else {
            p->count++;
        }
    }

    i = 0;
    HASH_SORT(head,compfunc);
    HASH_ITER(hh,head,p,s){
        if(i < k)
        nums[i++] = p->key;
    }
    *returnSize = k;
    return nums;
}
```
