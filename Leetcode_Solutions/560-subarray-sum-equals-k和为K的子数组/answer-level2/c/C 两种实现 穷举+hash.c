# **1、穷举**
![image.png](https://pic.leetcode-cn.com/d17e69a0d29d03967394826cf27911912b2f31df1d9ad3ce5c8338d682422855-image.png)

```
int subarraySum(int* nums, int numsSize, int k){
    int count = 0;
    int times = 0;

    for (int i = 0; i < numsSize; i++) {
        count = nums[i]; //逐个统计包含第i个数的子数组
        if (count == k) {
            times++;
        }        
        for (int j = i + 1; j < numsSize; j++) {
            count += nums[j];
            if (count == k) {
                times++;
            }
        }
    }

    return times;
}
```
# **2、hash实现**
pi = a[0] + a[1] + ... + a[i]，pj =  a[0] + a[1] + ... + a[j]。
pj - pi = a[i + 1] + a[i + 2] + ... + a[ j ] = K 即满足条件
![image.png](https://pic.leetcode-cn.com/5b58614a49a3d3e2d5443beda021e7c2c3a593faa93f530dabb7374dc89786ea-image.png)

```
struct hashNode {
    int key;
    int value;
    struct hashNode *next;
};

struct hashMap {
    int size;
    struct hashNode *data;
};

struct hashMap * hashCreat(int size)
{
    struct hashMap * hashMapInfo;

    hashMapInfo = (struct hashMap *)malloc(sizeof(struct hashMap));
    hashMapInfo->size = size;
    hashMapInfo->data = (struct hashNode *)malloc(sizeof(struct hashNode) * size);

    for (int i = 0; i < size; i++) {
        hashMapInfo->data[i].value = 0;
        hashMapInfo->data[i].key = INT_MIN;
        hashMapInfo->data[i].next = NULL;
    }

    return hashMapInfo;
}

void Put(int key, struct hashMap * hashMapInfo)
{
    int pos = abs(key) % hashMapInfo->size;
    struct hashNode *data = &hashMapInfo->data[pos];
    struct hashNode *newNode = NULL;

    if (data->key == INT_MIN) {  //链表未占用
        data->key = key;
        data->value = 1;
        return;
    }
    
    while (data != NULL) {//while循环要考虑当前节点，不能从data->next开始
        if (data->key == key) { //当前链表已存在该key
            data->value++;
            return;
        } 
        
        if (data->next == NULL) { //未后续添加Node做准备
            break;
        }
        data = data->next;
    }

    /* 添加节点 */
    newNode = (struct hashNode *)malloc(sizeof(struct hashNode));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = NULL;
    data->next = newNode;

    return;
}

int Get(int key, struct hashMap * hashMapInfo)
{
    int count = 0;
    int pos = abs(key) % hashMapInfo->size; //选择hash桶
    struct hashNode *data = &hashMapInfo->data[pos];

    while (data != NULL) { /*遍历链表，匹配key*/
        if (data->key == key) {
            count = data->value;
            break;
        }
        data = data->next;
    }

    return count;
}

int subarraySum(int* nums, int numsSize, int k){
    int sum = 0;
    struct hashMap *hashMapInfo;
    int times = 0;

    hashMapInfo = hashCreat(numsSize); 
    Put(0, hashMapInfo); //初始化为0，这个很重要，后续sum=k时需要

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        times += Get(sum - k, hashMapInfo);
        Put(sum, hashMapInfo);
    }

    return times;
}
```
