### 解题思路
![Snipaste_2020-03-12_16-09-09.png](https://pic.leetcode-cn.com/c20678bb258efb3101fd0b863a9ff67dfcd459e64b628a578c233789fa64ef38-Snipaste_2020-03-12_16-09-09.png)

看了好几遍题。确认就是扫描一遍，找到第一个递减的位置

### 代码

```c
int peakIndexInMountainArray(int* A, int ASize){
    int i=0;
    while(A[i]<A[i+1]) i++;
    return i;
}
```