
这道题说白了就是**保留**`nums`中不等于`val`的元素。注意**保留**两个字，我们直接用一个变量来记录需要**保留**的元素下标，然后再用一个变量来遍历原数组，这就是所谓的**双指针**。

![image.png](https://pic.leetcode-cn.com/8f3565c2bffa22c2742a9ae24ad24a39bc36bf0dc3ab345ba0a7238d89280bbc-image.png)


```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0, j = 0;
        while (j < nums.length) {
            if (nums[j] != val) {
                nums[i++] = nums[j++]; // nums[j] != val，这个元素需要保留
            } else {
                j++;  // nums[j] == val，不用保留，直接忽略，往后遍历
            }
        }
        return i;
    }
}
```