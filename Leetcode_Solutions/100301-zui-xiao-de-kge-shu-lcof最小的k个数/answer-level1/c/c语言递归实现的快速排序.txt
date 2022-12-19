### 解题思路
每次将数段的最后一个数作为mid，设置left和right两个指针（指示位置的针）分别从头和尾开始移动，
left遇到比mid大或等于的数就停下，right遇到小于mid的数就停下，期间要保证left<right,将两个位置的数的值进行交换，以保证left经过的数比mid小，right经过的数不比mid小，
直到left和right相遇，此时右边的值都是大于等于mid的，左边的值都是小于mid的，再分别处理start到left和left+1到end这两段的数据

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void quickSort(int *arr,int start,int end)
 {   
    // printf("\n%d %d\n",start,end);
    // for(int i=start;i<=end;i++)
    // {
    //     printf("%d ",*(arr+i));
    // }
     int left=start;
     int right=end-1;
     int mid=*(arr+end);
     while(left<right)
     {
         while(*(arr+left)<mid && left<right) left++;
         while(*(arr+right)>=mid && right>left) right--;
         if(left<right)
         {
             int tmp=*(arr+left);
             *(arr+left)=*(arr+right);
             *(arr+right)=tmp;    
             left++;
             right--;        
         }   
                
     }
     if(*(arr+left)>mid)
     {
         *(arr+end)=*(arr+left);
         *(arr+left)=mid;
     }
     if(left>start)
     {
         quickSort(arr,start,left);
     }
     if(left<end-1)
     {
         quickSort(arr,left+1,end);
     }
     
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    quickSort(arr,0,arrSize-1);
    int *ans;
    ans=(int *)malloc(k*sizeof(int));
    for(int i=0;i<k;i++)
    {
        *(ans+i)=*(arr+i);
    }
    *returnSize=k;
    return ans;
}
```