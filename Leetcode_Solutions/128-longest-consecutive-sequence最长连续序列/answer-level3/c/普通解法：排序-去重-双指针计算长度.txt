### 解题思路
1、排序 （注意int溢出，cmp函数的写法）
2、去重
3、用双指针计算最长长度

### 代码
```c
int cmp(const void* a, const void* b)
{
    int pa = *(int *)a;
    int pb = *(int *)b;

    if (pa > pb) {
        return 1;
    } else if (pa = pb) {
        return 0;
    } else {
        return -1;
    }
}

int delmore(int* nums, int numsSize, int* buf) 
{
    int *p = nums;
    int *pb = buf + 1;
    int *q;
    int res = 1;

    int i = 1; 
    while (i < numsSize) {
        q = nums + i;
        if (*q != *p) {
            *pb = *q;
            p = q;
            pb++;
            res++;
        } 
        i++;
    }
    
    return res;
}

int longestConsecutive(int* nums, int numsSize){
    if (numsSize <= 1) {
        return numsSize;
    }

    int buf[numsSize];
    int bufsize = numsSize;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    buf[0] = nums[0];
    bufsize = delmore(nums, numsSize, buf);
 
    int i = 1;
    int* p = buf;
    int* h = p;
    int* q = p + 1;
    int Maxlen = 1;

    while (i < bufsize) {
        if (*q != *p + 1) {
            h = q;
            p = q;
        } else {
            p++;            
        }
        q++;
        Maxlen = Maxlen > (q - h) ? Maxlen : (q - h);
        i++;
    }
     
    return Maxlen;
}
```