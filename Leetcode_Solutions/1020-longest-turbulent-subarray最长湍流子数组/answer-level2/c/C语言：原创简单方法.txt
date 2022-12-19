**解题思路：**
用数组a,大小为(ASize-1)记录相邻两数的符号关系：
1. A[i] > A[i + 1],a[i] = 1;
2. A[i] < A[i + 1],a[i] = -1;
3. A[i] == A[i + 1],a[i] = 0;
再遍历一次数组a,用mcnt记录连续的互相异号的数的个数的最大值，return mcnt + 2;
(排除了特殊情况数组A中所有的数都相同，如[9,9,9]。这时应返回1,而非2).

```c


int maxTurbulenceSize(int* A, int ASize){
    if (ASize == 1)
        return 1;

    int j = 1;
    //特殊情况:数组A中所有的数都相同
    for (; j < ASize; j++){
        if (A[j] != A[j - 1])
            break;
    }
    if (j == ASize)
        return 1;

    //一般情况
    int* a = (int*)malloc(sizeof(int) * (ASize - 1));
    for (int i = 0; i < ASize - 1; i++){
        if (A[i] > A[i + 1])
            a[i] = 1;
        else if (A[i] < A[i + 1])
            a[i] = -1;
        else
            a[i] = 0; 
    }
    int cnt = 0, mcnt = 0;
    for (int i = 0; i < ASize - 2; i++){
        if (a[i] * a[i + 1] < 0){
            cnt++;
            if (cnt > mcnt)
                mcnt = cnt;
        }
        else
            cnt = 0;//遇到不满足条件的(3个数递增or3个数递减or2个数相等)，cnt置为0
    }
    return mcnt + 2;
}


```