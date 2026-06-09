### 解题思路
medium大水题

### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E >= C || F >= D || G <= A || H <= B) return (C - A)*(D - B) + (G - E)*(H -  F);
        int wid = 0, height = 0;
        if(E <= A){
            if(G >= C) wid = C - A;
            else wid = G - A;
        }
        else{
            if(G >= C) wid = C - E;
            else wid = G - E;
        }
        if(F <= B){
            if(H >= D) height = D - B;
            else height = H - B;
        }
        else{
            if(H >= D) height = D - F;
            else height = H - F;
        }
        return (C - A)*(D - B) + (G - E)*(H -  F) - wid * height;
    }
}
```