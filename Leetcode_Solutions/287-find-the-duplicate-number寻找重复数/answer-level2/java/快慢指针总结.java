### 解题思路

1. 用兔子(hare)和乌龟(tortoise)彩排一把，找到循环的入口
2. pointer1 从头开始跑，pointer2在循环里面死跑，等待与pointer1相遇
3. 相遇点(索引)对应的值就是我们要求的值

### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        //找到重复入口
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        int pointer1 = nums[0];
        int pointer2 = tortoise;
        
        //pointer2在循环里死跑等待与pointer1相遇
        while (pointer1 != pointer2) {
            pointer1 = nums[pointer1];
            pointer2 = nums[pointer2];
        }
        return pointer2;
    }
}
```