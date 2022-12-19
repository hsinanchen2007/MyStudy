# 下面是我的代码

```
#define true -1
#define false 0
#ifndef NULL
#define NULL 0
#endif

typedef struct _tempnode{   //链表法hashmap的节点对象
    int key;
    int value;
    struct _tempnode * next;
}Node;

typedef struct{     //链表法hashmap
    Node ** values;
    int size;
}HashMap;

HashMap * createHashMap(int);   //创建指定大小的hashmap
int hasKey(HashMap *, int);   //查找某个key是否存在
int getValue(HashMap *, int);   //获取某个key对应的value（应该先调用hasKey）
void putValue(HashMap *, int, int);     //放入键值对
void destoryHashMap(HashMap *); //释放内存

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int * result = (int *)malloc(sizeof(int) * *returnSize);
    HashMap * hashmap = createHashMap(20);
    for (int i = 0; i < numsSize; ++i){
        if (hasKey(hashmap, target - nums[i])){ //一遍哈希即可，要注意已经存在的放在前面（result[0]）           
            result[0] = getValue(hashmap, target - nums[i]);
            result[1] = i;
            destoryHashMap(hashmap);
            return result;
        }
        putValue(hashmap, nums[i], i);
    }
    destoryHashMap(hashmap);
    return NULL;
}

HashMap * createHashMap(int size){
    HashMap * hashmap = (HashMap *)malloc(sizeof(HashMap));
    hashmap->values = (Node **)malloc(size * sizeof(Node *));
    hashmap->size = size;
    for (int i = 0; i < size; ++i){
        hashmap->values[i] = NULL;
    }
    return hashmap;
}

int hasKey(HashMap * hashmap, int key){
	int backupKey = key;
    key = key % hashmap->size;  //为简单起见，直接用取余数求哈希值
    if (key < 0){
        key += hashmap->size;
    }
    Node * ptr = hashmap->values[key];
    while (ptr != NULL){
        if (ptr->key == backupKey){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

int getValue(HashMap * hashmap, int key){
	int backupKey = key;
    key = key % hashmap->size;
    if (key < 0){
        key += hashmap->size;
    }
    Node * ptr = hashmap->values[key];
    while (ptr != NULL){
        if (ptr->key == backupKey){
            return ptr->value;
        }
        ptr = ptr->next;
    }
    return -1;
}

void putValue(HashMap * hashmap, int key, int value){
    int backupKey = key;
    key = key % hashmap->size;
    if (key < 0){
        key += hashmap->size;
    }
    if (hashmap->values[key] == NULL){
        hashmap->values[key] = (Node *)malloc(sizeof(Node));
        hashmap->values[key]->key = backupKey;
        hashmap->values[key]->value = value;
        hashmap->values[key]->next = NULL;
    }
    else {
        Node * ptr = hashmap->values[key];
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = (Node *)malloc(sizeof(Node));
		ptr = ptr->next;
        ptr->key = backupKey;
        ptr->value = value;
        ptr->next = NULL;
    }
}

void destoryHashMap(HashMap * hashmap){
    for (int i = 0; i < hashmap->size; ++i){
        Node * ptr = hashmap->values[i];
        while (ptr != NULL){
            Node * next_ptr = ptr->next;
            free(ptr);
            ptr = next_ptr;
        }
    }
    free(hashmap);
}

```
