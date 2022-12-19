如果使用普通的快排划分，虽然时间复杂度是O(n)，空间复杂度是O(1)。

但是仍然不是最优解。因为普通的快排划分需要对数组进行两次扫描(第一次以2为中心划分，第二次以1为中心划分)。

题目要求的最优是对数组进行一次扫描。

怎么做呢？

设置两个变量r1,r2，含义是r1,左边(包含r1)的变量值都小于1，r2左边(包含r2)的变量值都小于2。

那么初始时他俩都是-1(实际上是左边界-1)，代表他俩所包裹的范围是空。

假设现在有数组nums = [0,0,1,1,2,0,0],r1 = 1,r2 = 3。此时的数组索引i是5，也就是要处理0，这个数是小于2的。

因此r2+1，代表区间扩大，把nums[i]和nums[r2]交换。此时维持了r2左侧的数都是小于2的这个性质。

交换完之后，这个小于2的数存放在了nums[r2]，但是这个nums[r2]仍然有可能小于1，若是小于1，那么

应该把r1+1，代表区间扩大，然后把nums[r1]和nums[r2]交换，这样才能维持r1左侧的数小于1的这个性质。

java 代码:

```
class Solution {
    public void sortColors(int[] nums) {
        
        int r1 = -1;
        int r2 = -1;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] < 2)
            {
                r2++;
                swap(nums,i,r2);
                if(nums[r2] < 1)
                {
                    r1++;
                    swap(nums,r1,r2);
                }
            }
            
        }
        
        
      
        
    }
    
    void swap(int[]nums,int i,int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```