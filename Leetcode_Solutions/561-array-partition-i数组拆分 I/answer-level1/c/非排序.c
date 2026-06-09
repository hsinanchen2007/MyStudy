
int arrayPairSum(int* nums, int numsSize){
    int n[20001]={0},count=0,i,j;
    for(i=0;i<numsSize;i++)
        n[nums[i]+10000]++;
    for(i=0,j=0;i<20001;i++)
        while(n[i]--!=0)
            if(j++%2==0)
                count+=i-10000;
    return count;
}