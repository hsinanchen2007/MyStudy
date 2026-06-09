### 解题思路
利用以下两个特性：
1，两个相同的值，异或结果是0
2，任何一个数与0异或结果是其本身

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        //使用异或操作来实现
        if (nums.length == 0) {
            return 0;
        }

        //保存单个的值
        int single = nums[0];

        //循环进行异或
        for (int i = 1; i < nums.length; i++) {
            single ^= nums[i];
        }

        return single;
    }
}
```