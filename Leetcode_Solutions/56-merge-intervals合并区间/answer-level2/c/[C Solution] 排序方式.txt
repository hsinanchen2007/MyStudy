### 解题思路

有两种通用解题方式：
（1）分治归并思路，
（2）排序方式
这两种的时间复杂度其实很接近，
分治归并基本本归并排序的时间复杂度一致O(nlogn) ，
而排序方式库函数基本用优化过的快排O(nlogn)，

而且分治归并的实现复杂度高，所以用排序方式，易懂易实现。

看到针对c刷题的模版，总结的特别好，推荐[https://leetcode-cn.com/problems/merge-intervals/solution/chun-c-leetcodeer-wei-shu-zu-can-shu-shi-yong-xiao/](https://leetcode-cn.com/problems/merge-intervals/solution/chun-c-leetcodeer-wei-shu-zu-can-shu-shi-yong-xiao/)

### 代码

```c


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


// 返回值小于 0（< 0），那么 p1 所指向元素会被排在p2所指向元素的前面
// 返回值等于 0（= 0），那么 p1 所指向元素与 p2 所指向元素的顺序不确定
// 返回值大于 0（> 0），那么 p1 所指向元素会被排在 p2 所指向元素的后面。
int comp(const int* a , const int* b){
    return *(int*)a - *(int*)b ;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(sizeof(int*)*intervalsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int)*intervalsSize);

    int* leftArr = (int*)malloc(sizeof(int)*intervalsSize);
    int* rightArr = (int*)malloc(sizeof(int)*intervalsSize);
    int row = 0 , col = 0 ;
    for(int i = 0 ; i <  intervalsSize ;i++){
        ret[i] = (int*)malloc(sizeof(int)*2);
        leftArr[row++] = intervals[i][0];
        rightArr[col++] = intervals[i][1];
    }

    qsort(leftArr , intervalsSize , sizeof(int) , comp);
    qsort(rightArr , intervalsSize , sizeof(int) , comp);

    for(int i = 0 ; i< intervalsSize ;i++){
        ret[*returnSize][0] = leftArr[i];
        for(; i < intervalsSize -1 ; i++){
            if(leftArr[i+1] > rightArr[i] ){
                break;
            }
        }
        ret[*returnSize][1] = rightArr[i];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return ret;


}


```