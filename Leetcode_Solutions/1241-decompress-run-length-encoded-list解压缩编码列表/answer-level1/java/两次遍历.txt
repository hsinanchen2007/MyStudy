### 解题思路
1. 求出数组长度
2. 顺序输出
![image.png](https://pic.leetcode-cn.com/13bd326e27e6febcd275096e59ce86284dcd0d5789f99fc2d238b385f08e03ca-image.png)
### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 1; i += 2) {
            count += nums[i];
        }
        int[] rs = new int[count];
        int index = 0;
        for (int i = 1; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i - 1]; j++) {
                rs[index++] = nums[i];
            }
        }
        return rs;
    }
}
```