### 解题思路
此处撰写解题思路
        //r0,r1,r2,r3    c0,c1,c2,c3
        //当这些时候 不满足相互覆盖：r0>c2 ,c0>r2 ,r3<c1 ,c3<r1
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[1] >= rec2[3]);
    }
}
```