官方题解看不懂，自己写的倒是可以出结果，就是时间和内存比较差。
我是逐个遍历，如果当前元素为1， 那么先从该节点按行遍历，记下连续1的个数；然后再下一行，每一行都会取最小连续1的个数。
最后行数乘以列数，就是当前节点矩阵的最大面积。
最后对所有取出的结果取最大值


    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        int C = matrix.length, R = matrix[0].length;
        int max = 0, count, ret = 0;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                count = 0;
                max = 0;
                if (matrix[i][j] == '1') {
                    count++;
                    int cur = j+1;
                    while (cur < R && matrix[i][cur] == '1') {
                        count++;
                        cur++;
                    }
                    max = Math.max(max, count);
                    int i2 = i+1;
                    while (i2 < C) {
                        int cur2 = j;
                        int count1 = 0;
                        while (cur2 < cur && matrix[i2][cur2] == '1') {
                            count1++;
                            cur2++;
                        }
                        count = Math.min(count1, count);
                        max = Math.max(max, (i2-i+1)*count);
                        i2++;
                    }
                }
                ret = Math.max(ret, max);
            }
        }
        return ret;
    }