### 解题思路
此处撰写解题思路
重叠的情况有
1.圆在矩形内部（只要圆心在矩形内部肯定包括这种情况）
2.矩形有一个角落在圆范围内
3.边交叉（或者相切）
![WechatIMG1728.jpeg](https://pic.leetcode-cn.com/8fbfebe4fc2372ab5d8ac0f844a0238a31cc5923c61b673232c4e7f04e7e1495-WechatIMG1728.jpeg)

着重说第3种
![WechatIMG99.jpeg](https://pic.leetcode-cn.com/a6ce85046b6a972d4cfef859e01b46c01e0a66399b3fc957eebcc99c520b33e2-WechatIMG99.jpeg)


先求圆心P到矩形边的最短距离，如果相交那么勾股定理可以求出与矩形相交的长度l
只要Py + l和Py-l在y1和y2的范围内那就肯定是先交的
x也是同理
### 代码

```java
class Solution {
     public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
          int[][] jx = {{x1, y1},{x2, y2},{x1, y2},{x2, y1}};
        
        //有一个角落在圆范围内
          for(int i=0;i<4;i++){
           boolean flaga =  (jx[i][0]-x_center) *(jx[i][0]-x_center)  + (jx[i][1]-y_center) *(jx[i][1]-y_center) <= radius * radius;
            if(flaga){
                return true;
            }
        }
        
        //在矩形内部
        if(x_center>=x1 && x_center <= x2 && y_center>=y1 && y_center<=y2){
            return true;
        }
        //边交叉
        int xd = Math.min(Math.abs(x_center-x1),Math.abs(x_center-x2));
        int yd = Math.min(Math.abs(y_center-y1),Math.abs(y_center-y2));
        //如果有交叉肯定有点在圆上，r的平方-线的距离平方对应的偏移量在线上就是交叉
        int xdd = radius*radius - xd*xd;
        if( xdd>=0 && Math.sqrt(xdd) + y_center<y2 && y_center -  Math.sqrt(xdd)  > y1 ){
            return true;
        }
        int ydd = radius*radius - xd*xd;
        if( ydd >=0 && Math.sqrt(ydd) + x_center < x2 && x_center - Math.sqrt(ydd) >x1  ){
            return true;
        }

        return false;
    }
}
```