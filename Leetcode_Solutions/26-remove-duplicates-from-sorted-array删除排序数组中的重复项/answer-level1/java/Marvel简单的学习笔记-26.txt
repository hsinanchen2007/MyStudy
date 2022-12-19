### 解题思路
定义一前一后的双指针i、j，初始时i=0，j=1。不断地比较i和j指向的元素，如果是重复的（即nums[i]==nums[j]），则j往后移指向下一个待比较的元素；如果不是重复的的（即nums[i]!=nums[j]），由于要删除重复元素，所以将j指向的元素赋值到i后面，即nums[i+1]=nums[j]，而后i、j均向后移一位。如此这般，最后i的下标加一就是所有不重复元素的个数。最好自己在纸上模拟一次。
可以这样理解这两个指针:
i，**最新一个有效**（本题中有效指的是不重复）**元素的位置**。
j，下一个要检查的元素的位置。
时间复杂度：O(n)。指针j遍历一次数组即可。
空间复杂度：O(1)。只需两个int型变量。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0,j=1;
        while(j<nums.length)
        {
            if(nums[i]!=nums[j])    
                nums[++i]=nums[j];
            j++;
        }
        return i+1;
    }
}
```