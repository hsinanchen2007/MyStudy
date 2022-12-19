### 解题思路
#### 矩形重叠，可以这样理解  
```
* 1. x轴两条直线有相交
* 2. y轴两条直线有相交
```    
#### 如何判断水平相交

```
1.距离Y轴更远的那条线的起始点,比距离Y轴更近的那条线的终点要小。
    设
        xA1:为更近那条线的起点
        xA2:为更近那条线的终点
        xB1:为更远那条线的起点

    当满足
        xA1 <= xB1 <xA2 
    即满足两线水平相交
```

#### 垂直相交同理


### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1 == null || rec2 == null || rec1.length != 4 || rec1.length != 4){
            return false;
        }

        //判断水平相交
        if(rec1[0] <= rec2[0]){
            //矩形1里Y轴更近
            if(!lineOverlap(rec1[0] , rec1[2] , rec2[0])){
                return false;
            }
        } else {
            //矩形2里Y轴更近
            if(!lineOverlap(rec2[0] , rec2[2] , rec1[0])){
                return false;
            }
        }

        //判断垂直相交
        if(rec1[1] <= rec2[1]){
            //矩形1里X轴更近
            if(!lineOverlap(rec1[1] , rec1[3] , rec2[1])){
                return false;
            }
        } else {
            //矩形2里X轴更近
            if(!lineOverlap(rec2[1] , rec2[3] , rec1[1])){
                return false;
            }
        }

        return true;
    }

    private boolean lineOverlap(int pA1 , int pA2 , int pB1){
        return (pA1 < pB1 && pB1 < pA2)
            || (pA1 <= pB1 && pB1 < pA2);
    }
}
```