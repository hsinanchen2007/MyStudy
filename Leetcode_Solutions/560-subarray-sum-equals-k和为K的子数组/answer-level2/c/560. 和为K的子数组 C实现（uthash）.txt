### 解题思路

    练习uthash使用选做的一题，发现几个注意点：

        要确保哈希表的头指针定义和HAHS_ADD及HASH_FIND等操作处于同一作用域内（函数体（内联函数无效））
    ，若不同作用域需要传入头指针的地址（二级指针），否则操作过程中会得到一些很奇怪的答案。

        一定要记得释放内存，不然提交的答案和执行代码的结果不一样，这个还没有深入研究过，目前的猜想是后台
    测试用例并发测试全局变量地址被共享（并且hash值的计算方式相同插入相同键值对（entry）的时候会计算出相同
    的地址），导致HASH TABLE数据污染，而执行代码只针对一个测试用例所以正确，故导致提交和执行代码的结果不
    一样。
        如果不想释放内存的解决办法只有一个就是将头指针设置为非全局变量。

    有空会去研究一下uthash.h的源码看看ADD及FIND操作无效是怎么回事。

    总结，uthash的使用注意两点：
    1.table头指针以非全局变量的形式定义；
    2.涉及到uthash.h中的宏定义形式的操作（如HASH_ADD、HASH_FIND）尽量在table的头指针的作用域内使用。

### 代码

```c
typedef struct hash_entry {
    int key;
    int val;
    UT_hash_handle hh;
} entry;

entry* FindHash(entry** hashMap, int k)
{
    entry* ret = NULL;
    HASH_FIND_INT(*hashMap, &k, ret);
    return ret;
}

bool AddHash(entry** hashMap, int k, int v)
{
    entry* ret = NULL;
    HASH_FIND_INT(*hashMap, &k, ret);
    if (ret == NULL) {
        entry* p = (entry*)malloc(sizeof(entry));
        p->key = k;
        p->val = v;
        HASH_ADD_INT(*hashMap, key, p);
        return true;
    } else {
        ret->val++;
        return false;
    }     
}

void DeleteHash(entry** hashMap) {  
    entry *current_entry, *tmp;  
    HASH_ITER(hh, *hashMap, current_entry, tmp) {  
    HASH_DEL(*hashMap,current_entry);    
    free(current_entry);              
    }  
}

int subarraySum(int* nums, int numsSize, int k){
    if (!nums || numsSize <= 0) {
        return 0;
    }
    int cnt = 0;
    int sum = 0;
    entry* hashMap = NULL;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        AddHash(&hashMap, sum - nums[i], 1);
        entry* find = FindHash(&hashMap, sum - k);
        if (find) {
            cnt += find->val;
        }
    }
    DeleteHash(&hashMap);
    return cnt;
}
```