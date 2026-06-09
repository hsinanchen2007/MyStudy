### 解题思路
![image.png](https://pic.leetcode-cn.com/de4367841b9c2a29eb4cc6343b60f98bffe21c24c16473867dd5b1bec2490d77-image.png)

### 代码

```c
#define ARRAY_NUM 2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    if(NULL == nums || numsSize < 2)
    {
        return NULL;
    }

    int * res = (int *) malloc(sizeof(int)*ARRAY_NUM);
    memset(res,0,sizeof(int)*ARRAY_NUM);

    int xorRes = 0;

    for(int i = 0;i < numsSize;i++)
    {
        xorRes ^= nums[i];
    }

    int  bitmap = 1;
    while(1)
    {
        if((xorRes & 1) == 1)
        {
            break;
        }

        bitmap = bitmap << 1;
        xorRes = xorRes >> 1;

    }

    int y = 0;
    for(int i = 0; i < numsSize;i++)
    {
        if((nums[i] & bitmap) == 0)
        {
            res[0] ^= nums[i];
        }
        else
        {
            res[1] ^= nums[i];
        }
    }

    *returnSize = 2;

    return res;
}
```