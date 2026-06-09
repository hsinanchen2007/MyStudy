### 解题思路
### 如题
    找出一个数组中最小的k个数。
    1、我们需要先把该数组排序（从小到大）。
    2、截取前k个数返回需要的数组。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        // 排序
        Arrays.sort(arr);
        // 返回前k个数
        return Arrays.copyOfRange(arr, 0, k);   
    }
}
```