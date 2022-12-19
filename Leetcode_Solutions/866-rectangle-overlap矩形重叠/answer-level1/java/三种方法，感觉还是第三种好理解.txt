### 解题思路

### 主要讲一下，第三种判断重叠时的取值范围

*若两个矩形相交，则rec2取值范围中必须和rec1的取值范围有交集*
![图片.png](https://pic.leetcode-cn.com/0e127d86dc073dc152c75848f6b349fdb23288e5f979eae9e61bee2b0c5f5049-%E5%9B%BE%E7%89%87.png)

*rec1 X取值范围rec1[0]--->rec1[2] Y取值范围rec1[1]--->rec1[3] 
rec2 X取值范围rec2[0]--->rec2[2] Y取值范围rec2[1]--->rec2[3]*

#### rec2的X取值范围必须要和rec1X的取值范围有交集，也可以是说是rec2的X取值范围不能落在rec1的X取值范围左右两侧
![图片.png](https://pic.leetcode-cn.com/ef361d6620cad352967ac70faf182cacc072d35cd5980b1675fb67b2f9a4ba03-%E5%9B%BE%E7%89%87.png)


其中rec2 Xmax对应rec2[2],rec2 Xmin对应rec2[0],rec1 Xmax对应rec1[2],rec2 Xmin对应rec1[0]
可表示为 !(rec2[0]>=rec1[2]||rec2[2]<=rec1[0])


#### 同理rec2的Y取值范围必须要和rec1的Y取值范围有交集,也可以是说是rec2的Y取值范围不能落在rec1的Y取值范围上下两侧

可表示为 !(rec2[1]>=rec1[3]||rec2[3]<=rec1[1])

两个条件必须同时满足，所有得到
return (!(rec2[0]>=rec1[2]||rec2[2]<=rec1[0]))&&(!(rec2[1]>=rec1[3]||rec2[3]<=rec1[1]));
简化一下即
return rec2[0]<rec1[2]&&rec2[2]>rec1[0]&&rec2[1]<rec1[3]&&rec2[3]>rec1[1];



### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return cal3(rec1,rec2);

    }

    private boolean cal1(int[] rec1, int[] rec2){
        /***如何判断两个矩形是否相交?
            假定矩形是用一对点表达的(minx,miny)(maxx, maxy)
            那么两个矩形rect1{(minx1,miny1)(maxx1, maxy1)}, rect2{(minx2,miny2)(maxx2, maxy2)}
            相交的结果一定是个矩形，构成这个相交矩形rect{(minx,miny)(maxx, maxy)}的点对坐标是：
            minx = max(minx1, minx2)
            miny = max(miny1, miny2)
            maxx = min(maxx1, maxx2)
            maxy = min(maxy1, maxy2)
            如果两个矩形不相交，那么计算得到的点对坐标必然满足
            minx > maxx
            或者
            miny > maxy 
        ****/
        int x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3],a1=rec2[0],b1=rec2[1],a2=rec2[2],b2=rec2[3];
        int minx = x1>a1?x1:a1;
        int miny = y1>b1?y1:b1;
        int maxx = x2>a2?a2:x2;
        int maxy = y2>b2?b2:y2;

        if(minx>=maxx||miny>=maxy){
            return false;
        }else{
            return true;
        }

    }

    private boolean cal2(int[] rec1, int[] rec2){
       //第二种方法，考虑不相交的情况（相交即是不相交取反）即rec2在rec1 四周
        //rec2 在rec上方rec2
        //rec2[1]>rec1[3]

        //rec2 在rec下方
        //rec2[3]<rec1[1]

        //rec2 在rec左方
        //rec2[2]<rec1[0]

        //rec2 在rec右方
        //rec2[0]>rec1[2]
        
        //所以正确返回是
        //return !(rec2[1]>=rec1[3]||rec2[3]<=rec1[1]||rec2[2]<=rec1[0]||rec2[0]>=rec1[2]);

        //简化后
        return rec2[1]<rec1[3]&&rec2[3]>rec1[1]&&rec2[2]>rec1[0]&&rec2[0]<rec1[2];

    }

    private boolean cal3(int[] rec1, int[] rec2){
       //第三种方法 即考虑rec2中有一个点够落在rec1中点取整范围内
        //rec1 x取值rec1[0]--->rec1[2] y取值rec1[1]--->rec1[3]
        //rec2 x取值rec2[0]--->rec2[2] y取值rec2[1]--->rec2[3]
        //画坐标系中 可以理解成x取值范围为一条水平直线， rec2X的取值范围不应该落在rec1X的左右两侧
        //即 !(rec2[0]>=rec1[2]||rec2[2]<=rec1[0]) 简化 rec2[0]<rec1[2]&&rec2[2]>rec1[0]

        // rec2Y的取值范围不应该落在rec1Y的上下两侧 
        //!(rec2[1]>=rec1[3]||rec2[3]<=rec1[1]) 简化 rec2[1]<rec1[3]&&rec2[3]>rec1[1]
        
        //return (!(rec2[0]>=rec1[2]||rec2[2]<=rec1[0]))&&(!(rec2[1]>=rec1[3]||rec2[3]<=rec1[1]));

        //简化一下 (rec2[0]<rec1[2]&&rec2[2]>rec1[0])&&(rec2[1]<rec1[3]&&rec2[3]>rec1[1])
        return rec2[0]<rec1[2]&&rec2[2]>rec1[0]&&rec2[1]<rec1[3]&&rec2[3]>rec1[1];
    }






}
```