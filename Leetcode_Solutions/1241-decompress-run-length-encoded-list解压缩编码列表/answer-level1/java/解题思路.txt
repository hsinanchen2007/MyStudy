### 解题思路
1.计算出所有b共有多少个。
2.将每个b添加到结果数组中。


### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int capacity = 0;
        // 计算nums中b的总个数
        for (int i = 0; i < nums.length; i += 2) {
            capacity += nums[i];
        }
        int[] res = new int[capacity];
        // [a, b] -> 共有a个b
        int a, b;
        int size = 0;
        for (int i = 0; i < nums.length; i += 2) {
            a = nums[i];
            b = nums[i + 1];
            for (int j = size; j < a + size; j++) {
                res[j] = b;
            }
            // 维护数组当前存储个数
            size += a;
        }
        return res;
    }
}
```