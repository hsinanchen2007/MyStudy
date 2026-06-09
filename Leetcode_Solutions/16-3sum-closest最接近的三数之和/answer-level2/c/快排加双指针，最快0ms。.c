```
//声明排序为整型数组递增
int inc(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(nums[0]),inc);   //快速排序
    int threeSum=nums[0]+nums[1]+nums[numsSize-1];//先初始化一个值
    int i=0,j=0,k=0;
    
    for(i=0;i<(numsSize-2);i++){
        if(nums[i]>=(threeSum/3)&&threeSum>target){
            break;  //当最左边的都大于1/3*threesum,并且threesum大于target了，
        }           //那三个数之和肯定更大了，就不用算了    
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }   
        j=i+1;k=numsSize-1; 
        while(j<k){
            if(nums[j]==nums[j-1]&&(j-1)!=i){
                j++;
            }
            else if((k<numsSize-1)&&nums[k]==nums[k+1]){
                k--;
            }//当j++和k--之后是不能顺序执行下面语句的，所以要用else
            else{
                if(nums[i]+nums[j]+nums[k]==target){
                    return target;
                }
                else if(abs(nums[i]+nums[j]+nums[k]-target)<abs(threeSum-target)                ){
                    threeSum=nums[i]+nums[j]+nums[k];
                }
                
                if(nums[i]+nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }                
    }
return threeSum;    
}
```
![image.png](https://pic.leetcode-cn.com/1cfdd669cfcf4caea9179848b24a111440429b43402875bc67ea797e605ee614-image.png)

