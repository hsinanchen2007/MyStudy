void sortColors(int* nums, int numsSize){
    
    int i,j=0,a,b,c;
    a=b=c=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==0) a++;
        if(nums[i]==1) b++;
        if(nums[i]==2) c++;
    }
    for(i=0;i<a;i++)
    nums[j++]=0;
     for(i=0;i<b;i++)
    nums[j++]=1;
     for(i=0;i<c;i++)
    nums[j++]=2;
}