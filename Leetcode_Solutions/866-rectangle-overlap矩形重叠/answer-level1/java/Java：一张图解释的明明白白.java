### 解题思路
用计算机视觉里计算IoU的方法，0ms：
![image.png](https://pic.leetcode-cn.com/f3025b23d4ccdf6eb3e4d9d2560dee9603be01c7be4385da595babff35802950-image.png)
第一个矩形的左下坐标：(x1,y1)，高h1，宽w1；
第二个矩形的左下坐标：(x2,y2)，高h2，宽w2；

### 代码
```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int h1 = rec1[3]-rec1[1];
        int w1 = rec1[2]-rec1[0];
        int h2 = rec2[3]-rec2[1];
        int w2 = rec2[2]-rec2[0];
        int h = h1+h2-(Math.max(rec1[1]+h1,rec2[1]+h2)-Math.min(rec1[1],rec2[1]));
        int w = w1+w2-(Math.max(rec1[0]+w1,rec2[0]+w2)-Math.min(rec1[0],rec2[0]));
        if(h<=0 || w<=0){
            return false;
        }return true;
    }
}
```