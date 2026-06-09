### 解题思路
分离成两个一维题目

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        boolean t1 = !(rec1[0]>=rec2[2]||rec2[0]>=rec1[2]);
        boolean t2 = !(rec1[1]>=rec2[3]||rec2[1]>=rec1[3]);
        return t1&&t2?true:false;
    }
}
```