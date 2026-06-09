### 解题思路
此处撰写解题思路
0011122334   10
011122334    9
01122334     8
0122334      7
012334       6
012344       5
只要相同就向前覆盖，注意点在与最后一个可能死循环，因此i！=numsSize-1;
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    for(int i=0;i<numsSize-1;i++)
    {
        while(nums[i]==nums[i+1]&&i+1!=numsSize)
        {
            
            for(int j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
          numsSize--;
        } 
         
    }
    return numsSize;

}
```