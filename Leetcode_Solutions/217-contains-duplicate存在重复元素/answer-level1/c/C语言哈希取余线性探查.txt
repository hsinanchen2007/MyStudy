
这个题想起来也不难，自己就想用纯粹的算法解一下，结果超时。
我也想不明白，哈希表复杂度也不高啊，究竟是哪里浪费了时间？
有没有大佬给我点拨一下。
用了很简洁的一个结构体，value存储真实值，用来比较冲突点。isempty用来判空。
哈希函数是 先求绝对值，再取余。
冲突解决方法就是 挨着找下一个空。
看了下最后一个测试用例，负数正数一共20w个，其实用 *-1 处理负数不好，至少造成 n/2 的冲突。
试了试 取反 处理负数，但是还是超时。纳闷了。

```
// 1 暴力比较，时间复杂度 n^2 
// 2 用空间换时间，定义大小为 Maxnum 的数组，遍历一次数组，在数组中存储访问次数。时间复杂度 n
//   有一个弊端，当数组中有一个特别大的值时，会浪费空间。
// 3 可以用哈希表代替 2 的数组。不太会写太复杂的，就写个取余的hashmap。

typedef struct hashnode{
    int value;
    bool isempty;
}hash;

bool containsDuplicate(int* nums, int numsSize){
    // 分配 hashmap 内存，因为用取余作为 hash 函数，因此就分 Size 大小吧
    hash* hashmap = (hash*)malloc(sizeof(hash) * numsSize);
    if(hashmap == NULL){
        printf("malloc false!");
        return false;
    }
    // 初始化 hashmap。好麻烦😂。
    int i = 0;
    int index = 0;
    for(i;i<numsSize;i++){
        // hashmap[i]->key = 0;
        // hashmap[i]->value = 0;
        hashmap[i].isempty = true;
    }
    // 遍历数组
    for(i=0;i<numsSize;i++){
        if(nums[i] < 0)
            index = -1 * nums[i] % numsSize;
        else
            index = nums[i] % numsSize;
        // 可能有 n 个非空位置，循环检测。
        // 因为 hashmap 的大小等于 numsSize，因此每一个项都有位置。
        while(!hashmap[index].isempty){
            if(hashmap[index].value == nums[i])
                return true;
            else
                index = (++index) % numsSize;
        }
        // 找到空位置，且前 n 个都未匹配。
        hashmap[index].isempty = false;
        hashmap[index].value = nums[i];
    }
    return false;
}


```
