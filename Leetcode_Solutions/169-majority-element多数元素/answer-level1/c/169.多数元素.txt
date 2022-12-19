### 解题思路
此处撰写解题思路

### 代码

```c
//方法一--投票法
int majorityElement(int* nums, int numsSize){
    int count=0,candidate;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
        }
        if(candidate==nums[i]){
            count++;
        }else{
            count--;
        }
    }
    return candidate;
}

//方法二--排序法

//(1)排序   （2）取位置为(n/2)的元素
//快速排序
void sort(int *num,int low,int high){
    int i=low,j=high,temp;
    if(low<high){
        temp=num[low];
        while(i!=j){
            while(j>i&&num[j]>=temp) j--;
            num[i]=num[j];
            while(i<j&&num[i]<=temp) i++;
            num[j]=num[i];
        }
        num[i]=temp;
        sort(num,low,i-1);
        sort(num,i+1,high);
    }
}

//取元素
int majorityElement(int* nums, int numsSize){
    sort(nums,0,numsSize-1);
    return nums[numsSize/2];
}

```