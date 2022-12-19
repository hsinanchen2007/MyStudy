### 解题思路
当线段x1x2和x3x4重叠并且线段y1y2和y3y4重叠时，两块区域重叠

### 代码

```java
class Solution {
 
  private boolean Judge(int a1,int a2,int a3,int a4){
      //判断线段a1a2和a3a4是否重叠
      if(a3<a2&&a4>a1){return true;}
      return false;
  }
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
if(Judge(rec1[0],rec1[2],rec2[0],rec2[2])&&Judge(rec1[1],rec1[3],rec2[1],rec2[3]))
return true;
return false;

    }
}
```