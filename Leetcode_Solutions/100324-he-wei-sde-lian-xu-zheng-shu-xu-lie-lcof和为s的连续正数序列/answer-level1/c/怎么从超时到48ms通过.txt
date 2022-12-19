### 解题思路
1、一开始很顺利地就回溯算法一套就上去了，发现结果不对，后来仔细读了一下题目，发现是要连续的
2、那好，我就加个判断(如果当前值不是比前一个数大一就下一个)嘛，本以为是道简单题，可以秒的，但是超时了
3、后来又惊奇地发现这东西是确定了第一个值就确定了整个序列的，因此你确定一个值后就可以直接取到下一个值，因此就出现了下面的代码，顺利AC


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//回溯算法
void dfs(int target, int* returnSize, int** returnColumnSizes, int** res, int* dummy, int total, int num){
    if(total>target){
        return;
    }
    else if(total==target){
        memcpy(res[(*returnSize)],dummy,sizeof(int)*num);
        (*returnColumnSizes)[(*returnSize)]=num;
        (*returnSize)++;
        return;
    }
    else{
        //超时
        /*
        int i;
        for(i=1;i<=(target+1)/2;i++){
            if(num>0&&dummy[num-1]!=i-1){
                continue;
            }
            dummy[num]=i;
            dfs(target, returnSize, returnColumnSizes, res, dummy, total+i, num+1);
        }
        */
        //因为是连续的，所以没必要每次都进行判断，是确定了第一个值就确定了整个序列的情况
        if(num==0){
            int i;
            for(i=1;i<=(target+1)/2;i++){
                dummy[num]=i;
                dfs(target, returnSize, returnColumnSizes, res, dummy, total+i, num+1);
            }
        }
        else{
            dummy[num]=dummy[num-1]+1;
            dfs(target, returnSize, returnColumnSizes, res, dummy, total+dummy[num], num+1);
        }
    }
    return;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    *returnColumnSizes=(int *)malloc(sizeof(int)*1000);
    int **res=(int **)malloc(sizeof(int *)*100);
    int i;
    for(i=0;i<100;i++){
        res[i]=(int *)malloc(sizeof(int)*1000);
    }
    for(i=0;i<100;i++){
        memset(res[i],'\0',sizeof(int)*1000);
    }
    int *dummy=(int *)malloc(sizeof(int)*1000);
    memset(dummy,'\0',sizeof(int)*1000);
    dfs(target, returnSize, returnColumnSizes, res, dummy, 0, 0);
    free(dummy);
    return res;
}
```