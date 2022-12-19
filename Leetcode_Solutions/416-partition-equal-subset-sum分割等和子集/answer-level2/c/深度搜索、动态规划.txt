以下均为学习大佬代码后写出
动态规划
```
int compare(int a,int b){
    return b-a;
}

bool canPartition(int* nums, int numsSize){
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    if(sum%2)return false;
    int target=sum/2;
    qsort(nums,numsSize,sizeof(int),compare);
    bool dp[100000]={false};
    dp[0]=true;
    if(nums[0]>target)
        return false;
    
    for(int i=0;i<numsSize;i++){
        for(int j=target;j>=nums[i];j--){
            dp[j]=dp[j]||dp[j-nums[i]];
        }
    }
    return dp[target];
}
```
递归
```
int compare(int a,int b){
    return a-b;
}
bool canPartition(int* nums, int numsSize){
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    //printf("1  sum=%d\n ",sum);
    if(sum%2)return false;
    sum=sum/2;
    qsort(nums,numsSize,sizeof(int),compare);
    if(find(nums,numsSize-1,sum,sum))
        return true;
    else return false;
}

int find(int* nums,int idx,int had,int pass){
    
    if(pass==0||had==0)return 1;
    else if(pass<0||had<0)return 0;
    else return (find(nums,idx-1,had-nums[idx],pass)||find(nums,idx-1,had,pass-nums[idx]));

}
```
