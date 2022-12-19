### 解题思路
摩尔投票法
此算法基于条件为当一个数的重复次数超过数组长度的一半，每次将两个不相同的数删除，最终剩下的就是要找的数。

1.初始化计数器cnt = 0； 返回目标值n = nums[0]; 表示从此时开始计算投票。

2.遍历数组，如果接下来出现的数字与n相同，cnt加1。如果不同，cnt减1。

3.如果cnt == 0，表示之前出现的所有数字中n之间都是可以凑成不同的数对，一起抵消，直接遍历下一个数。重复次数大于n/2的数还会在后面出现。遍历完数组，满足条件的 n 其 cnt 必定>0。


### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 0;
        int n = nums[0];
        for(int num : nums){
            if(cnt == 0) n = num;
            cnt += n == num ? 1 : -1;
        }
        return n;
    }
}
```