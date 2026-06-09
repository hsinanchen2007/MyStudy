    int wiggleMaxLength(int* nums, int numsSize){   //差值变符号res+1，O(n),O(1)
    int i,res,flag,tmp;
    if(numsSize<2) return numsSize;
    
    res=1;
    for(i=1,tmp=0;i<numsSize;i++){
        if(nums[i]-nums[i-1]>0) flag=1;
        else if(nums[i]-nums[i-1]<0) flag=-1;
        else flag=0;
        
        if(flag==0) continue;
        else if(flag!=tmp) res++;
        tmp=flag;
    }
    return res;

    }