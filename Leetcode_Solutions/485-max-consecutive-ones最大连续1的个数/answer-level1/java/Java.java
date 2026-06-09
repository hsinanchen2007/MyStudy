### 解题思路
java

### 代码

```java
class Solution {
    /**
     * 很简单的题，一次遍历即可解决问题
     * @param nums
     * @return
     */
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0, count = 0;
        for ( int num: nums) {
            if (num == 1) {
                count++;
                max = Math.max(max, count);
            }
            else count = 0;
        }
        return max;
    }
}
```