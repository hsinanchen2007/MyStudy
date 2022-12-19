### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        //rec2在rec1右边
        if(rec2[0]-rec1[2]>=0){
            return false;
        }
        //rec2在rec1上边
        if(rec2[1]-rec1[3]>=0){
            return false;
        }
        //rec2在rec1左边
        if(rec2[2]-rec1[0]<=0){
            return false;
        }
        //rec2在rec1下边
        if(rec2[3]-rec1[1]<=0){
            return false;
        }
        return true;
    }
}
```