### 解题思路
此处撰写解题思路

### 代码

```c
//快排无法满足性能要求
/*int partition(int a[],int low,int high){
    int key=a[low];
    int p=low,q=high;
    while(p<q){
        while(p<q&&a[q]>key) q--;
        a[p]=a[q];
        while(p<q&&a[p]<=key) p++;
        a[q]=a[p];
        
    }
    a[p]=key;
    return p;
}

void quicksort(int nums[],int low,int high){
    if(low<high){
    int pivot=partition(nums,low,high);
    quicksort(nums,low,pivot-1);
    quicksort(nums,pivot+1,high);
    }
}*/

//heap  sort
void heapadjust(int nums[],int i,int size){
    int nChild;
    int nTemp;
    for(;i*2+1<size;i=nChild){
        nTemp=nums[i];
        nChild=i*2+1;
        if(nChild<size-1&&nums[nChild+1]>nums[nChild]) nChild++;
        if(nums[nChild]>nTemp){
            nums[i]=nums[nChild];
            nums[nChild]=nTemp;
        }
        else break;
    }
}

void heapsort(int nums[],int numsSize){
    for(int i=numsSize/2-1;i>=0;i--)
       heapadjust(nums,i,numsSize);
    for(int i=numsSize-1;i>0;i--){
        int temp=nums[i];
        nums[i]=nums[0];
        nums[0]=temp;
        heapadjust(nums,0,i);
    }
}




bool containsDuplicate(int* nums, int numsSize){
  if(numsSize==0)  return false;
  heapsort(nums,numsSize);
  int key=nums[0];
  for(int i=1;i<numsSize;i++){
      if(key==nums[i]){
          return true;
      }
      else{
          key=nums[i];
      }
  }
  return false;
}
```