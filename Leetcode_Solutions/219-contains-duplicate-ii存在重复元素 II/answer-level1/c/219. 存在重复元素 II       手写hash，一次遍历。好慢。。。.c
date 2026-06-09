### 解题思路
因为有负数，而且有最大int值，所以只能老实写hash了

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

 

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true


### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef struct node{
    int key;    
    int index;    //唯一的
    struct node* next;
}Node;

int htSize;

void hashAddOrUpdate(Node** ht, int key, int index){
    Node* newnode = malloc(sizeof(Node));
    newnode->key = key;
    newnode->index = index;
    newnode->next = NULL;
    //-2147483648 用abs 转换不了，得上labs
    //这个地址算法怎么弄都行，key的值不变就行
    int keyaddr = labs(key)%htSize;
    //printf("hashadd key=%d index=%d\n", key, index);
    if(ht[keyaddr] == NULL)
        ht[keyaddr] = newnode;
    else{
        Node* temp = ht[keyaddr];
        Node* last;
        while(temp){
            //printf("hashadd key=%d tempkey=%d, index=%d\n", key, temp->key, index);
            if (temp->key == key) {
                temp->index = index;
                free(newnode);
                return;
            }
            last = temp;
            temp= temp->next;
        }

        last->next = newnode;
    }
}

int hashGet(Node** ht, int key){
    int keyaddr = labs(key)%htSize;
    Node* temp = ht[keyaddr];

   // printf("0 hashget key=%d\n", key);
    while(temp){
       // printf("hashget key=%d tempkey=%d index=%d\n", key, temp->key, temp->index);
        if(temp->key == key)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int i, found;

    if (numsSize < 2)   return false;

    htSize = numsSize;
    Node ** hashtable = malloc(htSize * sizeof(Node *));
    for (i = 0; i < htSize; i++)
        hashtable[i] = NULL;

    for (i = 0; i < numsSize; i++) {
        found = hashGet(hashtable, nums[i]);
       //printf("i=%d numi=%d found=%d\n", i, nums[i],found);
        if(found >= 0 && i - found <= k)
            return true;
        
        hashAddOrUpdate(hashtable, nums[i], i);
    }
    return false;
}
```