### 题目
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:

    输入: [2,3,1,1,4]
    输出: true
    解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

示例 2:

    输入: [3,2,1,0,4]
    输出: false
    解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game

### 解题思路
- 第一反应想到的方法,应该是一步步跳,直到能跳到终点.当然这效率肯定低
- 也可以像代码中注释那样,倒着跳,看前面的位置有没有能跳到当前位置的.一步步往回跳,一次循环就够了

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {

        // 咱们倒着跳,lastIndex代表所在位置
        int lastIndex = nums.length - 1;
        for(int i = nums.length - 1 ; i >= 0 ; i--){
            //如所在 i 位置,加 i 可跳跃长度大于 lastIndex
            //证明只要调到i有能跳到i位置的,就一定能跳到lastIndex
            if( i + nums[i] >= lastIndex){
                // 将lastIndex替换为I,找能跳到i位置的
                lastIndex = i;
            }
        }

        //如果最后跳到初始位置,证明反着跳可以跳回来,正着跳当然也没问题
        return lastIndex == 0;
    }
}
```