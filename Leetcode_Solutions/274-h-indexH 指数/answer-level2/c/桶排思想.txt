### 解题思路
此处撰写解题思路

### 代码

```c
//两种方法：1.采用计数排序的方法；2.先排序，然后采用水位线思想，线性扫描
int hIndex(int* citations, int citationsSize){
    int n = citationsSize + 1;
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] > citationsSize) {
            count[citationsSize]++;
        } else {
            count[citations[i]]++;
        }
    }

    int k = citationsSize;
    for (int s = count[citationsSize]; k > s; s += count[k]) {
        k--;
    }
    return k;
} 
```