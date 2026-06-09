### 解题思路
标准的二分查找，空间消耗好多啊，怎么降啊各位大佬
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
         int lowPosition = 0;
         int highPosition = nums.length - 1;
         int mid = 0;

        while(lowPosition <= highPosition)
        {
            mid = lowPosition + (highPosition - lowPosition)/2;
            if(target > nums[mid])
            {
                lowPosition = mid + 1;
            }
            else if(target < nums[mid])
            {
                highPosition = mid - 1;
            }
            else return mid;
        }
        return -1;
    }
}
```