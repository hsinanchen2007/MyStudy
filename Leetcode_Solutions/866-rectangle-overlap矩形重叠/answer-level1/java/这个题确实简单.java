### 解题思路
直接比较边界就可以了，找出所有不能重叠的情况，然后剩下的就是重叠了

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec2[2]<=rec1[0]||rec2[0]>=rec1[2]) return false;
        if(rec2[1]>=rec1[3]||rec2[3]<=rec1[1]) return false;
        return true;
    }
}
```