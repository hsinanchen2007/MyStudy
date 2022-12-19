### 解题思路

W <= sqrt(area)，因此只要找到sqrt(area)之后的第一个被area整除的数字即可。

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
        int W = (int) Math.sqrt(area);
        while (area % W != 0) {
            W --;
        }
        return new int[]{area / W, W};
    }
}
```