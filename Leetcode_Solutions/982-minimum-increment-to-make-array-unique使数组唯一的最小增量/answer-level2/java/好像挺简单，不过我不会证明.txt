### 解题思路
先排序，每次有重复，就增加到前面的最大值+1

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int minTime = 0;
        Arrays.sort(A);
        Integer max = null;
        for (int i : A) {
            if(max == null || i > max ) {
                max = i;
            } else {
                max++;
                minTime += max - i;
            }
        }
        return minTime;
    }
}
```