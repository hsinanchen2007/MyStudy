
![image.png](https://pic.leetcode-cn.com/ada428af4959e6e612e8c6e387c2efa686d230daa83f14e2ce8f47881f389cd0-image.png)
思路：
第一遍 遍历行，将 col=0 所在的行取反，
第二遍，统计列中1个数colCnt, 如果colCnt <= Asize/2,则此列可以进行反转，直接获得对应二进制对应位数上1的个数为 Asize-colCnt。
最后获得结果 
int matrixScore(int** A, int ASize, int* AColSize){
    int row = 0;
    int col = 0;
    int colCnt = 0;
    int ret = 0;

    for (row = 0; row < ASize; row++) {
        if (A[row][0] == 0) {
            for (col = 0; col < *AColSize; col++) {
                // 反转元素
                A[row][col] = 0x1&(~A[row][col]);
            }
        }
    }

    for (col = 0; col < *AColSize; col++) {
        colCnt = 0;
        // 统计col 值为1 的个数是否超过*AColSize/2 
        for (row = 0; row < ASize; row++) {
            if(A[row][col] == 1) {
                colCnt++;
            }
        }

        printf("%d", colCnt);

        if (colCnt <= (ASize)/2) {
            colCnt = ASize-colCnt;
        }

        printf("%d", colCnt);

        ret = ret * 2+colCnt;
    }
    
    return ret;
}


