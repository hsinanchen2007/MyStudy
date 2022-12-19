### 解题思路
本题是非常容易理解的，但对于我来说难点在如何编程上。思路见注释。

![图片.png](https://pic.leetcode-cn.com/06137ad3ed8ca065af16c3545e7b2b8b7490aa59c36838161fe4f155a42fb7d2-%E5%9B%BE%E7%89%87.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int end=target/2;
    int retsize=0;
    int *retcolsize=(int*)malloc(sizeof(int)*end);
    int **output=(int**)malloc(sizeof(int*)*end);
    int iop=0;
    for(int i=1;i<=end;i++){
        int sum=0;int jcount=0;int j;
        for(j=i;;j++){
            sum+=j;
            jcount++;
            if(sum>=target){
                break;
            }
        }
        if(sum==target){//如果得到了结果，才分配空间
            output[iop]=(int*)malloc(sizeof(int)*(jcount));
            int ii=0;
            for(int k=i;k<=j;k++){
                output[iop][ii++]=k;
            }
            retcolsize[iop]=jcount;
            iop++;
            retsize++;
        }
    }
    *returnColumnSizes=retcolsize;
    *returnSize=retsize;
    return output;
}
```