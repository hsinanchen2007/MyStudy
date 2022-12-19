### 解题思路
题设里隐含着rec1[0] < rec1[2] rec1[1] < rec1[3]
只需要判断线段一的右端点和线段二的左端点的相对位置即可

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if( rec2[0] >= rec1[2] || rec1[0] >= rec2[2]){
            return false;
        }
        if( rec2[1] >= rec1[3] || rec1[1] >= rec2[3]){
            return false;
        }

        return true;
    }
}
```