```
int mycmp(const void* a,const void *b){
    const int *p1=(const int *)a;
    const int *p2=(const int *)b;
    if (*p1<*p2)
        return -1;
    else if (*p1==*p2)
        return 0;
    else 
        return 1;
}

void findans(int *candidates, int candidatesSize, int target, int **ans,int* returnSize, int** returnColumnSizes,int *path,int pathlenth,int flag){//flag为上一层所减的数字,用于防止出现重复结果

    if (target==0){//如果之和等于target，将结果保存到结果集中
        ans[*returnSize]=(int *)malloc(sizeof (int )*(pathlenth));
        for (int i=0;i<pathlenth;i++)
            ans[*returnSize][i]=path[i];
        returnColumnSizes[0][*returnSize]=pathlenth;
        (*returnSize)++;
    }
    else {
        for (int i=flag;i<candidatesSize;i++){
            if (target<candidates[i])//减去无效的分支
                break;
            path[pathlenth]=candidates[i];//记录路径值
            findans(candidates,candidatesSize,target-candidates[i],ans,returnSize,returnColumnSizes,path,pathlenth+1,i);//查找下一层分支
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),mycmp);//先排下序，便于后面剪支
    int **ans=(int **)malloc(sizeof (int *)*200);
    returnColumnSizes[0]=(int *)malloc(sizeof(int)*200);
    int *path=(int *)malloc(sizeof(int )*10);
    *returnSize=0;
    findans(candidates,candidatesSize,target,ans,returnSize,returnColumnSizes,path,0,0);
    return ans;
}
```
