```
void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,int **ret,int total,int *temp, int temp_count);
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ret=(int **)malloc(sizeof(int *)*200);            //结果二级指针
    *returnColumnSizes=(int *)calloc(200,sizeof(int));      //leetcode会自动截取对应长度
    int *temp=(int *)calloc(50,sizeof(int));                //存储临时数组
    int temp_count=0;                                       //存储temp数组的第几位
    *returnSize=0;
    int total=0;                                            //存储临时的和
    if(sizeof(candidates)==0){
        return NULL;
    }
    backtrack(candidates,candidatesSize,target, returnSize,returnColumnSizes,ret,total,temp,0);
    return ret;
}

void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,int **ret,int total,int *temp,int temp_count){
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
        for(int j=0;j<candidatesSize;j++){
            if(total+candidates[j]<=target&&(temp_count==0||(temp_count>=1&&candidates[j]>=temp[temp_count-1]))){ //要求
                temp[temp_count]=candidates[j];
                total=total+candidates[j];
                backtrack(candidates,candidatesSize,target, returnSize,returnColumnSizes,ret,total,temp,temp_count+1);
                total=total-candidates[j];
                temp[temp_count]=0;         //这一步要有的，不然虽然不会影响if条件的判断，但会影响
            }                               //temp[i]向ret[*returnSize]的赋值
        }                              
    }
}
```
