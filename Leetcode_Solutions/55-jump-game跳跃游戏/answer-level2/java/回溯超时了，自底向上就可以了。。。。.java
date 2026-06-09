### 解题思路
回溯超时了，自底向上就可以了

### 代码

```java
class Solution {
     //标记能否从起点跳到这个位置
    private boolean[] ican;

    public boolean canJump(int[] nums) {
        ican = new boolean[nums.length];
        ican[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (ican[i])
                for (int j = 1; j <= nums[i]&&i+j<nums.length; j++) {
                    ican[j + i] = true;
                }
        }

        return ican[nums.length - 1];
    }
}
```