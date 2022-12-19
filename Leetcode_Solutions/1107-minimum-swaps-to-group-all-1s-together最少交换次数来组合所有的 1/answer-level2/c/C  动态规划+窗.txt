总的1个数就是窗长，计算第1个窗内0的个数，然后每右移动1步窗，看窗头尾2个数的1和0情况，根据上一次的结果计算新窗内的0个数即可（2个int变量动态规划），
遍历一遍得出结果。
执行用时 :104 ms, 在所有 C 提交中击败了96.15%的用户
内存消耗 :11.7 MB, 在所有 C 提交中击败了100.00%的用户
```
int minSwaps(int* data, int dataSize)
{
    int i, begin, min, curr;
    int windowLen = 0, last = 0;
    for (i = 0; i < dataSize; i++) {
        if (data[i] == 1) {
            windowLen++;  /* 窗大小 */
        }
    }
    for (i = 0; i < windowLen; i++) {
        if (data[i] == 0) {
            last++;  /* 动态规划初始值，0个数就是需要交换的次数 */
        }
    }
    min = last;
    begin = 1;
    while (begin <= dataSize - windowLen) {
        curr = last;  /* 上次窗体内0个数 */
        if (data[begin - 1] == 0) { /* 移出窗外0，则0个数减少1 */
            curr--;
        }
        if (data[begin + windowLen - 1] == 0) { /* 移入窗内0，则0个数增加1 */
            curr++;
        }
        if (curr < min) {
            min = curr;
        }
        begin++;
        last = curr;
    }
    return min;
}
```
