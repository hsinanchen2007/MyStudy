执行用时 :2 ms, 在所有 Java 提交中击败了99.95%的用户
内存消耗 :40 MB, 在所有 Java 提交中击败了5.04%的用户

### 代码

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int answer = 0;
        int currentLen = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                currentLen++;
            } else {
                if (currentLen > answer) {
                    answer = currentLen;
                }
                currentLen = 0;
            }
        }
        if (currentLen > answer) {
            answer = currentLen;
        }
        return answer;
    }
}
```