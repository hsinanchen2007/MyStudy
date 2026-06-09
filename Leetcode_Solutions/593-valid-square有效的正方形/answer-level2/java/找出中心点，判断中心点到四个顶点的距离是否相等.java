### 解题思路
1. 如果四个点中有相同的点，返回false;
2. 找出对角线两个点
3. 求出中心点
4. 判断中心点到四个顶点的距离是否相等

### 代码

```java
class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        if(isSame(p1, p2) || isSame(p1, p3) || isSame(p1, p4) || isSame(p2, p3) || isSame(p3, p4)){
            return false;
        }
        int length1 = calculateDis(p1, p2);
        int length2 = calculateDis(p1, p3);
        int length3 = calculateDis(p1, p4);
        double midX ;
        double midY ;
        if (length1 > length2 && length2 == length3) {
            midX = (p2[0] + p1[0]) / 2.0;
            midY = (p2[1] + p1[1]) / 2.0;
        } else if (length2 > length1 && length1 == length3) {
            midX = (p3[0] + p1[0]) / 2.0;
            midY = (p3[1] + p1[1]) / 2.0;
        } else if (length3 > length1 && length1 == length2) {
            midX = (p4[0] + p1[0]) / 2.0;
            midY = (p4[1] + p1[1]) / 2.0;
        } else {
            return false;
        }
        double mid1 = calculateDisDouble(p1, new double[]{midX, midY});
        double mid2 = calculateDisDouble(p2, new double[]{midX, midY});
        double mid3 = calculateDisDouble(p3, new double[]{midX, midY});
        double mid4 = calculateDisDouble(p4, new double[]{midX, midY});
        return mid1 == mid2 && mid2 == mid3 && mid3 == mid4;
    }

    private double calculateDisDouble(int[] p, double[] t){
        return (p[0] - t[0]) * (p[0] - t[0]) + (p[1] - t[1]) * (p[1] - t[1]);
    }

    private int calculateDis(int[] p, int[] t){
        return (p[0] - t[0]) * (p[0] - t[0]) + (p[1] - t[1]) * (p[1] - t[1]);
    }

    private boolean isSame(int[] p, int[] t){
        return p[0] == t[0] && p[1] == t[1];
    }
}
```