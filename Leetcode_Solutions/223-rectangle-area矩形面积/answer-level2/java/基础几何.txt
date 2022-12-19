### 解题思路
执行时间3ms, 消耗内存38.6MB.
其实是一个很简单的几何问题,两矩形重叠面积即两矩形面积和减去重叠部分的面积,所以核心问题是求解重叠部分的面积
首先, 需要排除两个矩形不重叠的情况, 即矩形1完全在矩形2的上边/下边/左边/右边的情况
然后, 两个矩形重叠部分面积可以看做是四条横线与四条竖线相交的问题, 只需要确定两条最中间的横线和两条最中间的竖线即可.
以四条竖线举例
1. 已知A<C,A<G,E<G,E<C, 所以重叠矩形的左侧线要么是A要么是E,右侧线要么是C要么是G,因此加入一个判断即可返回重叠矩形的宽
2. 重叠矩形的高同理
![image.png](https://pic.leetcode-cn.com/35385f162306e4e82f11ba59084054fd92d014efd41053b8d3f6814868bee922-image.png)

### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //1. 计算重叠部分面积
        //如果把矩形看做是四条线,那么两个矩形重叠的面积就是四条横线中中间的两条线和四条竖线中中间的两条线组成的矩形的面积, 但是需要排除两个矩形没有重叠的情况
        int lapArea=0;
        if(!(E>=C||G<=A||B>=H||D<=F)){
            int width=middleTwo(A,C,E,G);
            int height=middleTwo(B,D,F,H);
            lapArea=width*height;
        }
        return (C-A)*(D-B)+(G-E)*(H-F)-lapArea;
        

    }
    public int middleTwo(int A,int C,int E,int G){
        //首先,A<C,E<G,E<C,A<G
        if(A<E)//E是第二小,确定第三小就可以
            return C<G?(C-E):(G-E);
        else  //A是第二小,确定第三小
            return C<G?(C-A):(G-A);
    }
}
```