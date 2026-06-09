### 解题思路
定义j，i两个指针然后遍历数组，这里会出现两种情况
1. 当nums[i]!=val. 这时我们直接将i指向的值赋给j指向的值就行，同时j+1
2. 当nums[j]==val. 这时我们可以保持j指针不动，等待i指向下一个不等于val的值就行

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for (int i = 0;i < nums.length;i++) {
            if (nums[i] != val) 
                nums[j++] = nums[i];                         
        }
        return j;
    }
}
```