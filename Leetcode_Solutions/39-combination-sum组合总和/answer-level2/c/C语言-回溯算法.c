```

 int Partition(int *nums,int left,int right){
    int temp=nums[left];
    while(left<right){
        while(left<right&&temp<nums[right]) right--;
        nums[left]=nums[right];
        while(left<right&&temp>=nums[left]) left++;
        nums[right]=nums[left];
    }
    nums[left]=temp;
    return left;
}

void sort(int *nums,int left,int right){
    if(left<right) {
        int pos=Partition(nums,left,right);
        sort(nums,left,pos-1);
        sort(nums,pos+1,right);
    }
}
void dfs(int *candidates,int candidatesSize,int **res,int arr[],int target,int *ind,int size,int start,int *returnColumnSizes){
    if (target==0) {
        res[*ind]=(int *)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++){
            res[*ind][i]=arr[i];
        }
        returnColumnSizes[*ind]=size;
        (*ind)++;
        return ;
        
    }
    for(int i=start;i<candidatesSize;i++){
        if(target<candidates[i]) return;
        arr[size++]=candidates[i];
        dfs(candidates,candidatesSize,res,arr,target-candidates[i],ind,size,i,returnColumnSizes);
        size--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if(candidatesSize==0) return 0;
    sort(candidates,0,candidatesSize-1);
    int **res=(int **)malloc(sizeof(int *)*1024);
    *returnColumnSizes=(int *)malloc(sizeof(int)*1024);
    int arr[1024];
    int ind=0;
    dfs(candidates,candidatesSize,res,arr,target,&ind,0,0,*returnColumnSizes);
    *returnSize=ind;
    return res;
}
```
