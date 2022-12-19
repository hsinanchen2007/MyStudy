#define HashSize 2000  //值大小是实验出来的

typedef struct {
    int count;
    int num;
} HashTable;

int cmp(const void *a, const void *b) {
    return (((HashTable*)a)->count - ((HashTable*)b)->count);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){

    HashTable hash[HashSize];
    memset(hash, 0, sizeof(hash));
    //创建hashtable，数组元素作为key，元素出现的次数(频率)作为键值
    for(int i = 0; i < numsSize; i++) {
        hash[(nums[i] + HashSize)%HashSize].count++;
        hash[(nums[i] + HashSize)%HashSize].num = nums[i];
    }
    
    //对hashtable 重新排序，因为hash表创建的过程中键存在空隙    
    int cnt = 0;
    for(int i = 0; i < HashSize; i++){
        if(hash[i].count != 0) {
            hash[cnt].count = hash[i].count;
            hash[cnt].num = hash[i].num;
            cnt++;
        }
    }  

    //对hashtable，按照频率进行排序，从小到大
    qsort(hash, cnt, sizeof(HashTable), cmp);

    //输出频率前k高的元素
    int *res = (int*)calloc(k, sizeof(int));
    for(int i = 0; i < k; i++) {
        res[i] = hash[cnt - i - 1].num;
    }
    *returnSize = k;

    return res;
}
