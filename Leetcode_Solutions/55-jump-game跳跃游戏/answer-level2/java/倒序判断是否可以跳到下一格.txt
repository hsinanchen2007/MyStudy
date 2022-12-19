### 解题思路
此处撰写解题思路
倒序开始从倒数第二个位置 判断是否可以跳到下一个位置，可以就把步数置为0。否则就把再下一个位置要跳的长度+1
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {

        int step = 0;
        //倒序开始从倒数第二个位置 判断是否可以跳到下一个位置，可以就把步数置为0
        //否则就把再下一个位置要跳的长度+1
        for(int i=nums.length-2 ;i>=0;i--){
            if(nums[i]<=step){
                step++;
            } else {
                step=0;
            }
        }
        return step==0;
    }
}
```