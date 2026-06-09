### 解题思路
而矩阵不相交相对关系可由矩阵的边的相对关系判断
上下左右四个方位，四种情形
而边的相对关系可由角坐标判断（题目已明确为正方矩阵）


### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        boolean flag = rec2[2] <= rec1[0] //rec2右上角x与左下角x比较
                    || rec2[3] <= rec1[1] //rec2右上角y与左下角y比较
                    || rec2[0] >= rec1[2]
                    || rec2[1] >= rec1[3];
        return !flag;
    }
}
```