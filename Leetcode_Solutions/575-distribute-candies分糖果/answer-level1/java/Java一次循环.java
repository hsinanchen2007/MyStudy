### 解题思路

使用一个`boolean[200001]`的数组来记录糖果是否出现，如果没有出现过就加一，最后返回糖果类型和数组一半的最小值

![image.png](https://pic.leetcode-cn.com/b98e122c574c153b36076f57be32d64201cc728385a84b5cfd57c64dac5fe99b-image.png)

### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        boolean[] table = new boolean[200001];
        int count = 0;
        for (int i : candies) {
            count = table[i + 100000] ? count : count + 1;
            table[i + 100000] = true;
        }
        return Math.min(count, candies.length / 2);
    }
}
```