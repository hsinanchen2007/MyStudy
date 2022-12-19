辗转多次，终于解决了！
![t.png](https://pic.leetcode-cn.com/941b6f73fd1f91976f4d58323b2ea873ad23f6d8d4cf2e66af13223064f0312b-t.png)

**思路：**
如果只有数字只有1位，直接返回；

倒数第1位数比倒数第2位数大，交换这两个数，返回；

从倒数第2位开始，到第2位，如果本位数大于前1位数，从倒数第1位开始，找到第1个比前1位数大的数
（也有可能找不到，单独处理），交换这两个数，将本位数到最后1位数非递减排序；

特殊情况:没有找到第1个比本位数小的数（比如2,3,1），直接交换本位数和它的前1位数，再本位数到最后1位数非递减排序。（如果不排序，2,3,1将输出3,2,1，而正确答案为3,1,2）

代码如下：

```
//排序函数
int cmp(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

//交换两数位置函数
void swap(int *a, int *b){
    int t;
    
    t = *a;
    *a = *b;
    *b = t;
}
void nextPermutation(int* nums, int numsSize){
    int i, j;
    int t;
    if (numsSize == 1)
        return;

    if (nums[numsSize - 1] > nums[numsSize - 2]){
        swap(&nums[numsSize - 2], &nums[numsSize - 1]);
        return;
    }

    /*从倒数第2位开始，到第2位，
    如果本位数大于前1位数，
    */
    for (i = numsSize - 2; i > 0; i--){
        if (nums[i] > nums[i - 1]){
            /*从倒数第1位开始，找到第1个比前1位数大的数
            （也有可能找不到，单独处理），交换这两个数，将本位数到最后1位数非递减排序；
            */
            for (j = numsSize - 1; j > i; j--){
                if (nums[j] > nums[i - 1]){
                    swap(&nums[j], &nums[i - 1]);
                    qsort(&nums[i], numsSize - i, sizeof(nums[0]), cmp);
                    break;//注意
                }
            }

            /*特殊情况:没有找到第1个比本位数小的数（比如2,3,1），
            直接交换本位数和它的前1位数，再本位数到最后1位数非递减排序。
            （如果不排序，2,3,1将输出3,2,1，而正确答案为3,1,2）*/
            if (j == i){
                swap(&nums[i], &nums[i - 1]);
                qsort(&nums[i], numsSize - i, sizeof(nums[0]), cmp);
            }
            break;//注意
        }
    }
    //非递增数列（如4,3,2,1）
    if (i == 0){
        qsort(nums, numsSize, sizeof(nums[0]), cmp);
    }
    return;
}
```
