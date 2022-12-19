![image.png](https://pic.leetcode-cn.com/aa046e01cd970515551edfccbd373352062b615557f49a6bbcd5ed069c1d811e-image.png)

如何判断两个区间是否重叠呢?
比如 [[1,4],[2,3]]
令：a = [1,4],b = [2,3]
当 a[1] >= b[0] 说明两个区间有重叠.

 int compare(const void *a, const void *b){
     return (**(int**)a-**(int**)b);
 }
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if(intervals==NULL || intervalsSize==0){
        *returnSize=0;
        return NULL;
    }
    int i,m=0;
    int **ret;
    qsort(intervals,intervalsSize,sizeof(int *),compare);       /*对intervals升序排序*/
    ret=malloc(sizeof(int *)*intervalsSize);
    *returnColumnSizes=malloc(sizeof(int)*intervalsSize);
    ret[m]=malloc(sizeof(int)*2);
    (*returnColumnSizes)[m]=2;
    ret[m][0]=intervals[0][0];
    ret[m][1]=intervals[0][*intervalsColSize-1];
    m++;
    for(i=0;i<intervalsSize-1;i++){
        /* 判断intervals[i+1]是否可以合并到ret[m-1]中，不然放置在区间ret[m]中*/
        if(intervals[i+1][0] <= ret[m-1][1]){
            /* ret[m-1][1]的值取intervalse[i+1][1]和ret[m-1][1]中的较大值*/
            if(intervals[i+1][1]>=ret[m-1][1]){
            ret[m-1][1]=intervals[i+1][*intervalsColSize-1];
            }
        }
        else{
            ret[m]=malloc(sizeof(int)*2);
            (*returnColumnSizes)[m]=2;
            ret[m][0]=intervals[i+1][0];
            ret[m][1]=intervals[i+1][*intervalsColSize-1];
            m++;
        }
    }
    *returnSize=m;
    return ret;
}