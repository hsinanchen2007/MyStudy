### 解题思路
 String.valueOf(n).length() & 1;
获取数字的长度，然后和1参与“与”预算。

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
       for (int n : nums) {
            int v = String.valueOf(n).length() & 1;
            if (v != 1) {
                count++;
            }
        }
        return count;
    }
}
```