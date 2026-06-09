```cpp
void dfs(int *nums,int N,int depth,int *sum)
{
    
    
    
    for(int i=depth;i<N;i++)
    {
        //mark,path
        if(nums[i]%(depth+1)!=0&&(depth+1)%nums[i]!=0) continue;
        
        int temp=nums[depth];
        nums[depth]=nums[i];
        nums[i]=temp;
        depth++;
       
        
        //result
        if(depth==N)
            *sum=*sum+1;
        //dfs
        if(depth<N) dfs(nums,N,depth,sum);
        depth--;
        temp=nums[depth];
        nums[depth]=nums[i];
        nums[i]=temp;
    }
}
int countArrangement(int N){
    int sum=0;
    int nums[N];
    for(int i=0;i<N;i++)
    {
        nums[i]=i+1;
    }
    dfs(nums,N,0,&sum);
    return sum;
}```
1全排列用swap更快。
2还是在赋值后result,因为有for的限制，有的不进入n+1层。