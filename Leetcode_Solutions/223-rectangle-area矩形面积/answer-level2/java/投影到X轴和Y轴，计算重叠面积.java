### 解题思路


### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_1 = calArea(A, B, C, D);
        int area_2 = calArea(E, F, G, H);
        if (isOverLap(A, B, C, D, E, F, G, H)){
            int x = Math.max(A, E) - Math.min(C, G);
            int y = Math.max(B, F) - Math.min(D, H);
            return area_1 + area_2 - x*y;
        }
        return area_1 + area_2;
    }

    private int calArea(int a, int b, int c, int d){
        int abs = Math.abs(a - c);
        int abs1 = Math.abs(b - d);
        return abs * abs1;
    }

    private boolean isOverLap(int A, int B, int C, int D, int E, int F, int G, int H){
        boolean x_over = !(C <= E || G <= A);
        boolean y_over = !(D <= F || H <= B);
        return x_over && y_over;
    }
}
```