### 解题思路
此题考查逆向思维，解题方法为排除 不相交特征 其他情况均为相交，用时击败率100%。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1[2]<=rec2[0]||rec1[3]<=rec2[1]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]) return false;
        return true;
    }
}
```