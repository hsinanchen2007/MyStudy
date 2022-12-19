思路：
1、排序，将数组对应的索引从小到大让如二维数组；
2、先处理两端；
3、从最小数字开始循环，主要有以下关联关系
    a、dp[i-1] = dp[i+1] = 0  则dp[i] = 1;
    b、dp[i-1]  dp[i+1] 有一端已经赋值则分两种情况
        1) ratings[i-1] != ratings[i]  dp[i] = Max(dp[i-1],dp[i+1])
        2) ratings[i-1]  == ratings[i] dp[i] = dp[i+1] + 1

int candy(int* ratings, int ratingsSize){
    int index[20480][8] = {0};
    int clk[20480] = {0};
    int dp[20480] = {0};
    int sum = 0;

    if (ratingsSize ==1)
        return 1;

    for (int i = 0; i < ratingsSize; i++) {
        index[ratings[i]][clk[ratings[i]]] = i;
        clk[ratings[i]]++;
    }

    for (int m = 0; m < 20480; m++) {
        for (int n = 0; n < clk[m]; n++) {
            if (index[m][n] == 0) {
                if (dp[1] > 0)
                    dp[0] = dp[1] + 1;
                else
                    dp[0] = 1;
            } else if (index[m][n] == (ratingsSize - 1)) {
                if (dp[ratingsSize - 2] > 0) {
                    if (ratings[ratingsSize - 2] == ratings[ratingsSize - 1]) {
                        dp[ratingsSize - 1] = 1;
                    } else
                    dp[ratingsSize - 1] = dp[ratingsSize - 2] + 1;
                } else
                    dp[ratingsSize - 1] = 1;
            } else {
                //左右两边dp均没有赋值
                if (dp[index[m][n] + 1] == 0 && dp[index[m][n] - 1] == 0) {
                    dp[index[m][n]] = 1;
                } else { 
                    if (n > 0 && (ratings[index[m][n]] == ratings[index[m][n] - 1])) { //与左边的数字相等
                        //printf("index: %d\n", index[m][n]);
                        if (index[m][n] < ratingsSize - 1){
                            dp[index[m][n]] = dp[index[m][n] + 1] + 1;
                        } else {
                            dp[index[m][n]] = 1;
                        }
                    } else {
                        if (dp[index[m][n] + 1] > dp[index[m][n] - 1]) {
                            dp[index[m][n]] = dp[index[m][n] + 1] + 1;
                        } else {
                            dp[index[m][n]] = dp[index[m][n] - 1] + 1;
                        }
                    }
                }   
            }  
            sum = sum + dp[index[m][n]];
        }
       
    }
    return sum;
}