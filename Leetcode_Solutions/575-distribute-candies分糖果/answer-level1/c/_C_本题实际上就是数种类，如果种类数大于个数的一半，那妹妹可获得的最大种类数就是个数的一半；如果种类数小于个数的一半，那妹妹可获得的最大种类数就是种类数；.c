### 解题思路
此处撰写解题思路

### 代码

```c
int distributeCandies(int* candies, int candiesSize){
    int i, j;
    int d;
    int tmp;
    int cnt;
    d = candiesSize / 2;
    // sort
    while (d > 0) {
        for (i = d; i < candiesSize; i++) {
            tmp = candies[i];
            j = i - d;
            while (j >= 0 && tmp < candies[j]) {
                candies[j + d] = candies[j];
                j = j - d;
            }
            candies[j + d] = tmp;
        }
        d = d / 2;
    }
    // get types
    cnt = 1;
    for (i = 0; i < candiesSize - 1; i++) {
        if (candies[i] != candies[i + 1]) {
            cnt++;
        }
    }
    // get results, comparison
    tmp = candiesSize / 2;
    if (tmp >= cnt) {
        d = cnt;
    } else {
        d = tmp;
    }
    return d;
}
```