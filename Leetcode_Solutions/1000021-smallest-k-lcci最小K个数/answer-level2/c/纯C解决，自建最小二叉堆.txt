### 解题思路
就是基本的建立最小二叉堆，然后依次输出即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void Adjust(int *nums,int k,int len)
 {
     int temp=nums[k];
     int i;
     for(i=2*(k+1);i<=len+1;i*=2)
     {
         if(i<len&&nums[i-1]>nums[i])
         i++;//我写这行代码的时候上帝和我知道，现在只有上帝知道了
         if(temp<=nums[i-1])break;
         else
         {
             nums[k]=nums[i-1];
             k=i-1;
         }
     }
     nums[k]=temp;
 }
 void CreateMax(int *nums,int length)//建立小顶堆
 {
     int i;
     for(i=(length-1)/2;i>=0;i--)
        Adjust(nums,i,length-1);
 }
int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    *returnSize=arrSize;
    if(arrSize==0)
    return arr;
    CreateMax(arr,arrSize);//创建小顶堆
    //for number[]
    int *number=(int *)malloc(sizeof(int)*arrSize);
    int index=0;

    while(k>0)
    {
        number[index++]=arr[0];
        arr[0]=arr[arrSize-index];
        Adjust(arr,0,arrSize-index);
        k--;
    }
    *returnSize=index;
    return number;
}
```