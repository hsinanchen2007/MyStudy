### 解题思路
1的起始点小于2的结束点并且1的结束点大于2的起始点
换过来再判断一遍即可

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1.length < 4 || rec2.length < 4)  return false;
        if((rec1[0] < rec2[2] && rec1[1] < rec2[3] && rec1[2] > rec2[0] && rec1[3] > rec2[1]) ||  (rec2[0] < rec1[2] && rec2[1] < rec1[3] && rec2[2] > rec1[0] && rec2[3] > rec1[1])){
                return true;
            }
        return false;
    }
}
```