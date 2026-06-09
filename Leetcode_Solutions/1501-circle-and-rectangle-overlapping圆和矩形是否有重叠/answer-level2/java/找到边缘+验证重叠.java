### 解题思路
第一次活动 双 100%
![截屏2020-04-05 上午1.25.47.png](https://pic.leetcode-cn.com/1fdbf8a23bd09a394ca74d06d78bca821bc93d0abfd9484a924144e741e38fe0-%E6%88%AA%E5%B1%8F2020-04-05%20%E4%B8%8A%E5%8D%881.25.47.png)

基本思路就是 大家说的，用圆在长方形边缘滚一圈。判断实际圆心是否在这个 4个四分之一圆+5个十字排列长方形 的内部

### 代码

```java
class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (overlapRectangl(x1-radius,y1,x2+radius,y2, x_center, y_center)){
            return true;
        }
        if (overlapRectangl(x1,y1-radius,x2,y2+radius, x_center, y_center)){
            return true;
        }
        
        return overlapRound(x1,y1, x_center,y_center,radius) ||
               overlapRound(x1,y2, x_center,y_center,radius) ||
               overlapRound(x2,y1, x_center,y_center,radius) ||
               overlapRound(x2,y2, x_center,y_center,radius) ;
    }
    ///左下/右上两个点构成的长方形 是否 包含 圆心
    boolean overlapRectangl(int p1x, int p1y, int p2x, int p2y, int cx, int cy){
        return p1x<=cx && cx <= p2x && p1y <= cy && cy <= p2y; 
    }
    ///某一个点 是否 在 圆 当中
    boolean overlapRound(int p1x,int p1y, int cx, int cy, int radius){
        return Math.pow(p1x-cx-0.0, 2) + Math.pow(p1y-cy-0.0, 2) <= Math.pow(radius-0.0, 2);
    }
}
```