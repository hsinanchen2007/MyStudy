### 解题思路
官方解题有个小于18，其实不用这样，感觉加这个主要是为了推出循环，在x=1或者y=1时如果不加条件判断会死循环的，因为1的任何次幂都等于1.

### 代码

```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> seen = new HashSet();
        boolean isX = false;
        for (int i = 0; Math.pow(x, i) <= bound && !isX; ++i) {
            boolean isY = false;
            for (int j = 0; Math.pow(y, j) <= bound && !isY; ++j) {
                int v = (int) Math.pow(x, i) + (int) Math.pow(y, j);
                if (v <= bound) {
                    seen.add(v);
                }
                if (y == 1) {
                    isY = true;
                }
            }
            if (x == 1) {
                isX = true;
            }
        }

        return new ArrayList(seen);
    }
}
```