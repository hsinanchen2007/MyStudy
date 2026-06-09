### 解题思路
如果在某个线段加入后路径变为交叉的，那么新加入的线段必然和在它之前加入的5条线段相交

### 代码

```c
bool isSelfCrossing(int* x, int xSize){
    int pres[5] = { 0 };
    int presSize = 0;
    for(int i = 0; i < xSize; i++) {
        int now = x[i];
        if(presSize >= 3 && pres[0] <= pres[2] && now >= pres[1]) { return true; }
        if(presSize >= 4 && pres[2] >= pres[0] && pres[0] >= pres[2] - pres[4] && now >= pres[1] - pres[3] && pres[1] - pres[3] >= 0) { return true; }
        for(int j = 4; j >= 1; j--) { pres[j] = pres[j - 1]; }
        pres[0] = now;
        if(presSize < 5) { presSize++; }
    }
    return false;
}
```