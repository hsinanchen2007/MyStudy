### 解题思路
此处撰写解题思路

### 代码

```c
int findPairs(int* nums, int numsSize, int k){
    void quicksort(int* ,int,int);
    quicksort(nums,0,numsSize-1);
    int i,j,count=0,temp;
    if(k==0){
        for(i=0;i<numsSize-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                temp=i;
                for(j=i+1;j<numsSize;j++){
                    if(nums[temp]==nums[j]) i++;
                }
            }
        }
    }
    else{
        for(i=0;i<numsSize-1;i++){
            for(j=i+1;j<numsSize;j++){
                if(nums[j]-nums[i]==k){
                    if(nums[i]!=nums[i+1]&&nums[j-1]!=nums[j]){
                        count++;
                    }
                }   
            }
        }
    }
    return count;
}

void quicksort(int* arr,int low,int high){
    if(low<high){
        int i,j,k;
        i=low;j=high;k=arr[low];
        while(i<j){
            while(i<j&&arr[j]>=k){
                j--;
            }
            if(i<j){
                arr[i++]=arr[j];
            }
            while(i<j&&arr[i]<=k){
                i++;
            }
            if(i<j){
                arr[j--]=arr[i];
            }
        }
        arr[i]=k;
        quicksort(arr,low,i-1);
        quicksort(arr,i+1,high);
    }
}
```