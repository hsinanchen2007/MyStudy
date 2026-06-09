先调整行，后调整列，先判断每行第一个数字是否是1，若不是则翻转此行，然后判断每列里0的个数是否大于1的个数，若0多，则翻转此列，最后把二进制转换成十进制累加返回结果。
```
int matrixScore(int** A, int ASize, int* AColSize){
    //行调整
    for(int i=0;i<ASize;i++)
        if(A[i][0]==0)
            for(int j=0;j<AColSize[i];j++){
                A[i][j]++;
                A[i][j]%=2;
            }
    //列调整
    for(int i=0;i<AColSize[0];i++){
        int sum=0;
        for(int j=0;j<ASize;j++)
            sum+=A[j][i];
        if(sum*2<ASize)
            for(int j=0;j<ASize;j++){
                A[j][i]++;
                A[j][i]%=2;
            }
    }
    //二进制转十进制累加
    long long n=0;
    for(int i=0;i<ASize;i++){
        int m=0;
        for(int j=0;j<AColSize[i];j++){
            m*=2;
            m+=A[i][j];
        }
        n+=m;
    }
    return n;
}
```
