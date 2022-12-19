执行用时：0ms
内存消耗：5.4MB

设i，j分别为子数组的左右下标。
对数组从左往右遍历，每次都先找到一个极大等差数列子数组P1，则P1的长度不为1或2的子数组都是一个等差数列子数组。设P1的长度为maxlen，则等差数列子数组个数为：（maxlen+1）*maxlen/2 - maxlen - （maxlen-1），即所有子数组个数减去长度为1和长度为2的子数组个数。
计算完P1的子等差数列个数后，更新**i为j-1**，继续上面的过程，直到到达数组最右端。
```
int numberOfArithmeticSlices(int* A, int ASize){
    if(ASize<3) return 0;

    int num=0;
    int j;
    for(int i=0; i+2<ASize; i=j-1){
        int d = A[i+1] - A[i];
        for(j=i+2; j<ASize; j++){
            if(A[j]-A[j-1]==d) {
                if(j==ASize-1){
                    int maxlen = j-i+1;
                    num += (maxlen-3)*maxlen/2+1;//(maxlen+1)*maxlen/2 - maxlen - (maxlen-1);
                    break;
                }
            }
            else {
                int maxlen = j-i;
                num += (maxlen-3)*maxlen/2+1;
                break;
            }
        }
    }
    return num;
}
}
```
