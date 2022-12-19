### 解题思路
此处撰写解题思路
自己一直列举重合的情况，每种情况验证都较为复杂，且种类很多。（然后接近凌晨，去看了一下别人题解）
转换思路，通过判断不重合的情况，反推出其他情况都是重合的。
不重合的情况有4种， 1、矩形1 的最右x坐标小于等于  矩形2最左x坐标  
                   2、矩形2 的最右x坐标小于等于  矩形1最左x坐标 
                   3 、矩形1 的最大y坐标小于等于  矩形2的最小y坐标  
                   4 、矩形2的最大y坐标小于等于  矩形1的最小y坐标  

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
 
        if( rec1[2]<=rec2[0] ||  rec2[2]<=rec1[0] || rec1[1]>=rec2[3] ||rec2[1]>=rec1[3]  )
            return false;

                
        return true;         
    }
}
```