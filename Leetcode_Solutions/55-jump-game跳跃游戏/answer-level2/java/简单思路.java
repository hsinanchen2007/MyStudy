![WX20200110-193328@2x.png](https://pic.leetcode-cn.com/b012f2a31fb2396df9e2eb3cd1f7db92aee784e1341ba6b227576a036eee6d57-WX20200110-193328@2x.png)

### 代码

```java
    public boolean canJump(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        if (nums.length == 1) {
            return true;
        }
        int tmp = 0;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > tmp) {
                tmp = 0;
            } else {
                tmp++;
            }
        }
        return tmp == 0;
    }
```