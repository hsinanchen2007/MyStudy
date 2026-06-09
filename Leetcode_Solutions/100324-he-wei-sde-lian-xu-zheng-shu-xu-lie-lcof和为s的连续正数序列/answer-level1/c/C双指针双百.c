### 解题思路
![Snipaste_2020-03-06_15-37-18.png](https://pic.leetcode-cn.com/26083818d89d327bb3f8854d82b97a652c6dd09a5e026b7da52141427dd76c4d-Snipaste_2020-03-06_15-37-18.png)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int RecordOneRes(int **res,int* returnColumnSizes,int count,int l,int r){
    if(r-l<=1) return 1;
    int *oneRes=(int *)malloc(sizeof(int)*(r-l));
    if(oneRes==0){
        return 1;
    }
    for(int i=l;i<r;i++){
        oneRes[i-l]=i;
    }
    res[count]=oneRes;
    returnColumnSizes[count]=r-l;

    return 0;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if(target<=2) return 0;

    int **res=(int **)malloc(sizeof(int *)*target);
    if(res==0) return 0;

    *returnColumnSizes=(int *)malloc(sizeof(int)*target);
    if(*returnColumnSizes==0){
        free(res);
        return 0;
    }

    int l = 1,r=1,sum=0,count=0; 
    bool stop = false;
    while(r<=target){
        if(sum<target){
            sum+=r;
            r++;
            continue;
        }
        if(sum==target){
            if(RecordOneRes(res,*returnColumnSizes,count,l,r)==0){
                count++;
            }
            sum+=r;
            r++;
            continue;
        } 
        
        while(sum>target){
            if(r-l-1<=1){
                stop=true;
                break;
            }
            sum-=l;
            l++;
        }
        if(stop) break;
    }

    *returnSize=count;
    return res;

}
```