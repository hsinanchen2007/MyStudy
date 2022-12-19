之所以写在题解这里，是因为我做C的时候没找到。然后自己捣鼓了半天，指针老是整不对。
于是搜了下C的答案，并修改了放在这里。

解题思路：可以转换成i遍历0 ~ (2^n - 1)的问题，当数字i的某一位为1，则说明要选择数组中对应位置的数字。
比如[1, 2 ,3] 可以看出000~111共8种情况（0代表子集不含，1代表子集含，共3位）。对应returnSize就应该是8。

转载自：
--------------------- 
作者：hang-7788 
来源：CSDN 
原文：https://blog.csdn.net/hang404/article/details/85649569 

参考代码，通过了后可以去看前面，空间换时间的代码/试图摸鱼

```
int count(int num, int k) {
    int i = 0, count = 0;
    for(i = 0; i < k; i++) {
        if(num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = 1, i = 0, j = 0, k = 0;
    int t = (int)pow(2, numsSize);
    *returnSize = t;
    int** result = (int**)malloc(t * sizeof(int*));
    returnColumnSizes[0] = (int*)malloc(t * sizeof(int));  
    for(i = 0; i < t; i++) {
        returnColumnSizes[0][i] = count(i, numsSize);
        result[i] = (int*)malloc(returnColumnSizes[0][i] * sizeof(int));
        k = i;
        size = 0;
        for(j = 0; j < numsSize; j++) {
            if(k & 1)
                result[i][size++] = nums[j];
            k >>= 1;
        }
    }
    
    return result;
}
```
