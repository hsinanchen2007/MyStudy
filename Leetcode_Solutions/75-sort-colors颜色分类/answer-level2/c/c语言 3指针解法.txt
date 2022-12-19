**这道题其实就是荷兰国旗嘛 然后解法就是用三个指针  i指针指向下一个放0的位置  
k指针用来遍历 j指针指向下一个放2的位置  当nums[k]==0时 将nums[k]的值和num[i]
的值交换然后i,k同时向右移动 ,如果nums[k]==1将k指针向右移动 如果nums[k]==2 将
nums[k]的值和num[j]的值交换然后将指针j向左移动**
```
void sortColors(int* nums, int numsSize){
    int i=0,j=numsSize-1,k=0,temp=0;
    while(k<=j)//这里一定要加=  2 0 1 这种情况可以解释原因
    {
        if(nums[k]==1)
           k+=1;
        else if(nums[k]==0)
        {
           temp=nums[i];
           nums[i]=nums[k];
           nums[k]=temp;
           i+=1;
           k+=1;
        }
        else{
          temp=nums[j];
           nums[j]=nums[k];
           nums[k]=temp;
           j-=1;
        }
    }

}
```
