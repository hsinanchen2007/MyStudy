### 解题思路
此处撰写解题思路

### 代码

```c
//剪枝法--借用快速排序的思想
int Find(int*nums,int s,int t,int k) {        //快速排序--由大到小排序
    int i=s,j=t;
    int temp;
    temp=nums[i];
    while(i!=j){                               //从两端交替向中间扫描，直到i=j            
        while(i<j&&nums[j]<=temp) j--;         //从后面向前找大于基准的值
        nums[i]=nums[j];
        while(i<j&&nums[i]>=temp) i++;         //从前面向后找小于基准的值
        nums[j]=nums[i];
    }
    nums[i]=temp;
    if(i+1==k)
        return temp;
    else if(i+1>k)
        return Find(nums,s,i-1,k);              //左区间中查找
    else
        return Find(nums,i+1,t,k);              //右区间中查找
}

int findKthLargest(int* nums, int numsSize, int k){
    int num;
    num=Find(nums,0,numsSize-1,k);
    return num;
}
```