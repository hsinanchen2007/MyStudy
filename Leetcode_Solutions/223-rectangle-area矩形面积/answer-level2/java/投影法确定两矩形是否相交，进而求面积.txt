### 解题思路
使用投影法
两个矩形相交，那么他们在x、y轴上的投影必定都相交
x轴投影线相交条件：Math.min(C, G) > Math.max(A, E)
y轴投影线相交条件：Math.min(D, H) > Math.max(B, F)

### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 总面积
        int total = (C-A)*(D-B) + (G-E)*(H-F); 

        // 判断是否相交
        if(Math.min(C, G) > Math.max(A, E) &&
                Math.min(D, H) > Math.max(B, F)){ // 相交
            return total - (Math.min(C, G) - Math.max(A, E)) * (Math.min(D, H) - Math.max(B, F));
        } else { // 不相交
            return total;
        }
       
    }
}
```