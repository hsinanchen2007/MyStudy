### 解题思路
帮助大家推理思路
快慢指针一开始可能想不到。我们可以换一种想法，比如创建一个和原数组一样大小的新数组，源数组指针j与新数组指针i一同前进，
源数组中值不等于val则copy到新数组，源数组中值等于val则不copy，这样就好理解了，如注释的代码。然后发现题目说可以"原地操作"，
那就省得创建新数组了，注释掉的代码里面的newNum就可以不用创建了，直接借用源数组，变成官方答案。大家想的时候依然可以想成是两个数组
i和j是在两个数组上移动，只是这两个数组视觉上看是重叠在一起了。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
//        int i = 0;
//        int[] newNums = new int[nums.length];
//        for (int j = 0; j < nums.length; j++) {
//            if (nums[j] != val) {
//                newNums[i] = nums[j];
//                i++;
//            }
//        }
//        return newNums.length;

        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                // newNum[i]变成了nums[i]，因为可以原地操作
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
```