![image.png](https://pic.leetcode-cn.com/fba8c996e90c5c4b9be515d16c294165acb4f0e694c2e911677a439b5149efe1-image.png)
看着官方题解写的，不然实在想不到
```
int minSwapsCouples(int* row, int rowSize){
    int rst = 0;
    for (int i = 0; i < rowSize; i+=2) {
        int x = row[i];
        if (row[i+1] == (x ^ 1)) continue;
        rst++;
        for (int j = i+1; j < rowSize; j++) {
            if (row[j] == (x^1)) {
                row[j] = row[i+1];
                row[i+1] = x^1;
                break;
            }
        }
    }
    return rst;
}
```
