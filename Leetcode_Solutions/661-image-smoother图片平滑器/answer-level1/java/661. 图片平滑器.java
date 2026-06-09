/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/28
 *
 * 解题思路1: 把情况都列输出 咋想咋做
![93CBF892103FD37895EA8D77A955E132.png](https://pic.leetcode-cn.com/58066c7a4959a0880392144c10f473fba7239bfb54d2566b35b7ecfc97e8e86f-93CBF892103FD37895EA8D77A955E132.png)
 *
 * 解题思路2: 暴力破解：左、右、正上、正下、左上、左下、右上、右下，看是否有这个元素，有则加进去，最后求平均 边界判定
 *
 */
```
public int[][] imageSmoother(int[][] M) {

    if(M.length == 1 && M[0].length == 1){
        return M;
    }

    int[][] M_r = new int[M.length][M[0].length];
    for(int i = 0;i < M.length;i++){
        for(int j = 0; j < M[i].length;j++){
            int sum = M[i][j];
            int num = 1;

            if(M.length == 1){
                if(j == 0){ // M
                    M_r[i][j] = (M[i][j] + M[i][j+1])/2;
                }else if(j == M[i].length - 1){ //O
                    M_r[i][j] = (M[i][j] + M[i][j-1])/2;
                }else { //N
                    M_r[i][j] = (M[i][j] + M[i][j-1] + M[i][j+1])/3;

                }

            }else if(M[i].length == 1){
                if(i == 0){ //J
                    M_r[i][j] = (M[i][j] + M[i+1][j])/2;
                }else if(i == M.length - 1){ //L
                    M_r[i][j] = (M[i][j] + M[i-1][j])/2;
                }else { //K
                    M_r[i][j] = (M[i][j] + M[i-1][j] + M[i+1][j])/3;
                }
            }else {
                if(i == 0){
                    if(j == 0){//A
                        M_r[i][j] = (M[i][j] + M[i + 1][j] + M[i][j + 1] + M[i + 1][j + 1])/4;
                    }else if(j == M[i].length - 1){ //C
                        M_r[i][j] = (M[i][j] + M[i + 1][j] + M[i][j - 1] + M[i + 1][j - 1])/4;
                    }else {//B
                        M_r[i][j] = (M[i][j] + M[i][j - 1] + M[i][j + 1] + M[i + 1][j - 1] + M[i + 1][j] + M[i + 1][j + 1])/6;
                    }
                }else if(i == M.length - 1){
                    if(j == 0){//E
                        M_r[i][j] = (M[i][j] + M[i - 1][j] + M[i][j + 1] + M[i - 1][j + 1])/4;
                    }else if(j == M[i].length - 1){ //G
                        M_r[i][j] = (M[i][j] + M[i - 1][j] + M[i][j - 1] + M[i - 1][j - 1])/4;
                    }else {//F
                        M_r[i][j] = (M[i][j] + M[i][j - 1] + M[i][j + 1] + M[i - 1][j - 1] + M[i - 1][j] + M[i - 1][j + 1])/6;
                    }
                }else {
                    if(j == 0){//H
                        M_r[i][j] = (M[i][j] + M[i + 1][j] + M[i - 1][j] + M[i - 1][j + 1] + M[i][j + 1] + M[i + 1][j + 1])/6;
                    }else if(j == M[i].length - 1){ //I
                        M_r[i][j] = (M[i][j] + M[i + 1][j] + M[i - 1][j] + M[i - 1][j - 1] + M[i][j - 1] + M[i + 1][j - 1])/6;
                    }else {//D
                        M_r[i][j] = (M[i][j] + M[i + 1][j] + M[i - 1][j] + M[i - 1][j - 1] + M[i][j - 1] + M[i + 1][j - 1] + M[i - 1][j + 1] + M[i][j + 1] + M[i + 1][j + 1])/9;
                    }
                }
            }
        }
    }
    return M_r;
}


public int[][] imageSmoother2(int[][] M) {
    int[][] M_r = new int[M.length][M[0].length];
    int size_1 = M.length;
    for(int i = 0;i<size_1;i++)
    {
        for(int j = 0;j < M[i].length;j++)
        {
            int temp = 0;
            int count = 1;
            temp += M[i][j];
            if(i-1 >= 0)
            {
                temp += M[i-1][j];
                count++;
            }
            if(i+1 < size_1)
            {
                temp += M[i+1][j];
                count++;
            }
            if(j-1 >= 0)
            {
                temp += M[i][j-1];
                count++;
            }
            if(j+1 < M[i].length)
            {
                temp += M[i][j+1];
                count++;
            }
            if(i-1 >= 0 && j-1 >= 0)
            {
                temp += M[i-1][j-1];
                count++;
            }
            if(i-1 >= 0 && j+1 < M[i].length)
            {
                temp += M[i-1][j+1];
                count++;
            }
            if(i+1 < size_1 && j-1 >= 0)
            {
                temp += M[i+1][j-1];
                count++;
            }
            if(i+1 < size_1 && j+1 < M[i].length)
            {
                temp += M[i+1][j+1];
                count++;
            }
            M_r[i][j]=temp/count;
        }
    }
    return M_r;
}
```