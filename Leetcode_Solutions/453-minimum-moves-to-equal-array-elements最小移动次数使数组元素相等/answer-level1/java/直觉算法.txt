### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minMoves(int[] nums) {
         
        return Arrays.stream(nums).sum() - nums.length * Arrays.stream(nums).min().getAsInt();
    }
}
```