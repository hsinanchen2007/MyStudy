### 解题思路
0.初始化存储数组A（大小为*matColSize）以及结果数组res（大小为k）
1.使用大小为*matColSize的数组A存储每行的军人数
2.从军人数为0开始，遍历数次数组A，依次把最小值存入res中，直到res存满为止。（该步骤实在是太浪费时间了，，，可是想不到没有其他方法，求帮助~~~~）

### 代码

```c
/*
first, count every rows' 1s, and stores them in a colsize array
then using a int small to select these k cols for return.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    *returnSize = 0;
    int i,j,small=0,num=0;
    int* arr = (int *)malloc(sizeof(int)*(matSize));
    //printf("matSize=%d, *matColSize =%d\n",matSize, *matColSize);
    
    for(i=0;i<matSize;i++)//initialize the array
        arr[i]=0;
    
    for(i=0;i<matSize;i++){
        for(j=0;j<*matColSize && mat[i][j]==1;j++)
            arr[i]++;
    }//calculate the solder num
    
    int* res = (int *)malloc(sizeof(int)*k);
    while(num!=k){//traverse all the small situations
        for(i=0;i<matSize;i++){
            if(arr[i]==small && num<k){
                res[num]=i;
                num++;
            }
        }
        small++;
    }
    
    *returnSize = k;
    return res;
}

```