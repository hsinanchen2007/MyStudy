### 解题思路
我们通过在纸上画图，发现两个矩阵重合的情形有很多，但是不重合的情形却只有四种，即 rec1[左] >= rec2[右]，rec1[下] >= rec2[上]，
rec1[右] <= rec2[左]，rec1[上] <= rec2[下] 这四种情况

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[2] <= rec2[0] || rec1[3] <= rec2[1]) return false;
        
        

        return true;
    
    }
}
```