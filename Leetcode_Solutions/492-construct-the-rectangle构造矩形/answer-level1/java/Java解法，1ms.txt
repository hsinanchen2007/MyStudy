执行用时 :1 ms, 在所有 Java 提交中击败了96.77%的用户
内存消耗 :33.4 MB, 在所有 Java 提交中击败了87.37%的用户

### 解题思路
中心拓展法，先找到平方根再向下拓展。
不要向上拓展，因为 1 到平方根的距离更近。

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
        int d = 0;
        for (int i =(int) Math.floor(Math.sqrt(area)) ; i > 0; i--) {
            if (area % i == 0) {
                d = i;
                break;
            }
        }
        return new int[]{area / d, d};
    }
}
```