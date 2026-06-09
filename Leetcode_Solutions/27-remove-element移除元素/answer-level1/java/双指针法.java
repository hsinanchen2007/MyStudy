### 解题思路
设置两个指针i和j，我们让i来扫描值为val的元素，j用来存放最终元素位置。若nums[i]值不为val，我们让i和j同时右移，若值为val，说明这个元素是要被移除的，不应放到最终数组上去，所以j不作任何处理

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]!=val)
            {
                nums[j++]=nums[i];
            }
        }
        return j;
    }
}
```