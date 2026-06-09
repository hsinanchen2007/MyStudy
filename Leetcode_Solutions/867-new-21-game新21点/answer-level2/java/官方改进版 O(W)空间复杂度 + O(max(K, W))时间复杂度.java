### 代码
```java
class Solution {
        
    public double new21Game(int N, int K, int W) {
        double[] rec = new double[W];
        double save, temp;
        int l, t;
        t = Math.min(N - K + 1, W);
        save = t;
        for(int i = 0; i < t; i++)
            rec[i] = 1.0;
        l = W - 1;
        for(int i = K - 1; i >= 0; i--){
            temp = save / W;
            save += temp - rec[l];
            rec[l] = temp;
            l--;
            if(l < 0){
                l = W - 1;
            }
        }
        l++;
        if(l == W)
            l = 0;
        return rec[l];
    }
}
```