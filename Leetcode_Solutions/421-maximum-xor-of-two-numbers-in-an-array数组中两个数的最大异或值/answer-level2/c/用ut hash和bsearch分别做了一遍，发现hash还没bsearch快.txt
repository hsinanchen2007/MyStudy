
qsort+bsearch的时间是116ms，hash的时间是212ms



代码：
```
typedef struct _ut_hash_
{
    int key;
    int value;
    UT_hash_handle hh;
}MY_UT_HASH_S;

int findMax(int* nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        if (result < nums[i]) result = nums[i];
    }
    return result;
}

int cmp(void* a, void*b)
{
    //printf("a:%u b:%u\n", *(int*)a, *(int*)b);
    return (*(int*)a - *(int*)b);
}

void hash_add(int key, MY_UT_HASH_S** hashTbl)
{
    MY_UT_HASH_S* hashItem = NULL;
    MY_UT_HASH_S* hashTmp = NULL;
    HASH_FIND_INT(*hashTbl, &key, hashItem);
    if (hashItem == NULL) {
        hashItem = (MY_UT_HASH_S*)malloc(sizeof(MY_UT_HASH_S));
        hashItem->key = key;
        HASH_ADD_INT(*hashTbl, key, hashItem);
        
        HASH_FIND_INT(*hashTbl, &key, hashTmp);
        //printf("key:%u hashTmp:%p hashItem:%p\n", key, hashTmp, hashItem);
    }
    return;
}

int findMaximumXOR(int* nums, int numsSize){
    int maxNum = 0;
    int bitLen = 0;
    int mask = 0;
    int temp = 0;
    int prefix = 0;
    int key = 0;
    int result = 0;

    int* prefixArry = (int*) malloc (sizeof(int)*numsSize);
    //memset(prefixArry, 0, sizeof(int)*numsSize);

    maxNum = findMax(nums, numsSize);
    bitLen = (log(maxNum)/log(2));

    for (int i = bitLen; i >= 0; i--) {
        mask |= 1 << i;
        MY_UT_HASH_S* hashTbl = NULL;
        MY_UT_HASH_S* hashTmp = NULL;

        for (int n = 0; n < numsSize; n++){
            prefix = mask & nums[n];          
            prefixArry[n] = prefix;
            //printf("i:%u key:%u prefixArry[%u]:%u\n", i, key, n, prefixArry[n]);
            hash_add(prefix, &hashTbl);
        }

        //qsort(prefixArry, numsSize, sizeof(int), cmp);  //此处为qsort+bsearch方法

        temp = result | (1 << i);
        
        for (int j = 0; j < numsSize; j++) {
            key = temp ^ prefixArry[j];
            int* searchR = NULL;
            //searchR = (int*)bsearch(&key, prefixArry, numsSize, sizeof(int), cmp);
            //printf("temp:%u result:%u i:%u key:%u prefixArry[%u]:%u searchR:%p\n", temp, result, i, key, j, prefixArry[j], searchR);
            HASH_FIND_INT(hashTbl, &key, hashTmp);
            //printf("i:%u j:%u temp:%u result:%u hashTmp:%p hashTbl:%p\n",i,j,temp,result,hashTmp,hashTbl);
            if (hashTmp) result = temp;
        }

    }
    free(prefixArry);
    return result;

}
```
