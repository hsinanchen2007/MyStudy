### 解题思路
增加一个坐标转换之后，就直接变成了二分法查找

![image.png](https://pic.leetcode-cn.com/95404ddfe5cab582b87c4317c56e182eaed5321547d3bfd2ad4257958da92647-image.png)

### 代码

```c
#define MY_NUM_2 2

typedef struct {
    int *nums;
    int numsSize;
    int target;
    int base;
} MyStatus;

int findBase(int *nums, int numsSize) 
{
    int i;
    int base = 0;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            base = i + 1;
            break;
        }
    }
    return base;
}
void sInit(MyStatus *s, int* nums, int numsSize, int target)
{
    s->nums = nums;
    s->numsSize = numsSize;
    s->target = target;
    s->base = findBase(nums, numsSize);
    return;
}
inline int transInx(MyStatus *s, int inx)
{
    return (inx + s->base) % s->numsSize;
}
inline int getValue(MyStatus *s, int inx)
{
    return s->nums[transInx(s, inx)];
}
int proc(MyStatus *s)
{
    int rlt = -1;
    int val;
    int l, mid, r;
    l = 0;
    r = s->numsSize - 1;
    while(l <= r) {
        mid = (l + r) / MY_NUM_2;
        val = getValue(s, mid);
        if (val < s->target) {
            l = mid + 1;
        } else if (val > s->target) {
            r = mid - 1;
        } else {
            rlt = transInx(s, mid);
            break;
        }
    }
    return rlt;
}
int search(int* nums, int numsSize, int target){
    MyStatus s;
    if (numsSize == 0 || nums == NULL) {
        return -1;
    }
    if (numsSize == 1) {
        return target == nums[0] ? 0 : -1;
    }
    sInit(&s, nums, numsSize, target);
    return proc(&s);
}
```