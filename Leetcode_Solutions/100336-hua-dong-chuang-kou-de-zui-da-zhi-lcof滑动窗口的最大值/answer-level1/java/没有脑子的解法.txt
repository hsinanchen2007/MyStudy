### 解题思路
没脑子与不高兴
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || k < 1 || nums.length < k) {
            return new int[0];
        }
        int[] max = new int[nums.length - k + 1];
        for(int i=0;i<max.length;i++){
            max[i] = Arrays.stream(Arrays.copyOfRange(nums,i,i+k)).max().getAsInt();
        }
        return max;
    }
}
```