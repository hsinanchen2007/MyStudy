### 解题思路
双100我只想记录下。
所以明明参考的别人的解题，为什么我的可以出来双百分百（基本都一样）。
话说力扣平台每次相同代码提交，时间内存啥的会有差距这正常吗？

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//returnSize是存的是有多少个结果，returnColumnSizes存的是每行有多少个元素
/* 暴力法, 思路: 1,...,target/2分别开始的可能的结果 */
/* 依次遍历, 遇到符合条件的结果进行输出 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int n = target / 2;
    int **res = (int**)malloc(sizeof(int *) * n);//动态分配行数
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);//动态分配行数？
    *returnSize = 0;
    int i, j, k, tmpTar;
    for(i = 1; i <= n; i++){   //这里的等于很重要
        tmpTar = target;
        j = i;
        while(tmpTar > 0){  //另类的求和判断，用减法
            tmpTar -= j;
            j++;
        }
        if(tmpTar == 0){   //找到和为target的序列
            //动态分配该行的列
            //这里不需要j-i+1的原因是上述while循环中结束循环时必然j多加了1
            res[*returnSize] = (int*)malloc(sizeof(int) * (j - i));
            for(k = i; k < j; k++)
                res[*returnSize][k - i] = k;
            (*returnColumnSizes)[*returnSize] = j - i;
            (*returnSize)++;  //带记录的行标自加
        }
    }
    return res;
}
```