思路（1）计算截止到每个数的最大长度 （2）计算对应的cnt值，即次数 （3）算出所有cnt和，即结果

3个例题如下：
结果是cnt数组中最大的数。length为截止到该数的递增序列的长度。截止到i个数的，最大长度可以先计算出来。
输入         1  3  5  4  7  |||   [1,3,8,6,5,1,4,2]  ||| [1,2,4,3,5,4,7,2]
length []   1  2  3  3  4         1 2 3 3 3 1 3 2        1 2 3 3 4 4 5 2 

    cnt[]   1  1  1  1  2         1 1 1 1 1 2 1 2        1 1 1 1 2 1 3 1
    result        2                      2                       3
上面的这个cnt是包含最后一个数字的cnt，就是截止到i个数，并包含i个数：长度为length的cnt值。
        为了避免cnt重复计算，length要和前一个对比。

例如：在上述第3个例子中，length为5的数7，和length为4的数比较。nums的值 7 > 5, 7 > 4。所以length为5的，数值为7的cnt = 2 + 1

例如: 在上述的第3个例子中，length为4的数4，和length为3的数比较。nums的值4 > 3（这个cnt要算进去）, 4 == 4(不符合要求)。  所以length为4的数4，对应的cnt = 1, 

最后返回的 结果，是length为3的，所有cnt的和。 


```
#define MAX(A, B) (A) > (B) ? (A) : (B)

int findNumberOfLIS(int* nums, int numsSize){
    int i;
    int j;
    int result = 0;
    int maxLength = 1;
    int maxLengthPose = 0;

    if (numsSize == 0)
        return 0;

    int length[numsSize];
    int cnt[numsSize];

    memset(cnt, 0, sizeof(int) * numsSize);
    cnt[0] = 1;
    length[0] = 1;

    for (i = 1; i < numsSize; i++) { //截止到第i个数，计算length
        length[i] = 1;

        /* 计算出length */
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                length[i] = MAX(length[j] + 1, length[i]);
                
            }
        }

        /* 记录最大length */
        if (maxLength < length[i]) {
            maxLength = length[i];
        }

        /* 计算cnt */
        for (j = 0; j < i; j++) {
            if(length[i] - length[j] == 1) {
                if (nums[i] > nums[j]) {
                    cnt[i] += cnt[j];
                }
            } else if (length[i] == 1) {
                cnt[i] = 1;
            }
        }               
                
//        printf("i = %d, length = %d, cnt = %d\n", i, length[i], cnt[i]);

    }

    /* 把所有最大长度的cnt累加 */
    for (i = 0; i < numsSize; i++) {
        if (length[i] == maxLength) {
            result += cnt[i];
        }
    }


    return result;
}
```
