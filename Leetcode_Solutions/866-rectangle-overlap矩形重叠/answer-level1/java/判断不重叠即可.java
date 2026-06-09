### 解题思路
只需要判断两个矩阵不想交即可，
1. 矩阵一在矩阵二的**右边**：`rec1[0] >= rec2[2];`
2. 矩阵一在矩阵二的**上面**：`rec1[1] >= rec2[3];`
3. 矩阵一在矩阵二的**左边**：`rec1[2] <= rec2[0];`
4. 矩阵一在矩阵二的**下面**：`rec1[2] <= rec2[0]。`
即完成判断。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1] || rec1[2] <= rec2[0]);
    }
}
```