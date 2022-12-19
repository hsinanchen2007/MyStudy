/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路: 双重循环 一次完成
 *
 */
```
public int[][] flipAndInvertImage(int[][] A) {
    //水平翻转
    int temp = 0;
    for(int i=0; i < A.length;i++){
        for(int j = 0;j <= A[0].length - 1 - j;j++){

            //水平反转
            temp = A[i][j];
            A[i][j] = A[i][A[0].length - 1 - j];
            A[i][A[0].length - 1 - j] = temp;

            //取反
            A[i][j] = A[i][j] == 0?1:0;
            A[i][A[0].length - 1 - j] = A[i][A[0].length - 1 - j] == 0?1:0;
        }
    }

    return A;

}
```