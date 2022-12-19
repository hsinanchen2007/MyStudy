### 解题思路
先找到打印元素的个数，再找到索引和值的关系，然后在数组中添加元素即可
提前双百 哈哈哈

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int max = (int) Math.pow(10, n) - 1;
        int[] arr = new int[max];
        for (int i = 0; i < max; i++) {
            arr[i] = i + 1;
        }
        return arr;
    }
}
```