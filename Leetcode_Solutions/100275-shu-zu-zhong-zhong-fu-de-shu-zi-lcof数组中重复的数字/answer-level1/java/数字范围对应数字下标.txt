### 解题思路
将数字一一交换到对应的下标下，如果发生冲突了nums[nums[i]] == nums[i]，则直接返回 nums[i]
利用数组代替hashmap
这样的空间复杂度就是O(1)了

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int i=0;
        while (i<nums.length) {
            if (nums[i] == i) {
                i++;
            } else {
                // 需要将i上的数字nums[i] 放置到 nums[i]的位置
                if (nums[nums[i]] == nums[i]) { //需要交换的地方已经到位，即出现重复
                    return nums[i];
                } else {
                    swap(i, nums[i], nums);
                }
            }
        }
        return -1;
    }
    void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
![image.png](https://pic.leetcode-cn.com/712e5e671321f84013c6d332be0f874985b652ffaa7cc6c91bee74e446ec6967-image.png)
