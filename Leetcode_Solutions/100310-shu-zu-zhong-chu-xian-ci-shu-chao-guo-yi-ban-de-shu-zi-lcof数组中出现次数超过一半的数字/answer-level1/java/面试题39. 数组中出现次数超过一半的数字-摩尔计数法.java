### 解题思路

首先这题目不难。以我自己的经验，可以至少使用以下两种方法：

1. 先快速排序，然后获得多数数字就是 nums[nums.length/2]，但是我用这种方法提交代码的时候，提示执行时间1.3s，惨不忍睹    
2. 使用HashMap 计数，存储每个数字出现的次数，之后再遍历数组的时候，发现某个数字的次数超过一半了，则它就是想要的结果。不过这种方法有使用辅助的 HashMap，并且遍历2次，略有繁琐

可能想不到的是摩尔计数法，我也是参考别人的答案才写出下面的解法，这个解法可能是这个问题的最优解了吧，要理解和记住这种方法。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums == null || nums.length == 0){
            throw new IllegalArgumentException("input error");
        }

        int voteNum = 0;
        int zhongshu = 0;

        for(int element: nums){
            if(voteNum == 0){
                zhongshu = element;
            }

            voteNum += element == zhongshu ? 1 : -1;
        }

        return zhongshu;
    }
}
```