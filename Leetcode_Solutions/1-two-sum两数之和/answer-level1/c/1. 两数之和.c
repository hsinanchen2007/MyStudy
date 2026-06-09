### 解题思路

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]



### 代码

```c
struct Hashdata{
    int key;
    int value;
    struct Hashdata *next;
};

typedef struct{
    struct Hashdata **head;
    int ht_width;
}Hashtable;

struct Hashdata * hashaddr(Hashtable * ht, int key){
    /*map 公式， 负数abs转成正的来计算。 取相同计算结果的链表*/
    int k = abs(key) % ht->ht_width;
    return ht->head[k];
}

struct Hashdata * hashfind(struct Hashdata *hdata, int key){
    while(hdata){
        if(hdata->key == key){
            //printf("cyx find key=%d\n",key);
            return hdata;
        }
        if(hdata->next)
            hdata = hdata->next;
        else
            return NULL;
    }
    return NULL;
}

int hashinsert(int key, int val, Hashtable * ht){
    struct Hashdata * hdata =(struct Hashdata *) malloc(sizeof(struct Hashdata));
    struct Hashdata * haddr = hashaddr(ht, key);
    int k;

    hdata->key = key;
    hdata->value = val;
    hdata->next = NULL;

    if(haddr == NULL){
        /*桶里此项链表为空，则为链表头*/
        k = abs(key)% ht->ht_width;
        ht->head[k] = hdata;
    }else{
        /*桶里此项链表有节点，则加入链表末尾*/
        while(haddr->next)
            haddr = haddr->next;
        /*新alloc的加入链表尾部*/
        haddr->next = hdata;
    }
    return 0;
}

int hashinit(Hashtable *ht, int width){
    
    ht->head = (struct Hashdata **)malloc(width * sizeof(struct Hashdata *));
    memset(ht->head, 0, width * sizeof(struct Hashdata *));
    ht->ht_width = width;
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, key;
    
    Hashtable ht;
    struct Hashdata *hdata;

    hashinit(&ht, numsSize);
    for(i=0;i<numsSize;i++){
        hashinsert(nums[i], i, &ht);
    }


    for(i=0; i<numsSize; i++){
        key = target - nums[i];
        hdata = hashaddr(&ht, key);
        hdata = hashfind(hdata, key);
        /*防止同一个数据重复使用，比如target 为6，num[i]为3，hashtable会找到这个num[i]*/
        if(hdata && hdata->value != i){
           // printf("cyx %d %d\n",nums[i], nums[hdata->value] );
            nums[0] = i;
            nums[1] = hdata->value;
            *returnSize = 2;
            return nums;
        }
    }
    *returnSize = 0;
    return nums;
}
```