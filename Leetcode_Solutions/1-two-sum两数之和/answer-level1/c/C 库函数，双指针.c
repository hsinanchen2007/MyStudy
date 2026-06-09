### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了99.75%的用户
内存消耗 :6.4 MB, 在所有 C 提交中击败了100.00%的用户

结构体保存数值与下标，使用qsort对结构体数组按照数值成员升序排序，使用头尾双指针法，比较头尾数值之和与target，返回相等时的下标。

### 代码

```c

struct NODE
{
    int val;
    int pos;
};

int cpr(const void* a, const void* b){
    return ((struct NODE*)a)->val - ((struct NODE*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//double-point
    int head = 0;
    int tail = numsSize -  1;
    int sum = 0;
    struct NODE* numNode = NULL;
    int *result = NULL;
    result = (int*)malloc(sizeof(int) * 2);
    numNode = (struct NODE*)malloc(sizeof(struct NODE) * numsSize);

    for(int i = 0; i < numsSize; i++){
        numNode[i].val = nums[i];
        numNode[i].pos = i;
    }
    //rise sort
    qsort(numNode, numsSize, sizeof(struct NODE), cpr);

    while(head < tail){
        sum = numNode[head].val + numNode[tail].val;
        if(sum > target){
            tail--;
        }else
        if(sum < target){
            head++;
        }else{
            result[0] = numNode[head].pos;
            result[1] = numNode[tail].pos;
            break;
        }
    }
    free(numNode);
    *returnSize = 2;
    return result;
}
```