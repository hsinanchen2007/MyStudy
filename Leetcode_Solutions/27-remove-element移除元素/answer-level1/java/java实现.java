### 解题思路
 题目中有一个关键描述，不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。元素的**顺序可以改变**。**你不需要考虑数组中超出新长度后面的元素**。所以 只要把与给定值不同数字直接放在
数组的最前面，然后返回新数组的长度即可，因为后面的数字已经不考虑了。。。一开始没看懂这一次层意思
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] != val) ) {
                nums[res]=nums[i];
                res++;
            }
        }
        return res;
      
    }
}
```