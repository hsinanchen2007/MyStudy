### 解题思路
方法一： 通过两重循环，时间复杂度为（O(N^2)）;
方法二：哈希表，哈希函数为hash(key) = abs(key) % numSize;

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * r = (int *) malloc(sizeof(int)*2);
    memset(r, 0, sizeof(r));
    *returnSize = 2;

    for(int i = 0; i < numsSize;i++){
        for(int j = i + 1; j < numsSize;j++){
            if(nums[i] + nums[j] ==  target){
                r[0] = i;
                r[1] = j;
                return r;
            }
        }
    }
    return r;
}
```


```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct Node{
     int key;
     int pos;
     struct Node * next;
 } Node;

 int hash(int key, int numsSize)
 {
     return abs(key) % numsSize;
 }

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int *)malloc(sizeof(int)*2);
    Node *hashtable = (Node *)malloc(sizeof(Node)* numsSize);
    *returnSize = 2;
    memset(res, -1, sizeof(int)*2);
    memset(hashtable, 0, sizeof(Node)*numsSize);

    for(int i = 0; i< numsSize;i++){
        int addr = hash(nums[i], numsSize);
        Node *p = (Node *)malloc(sizeof(Node));
        p->key = nums[i];
        p->pos = i;
        p->next = NULL;

        p->next = hashtable[addr].next;
        hashtable[addr].next = p;
        int addr2 = hash(target-nums[i], numsSize);
        Node * q = hashtable[addr2].next;
        while(q != NULL){
            if(q->key + nums[i] == target && q->pos != i ){
                res[0] = q->pos;
                res[1] = i;
                return res;
            }
            q = q->next;
        }  
    }

    return res;
}
```
