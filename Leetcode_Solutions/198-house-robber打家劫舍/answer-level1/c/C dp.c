### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)
int rob(int* nums, int numsSize){
    int cur = 0;
    int pre = 0;
    for (int i = 0; i < numsSize; i++) {
        int tmp = cur;
        cur = MAX(pre+nums[i], cur);
        pre = tmp;
    }
    return cur;
}
```