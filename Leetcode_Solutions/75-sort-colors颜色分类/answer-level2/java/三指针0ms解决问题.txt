### 解题思路
此处撰写解题思路
三指针
经典的颜色问题
### 代码

```java
class Solution {
    public static void swap(int[]num,int i ,int j)
    {
        int temp=num[i];
        num[i]=num[j];
        num[j]=temp;
    }
    public void sortColors(int[] nums) {
         int k=-1,i=0,j=nums.length,temp;
         while(i<j)
         {
             if(nums[i]==0) swap(nums,++k,i++); 
             else if(nums[i]==2) swap(nums,--j,i);
             else ++i;          
         } 

    }
}
```