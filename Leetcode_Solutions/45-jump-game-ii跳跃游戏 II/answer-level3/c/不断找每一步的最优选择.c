### 解题思路
1、新建每个数字对应能跳最远的数组 index[i] = muns[i] + 1;
2、每一步都是跳到index区域中最大的那个数，通过Max函数计算 //关键
3、依次跳下去

### 代码
```c
int *Max(int *num, int size){
    int *tmp = num;
    if (size == 1)
        return tmp;

    for (int k = 1; k < size; k++) {
        if (*(num + k) >= *tmp) {
            tmp = num + k;        
        }
    }
    return tmp;
}

int jump(int* nums, int numsSize){
    int *h = nums;
    int *t = NULL;
    int i = 0; 

    if (numsSize <= 1)
        return 0;

    int index[numsSize];
    for (int i = 0; i < numsSize; i++) {
        index[i] = nums[i] + i;
    }

    int *h1 = index;
    int *t1 = NULL;

    while(1) {
        i++;
        if ((*h + (h - nums) + 1) >= numsSize) { 
            break;
        }
        t1 = Max((h1 + 1), *h);
        h = h + (t1 - h1);
        h1 = t1;
    }

    return i;
}
```