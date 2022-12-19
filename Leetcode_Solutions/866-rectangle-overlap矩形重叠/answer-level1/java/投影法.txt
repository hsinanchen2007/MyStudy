### 解题思路
```text
投影法，两个矩形如果重叠，则其投影到x轴或者y轴的坐标必有交集
1. 如果投影到x轴没有交集，则没有重叠
2. 如果投影到y轴没有交集，则没有重叠
```

### 代码

```java
class Solution {
    // 位置检查，不重叠必定在上下左右
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] ||   // left
                rec1[3] <= rec2[1] ||   // bottom
                rec1[0] >= rec2[2] ||   // right
                rec1[1] >= rec2[3]);    // top
    }
    // 投影法
    public boolean isRectangleOverlapProjection(int[] rec1, int[] rec2) {
        // 投影到x轴不重叠或投影到y轴不重叠，则两个矩形不重叠
        // x轴不重叠
        if (rec2[0] >= rec1[2] || rec2[2] <= rec1[0]) {
            return false;
        }
        // y轴不重叠
        if (rec2[1] >= rec1[3] || rec2[3] <= rec1[1]) {
            return false;
        }
        return true;
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void isRectangleOverlap() {
        int[] rec1Input1 = {0,0,2,2};
        int[] rec2Input1 = {1,1,3,3};
        boolean result1 = solution.isRectangleOverlap(rec1Input1, rec2Input1);

        int[] rec1Input2 = {0,0,1,1};
        int[] rec2Input2 = {1,0,2,1};
        boolean result2 = solution.isRectangleOverlap(rec1Input2, rec2Input2);

        assertTrue(result1);
        assertFalse(result2);
    }
}
```