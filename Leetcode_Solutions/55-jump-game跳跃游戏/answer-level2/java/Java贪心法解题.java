### 解题思路
跳跃的目标是到达数组的最后一个位置，我们可以从数组的倒数第二个位置开始向前推导，判断每个索引处的值是否>=最小的跳跃步数

解题思想： 如果数组索引值 < 最小步数，索引向前，最小步数加一

初始化最小跳跃步数 minJump = 1; // 从倒数第二个位置跳到倒数第一个位置最少需要跳跃1步

[2,3,1,1,4]

1 >= 1,所以 数组索引3 可以跳到最后一个位置
1 >= 1,所以 数组索引2 可以跳到倒数第二个位置
3 >= 1,所以 数组索引1 可以跳到倒数第三个位置
2 >= 1，所以数组索引0 可以跳到倒数第四个位置
所以整体推导下来是可以跳到最后一个位置。

[3,2,1,0,4]
0 < 1,所以 索引前移，最小步数+1   minJump = 2,
1 < 2 所以 索引前移，最小步数+1   minJump = 3,
2 < 3 所以 索引前移，最小步数+1   minJump = 4,
3 < 4 所以 索引前移，最小步数+1   minJump = 5
所以永远不能到达最后一个位置

倒数第二个：1, 要想跳到最后一个位置，最小的跳跃步数为1，因此倒数第二个数应该要大于1

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length == 1) return true;
        int minJump = 1,start = nums.length -2;
        while(start > 0){
            if(nums[start] < minJump){
                minJump++;
            }else{
                minJump = 1;
            }
            start--;
        }
        if(nums[0] < minJump) return false;
        return true;
    }
}
```