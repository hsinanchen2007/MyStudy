js 纯暴力
```
var computeArea = function(A, B, C, D, E, F, G, H) {
    const sum = (C - A) * (D - B) + (G - E) * (H - F);
    const minX1 = Math.max(A, E);
    const minX2 = Math.min(C, G);
    if(minX2 <= minX1) return sum;
    const minY1 = Math.max(B, F);
    const minY2 = Math.min(D, H);
    if(minY2 <= minY1) return sum;
    return sum - (minX2 - minX1) * (minY2 - minY1);
};
```
