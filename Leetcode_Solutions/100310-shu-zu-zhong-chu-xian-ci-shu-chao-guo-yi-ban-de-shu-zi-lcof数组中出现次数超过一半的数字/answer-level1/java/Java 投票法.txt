### 解题思路
是同类则增加，否则消减，最后活着的就是多的。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        // 初始化"候选人" 和 "票数"
        int target = nums[0];
        int count = 1;

        for (int i = 1,len = nums.length; i < len; i++) {
            if (nums[i] == target) count++;      
            else {
                if (--count == 0) {          // 更替"候选人"
                    target = nums[i];
                    count = 1;
                }
            }
        }

        return target;
    }  
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :41.6 MB, 在所有 Java 提交中击败了100.00%的用户