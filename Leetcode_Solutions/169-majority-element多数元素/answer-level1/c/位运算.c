### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    if(numsSize==0) return NULL;
    if(numsSize==1) return nums[0];
    if(numsSize==2) return nums[0];
    int two[32]={0};
    long int ans=0;
    int j;
    for(int i=0;i<numsSize;i++){
        for( j=0;j<32;j++){
            two[j]+=((nums[i]>>j)&1);
            }
    }
    for(int i=0;i<32;i++){
        if(two[i]>numsSize/2) two[i]=1;
        else two[i]=0;
    }
    for(int i=0;i<32;i++){
       ans*=2;
       ans+=two[31-i];
       
    }
    return ans;
}
```