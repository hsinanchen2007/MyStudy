### 解题思路
思路是通过一次遍历，借助遍历指针和覆盖指针，判断遍历过程中指针指向元素的个数，不大于2的情况下当前的位置是需要覆盖
定义两个指针，一个用于遍历，一个用于指向重新写入个元素位置，一个计数器（用于保证原有的数组元素的正确个数）
从第二个元素开始（第一个元素一定是符合要求的，无需判断），遍历指针和覆盖指针指向同一个位置，那么这时候指向的元素已经有一个了，所以计数器赋值为 1
判断前一个元素与当前元素的等价关系，相等则计数器加一，不等则保持计数器为 1
判断当前计数器的值，不大于2的情况下，说明当前位置覆盖为当前遍历的元素，覆盖完成需要指向下一个元素

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        // 指向需要覆盖的元素
        // 从第二个原始开始判断
        int point = 1;
        // 记录当前遍历元素的个数
        int count = 1;
        for (int index = 1; index < nums.length; index += 1) {
            if (nums[index - 1] == nums[index]) {
                count += 1;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[point] = nums[index];
                point += 1;
            }
        }
        return point;
    }
}
```