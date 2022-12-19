### 解题思路
1.思路比较简单：利用两层循环去实现题目要求的解码算法即可。
2.corner condition：
这题在corner condition上几乎没有设置障碍，良心题，O(∩_∩)O哈哈~
3.经验教训：
最开始是想用memset对数据做批量赋值，从而达到时间复杂度位O（n）。但从test的结果看，没有实现，进而采用两层循环来实现。后面可以用visual studio研究一下如何用memset对数据做批量设置。
4.耗时：30mins，及格吧，要是没有memset的尝试的话，20mins以内应该没问题。

![image.png](https://pic.leetcode-cn.com/1d82c7b5d1f5db93293432d6c43b83870e5a0b9f84fa387d07c0d9048a9505c8-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 5000

int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int ret[MAXSIZE] = {0};
    int temp = 0;
    int *end = NULL;

    for(i = 0, j = 0; i < numsSize/2; i++) {
        //temp = nums[2 * i + 1];
        //memset(&ret[j], temp, nums[2 * i] * sizeof(int));
        k = nums[2 * i];
        while (k != 0) {
            ret[j] = nums[2 * i + 1];
            j++;
            k--;
        }
    }
    //printf("j = %d\n",j);
    *returnSize = j;
    end = (int *)malloc(j * sizeof(int));
    memset(end, 0x00, j * sizeof(int));
    memcpy(end, ret, j * sizeof(int));    
    return end;
}
```