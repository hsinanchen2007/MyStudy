### 解题思路
此处撰写解题思路
首先两个矩形相不相交可以采用投影的方法，就有六种情况
![rectengleArea.png](https://pic.leetcode-cn.com/c169f0adbca6b99414d2aaa0d1514efb3802dfc2dc2c2448c3f831d365e0356f-rectengleArea.png)
其中：A表示第一个矩形的横坐标，B表示第二个矩形的横坐标
六种情况中前两种是不重叠的返回面积之和
后四种只需要考虑中间两列的值的差值，仔细观察可以发现左边获得最大值，右边获得最小值
对于纵坐标的分析依然如此。
### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S = (C-A)*(D-B)+(G-E)*(H-F);
        if(C <= E || G <= A || D <= F || H <= B)
            return S;
        int lengthX = Math.min(C,G)-Math.max(A,E);
        int lengthY = Math.min(D,H)-Math.max(B,F);
        return S-lengthX*lengthY;
    }
}


