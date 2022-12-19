一、概述流程方法：
    遍历记录arr中非零项索引index
    多次循环将arr中能跳转至0的项项置为0
    最终arr若全为0，则 start 为任意值（范围内）皆可跳转至0，返回true
    若部分非零，直接判断start是否在index非零数组内，若在则返回false，否则返回true
二、细节
    多次循环跳出方式：判断非零项数目是否为0，判断两次循环后非零项数目是否发生变化
    index初始化为-1

源代码如下
```
bool canReach(int* arr, int arrSize, int start){
    int index[arrSize+1];
    memset(index, -1, sizeof(index));
    int i = 0;
    int k = 0;
    int cnt = 0;
    int flg = 1;
    int rslt = 0;
    int ii = 0;
    for (i = 0; i < arrSize; i++) {
        if (arr[i] != 0) {
            index[k] = i;
            k++;
        }
    }
    cnt = k;
    while (flg) {
        flg = 0;
        for (i = 0; i < k; i++) {
            if (index[i] != -1) {
                if (index[i] + arr[index[i]] < arrSize) {
                    if (arr[(index[i] + arr[index[i]])] == 0) {
                        arr[index[i]] = 0;
                        cnt--;
                        flg = 1;
                        index[i] = -1;
                    }
                } 
            }
            if (index[i] != -1) {
            if ((index[i] - arr[index[i]]) >= 0) {
                    if (arr[index[i] - arr[index[i]]] == 0) {
                        arr[index[i]] = 0;
                        cnt--;
                        flg = 1;
                        index[i] = -1;
                    }
                }
            }
        }
        if (cnt == 0) {
            flg = 0;
            rslt = true;
        }    
    }
    if (arr[start] == 0) {
        rslt = true;
    } else {
        rslt = false;
    }
    return rslt;
}
```
