很多方法遍历两边数组，第一次找到最大的，第二次在判断有没有dominant。这里提出一种新的思路：只遍历一遍数组，即可以找到dominant元素。

思路：考虑当前元素和下一个元素之间的关系，又如下几种关系：
 - `nums[i] < nums[i + 1] / 2`
 - `nums[i] > nums[i + 1] / 2 &&  nums[i] <= nums[i + 1]`
 - `nums[i] > nums[i + 1] &&  nums[i] < 2 * nums[i + 1] `
 - `nums[i] >= 2 * nums[i + 1]`

只有当所有数组的所有元素满足上述条件1或者4的时候（小于1/2或者大于2倍的时候），才存在dominant的元素，所以我们定义flag，来判断整个数组是否存在dominant的元素。

```java
class Solution {
    public int dominantIndex(int[] nums) {
        // corner case
        if (nums.length == 0) {
            return -1;
        }
        if (nums.length == 1) {
            return 0;
        }
        boolean flag = true;
        int dominant = nums[0];
        int dominantIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > dominant / 2 && nums[i] <= dominant) {
                flag = false;
            }
            if (nums[i] > dominant && nums[i] < 2 * dominant) {
                dominant = nums[i];
                flag = false;
            }
            if (nums[i] >= 2 * dominant) {
                dominant = nums[i];
                flag = true;
                dominantIndex = i;
            }
        }
        return flag ? dominantIndex : -1;
    }
}
```