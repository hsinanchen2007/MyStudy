```
int inc(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,int **ret,int total,int *temp, int temp_count,int pos);
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ret=(int **)malloc(sizeof(int *)*200);            //结果二级指针
    *returnColumnSizes=(int *)calloc(200,sizeof(int));      //leetcode会自动截取对应长度
    int *temp=(int *)calloc(50,sizeof(int));                //存储临时数组
    
    int temp_count=0;                                       //存储temp数组的第几位
    *returnSize=0;
    int total=0;                                            //存储临时的和
    int pos=0;                                              //存的选取的candidates里面的第几位
    if(sizeof(candidates)==0){
        return NULL;
    }
    qsort(candidates,candidatesSize,sizeof(int),inc);
    
    backtrack(candidates,candidatesSize,target, returnSize,returnColumnSizes,ret,total,temp,0,pos);
    return ret;
}

void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,int **ret,int total,int *temp,int temp_count,int pos){
    if(total==target){
        ret[*returnSize]=(int *)malloc(sizeof(int)*50);
        int i=0;
        while(temp[i]!=0){
            ret[*returnSize][i]=temp[i];
            i++;
        }        
        (*returnColumnSizes)[*returnSize]=temp_count;   //注意运算符的优先级
        (*returnSize)++;
    }
    else{
        for(int j=pos;j<candidatesSize;j++){
            if(j>pos&&candidates[j]==candidates[j-1]){//注意，这里是j>pos而不是>0,因为会如果后者会使
                continue;           //得上一层与下一层连续两位不相同，而不是仅是同一层的连续两位不相同
            }
            if(total+candidates[j]<=target){ 
            temp[temp_count]=candidates[j];
            pos=j;
            total=total+candidates[j];
            backtrack(candidates,candidatesSize,target, returnSize,returnColumnSizes,ret,total,temp,temp_count+1,pos+1);
            total=total-candidates[j];
            temp[temp_count]=0;         //这一步要有的，不然虽然不会影响if条件的判断，但会影响
                                              //temp[i]向ret[*returnSize]的赋值
            }     
        }                              
    }
}
```
