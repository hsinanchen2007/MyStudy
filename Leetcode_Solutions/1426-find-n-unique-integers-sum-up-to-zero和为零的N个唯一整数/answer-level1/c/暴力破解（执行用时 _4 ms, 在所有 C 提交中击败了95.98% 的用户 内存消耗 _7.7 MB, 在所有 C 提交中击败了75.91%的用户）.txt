解题思路：
1.只要满足n个数相加为0，那就分类两种类型考虑。
2.偶数个数，+-num就满足要求。
3.奇数个数加上0.

解题代码：
    int* sumZero(int n, int* returnSize){
        int i, j, m, k;
        int *p;
        int flag = 0;//偶数
        if (n < 1 || n > 1000) {
            return NULL;
        }
        m = n;
        if (n % 2 != 0) {
            m = n - 1;
            flag = 1;
        }
        p = (int *)malloc(sizeof(int) * n);
        for (i = 0, k = 1; i < m; i++, k++) {
            p[i++] = k;
            p[i] = -k;
        }
        if (1 == flag) {
            p[i] = 0;
        }

        * returnSize = n;
        return p;
    }