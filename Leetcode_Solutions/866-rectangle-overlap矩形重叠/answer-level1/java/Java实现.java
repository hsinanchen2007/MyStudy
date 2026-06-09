### 解题思路
只需要排除边界条件，剩下的就是符合重叠条件的
边界条件有：矩阵1的左下角大于等于矩阵二的右上角
            矩阵1的右上角小于矩阵二的左下角

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {

        if(rec1[2]<=rec2[0]||rec1[3]<=rec2[1]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]) return false;

        else return true;
    }
}
```