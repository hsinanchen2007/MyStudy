### 解题思路
请参考注释和代码，非常简单的解法

### 代码

```java
class Solution {
    // 此题用到了位运算中的一个特性
    // a^b^c = a^c^b = b^c^a = c^b^a = ...
    // 即XOR运算支持交换律
    public int singleNumber(int[] nums) {
        int a = 0;
        for(int m:nums){
            a = a^m;
        }
        return a;
    }
}
```