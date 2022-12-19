### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1_, int[] rec2_) {
        float[] rec1 = new float[4];
        float[] rec2 = new float[4];
        for(int i=0;i<4;i++) rec1[i] = (float)rec1_[i];
        for(int i=0;i<4;i++) rec2[i] = (float)rec2_[i];
        return ((Math.abs (rec1[2] - rec1[0]) + Math.abs (rec2[2] - rec2[0])) >
                Math.max (Math.abs (rec2[2] - rec1[0]), Math.abs (rec1[2] - rec2[0]))) &&
                ((Math.abs (rec1[3] - rec1[1]) + Math.abs (rec2[3] - rec2[1])) >
                 Math.max (Math.abs (rec2[3] - rec1[1]),Math.abs (rec1[3]-rec2[1])));
    }
}
```