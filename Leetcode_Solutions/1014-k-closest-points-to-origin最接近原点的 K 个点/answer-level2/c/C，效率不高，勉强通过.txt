1，新开buffer存取前k个小的元素
2，每次新获取的样点通过二分法在新卡buffer中找到插入位置并插入，最终返回这个新开buffer即可

//二分法查找插入位置
int InsertPoint(int **res, int cur, int len)
{
    int l = 0;
    int r = len - 1;
    int mid;
    int tmp2;
    while (l <= r) {
        mid = (l + r) / 2;
        tmp2 = res[mid][0] * res[mid][0] + res[mid][1] * res[mid][1];
        if (cur == tmp2) {
            return mid;
        } else if (cur < tmp2) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l; 
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    if (pointsSize == 0 || points == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int i, j;
    int col = *pointsColSize;
    int row = pointsSize;
    int **res = (int **)malloc(sizeof(int *) * K);
    int id = 0;
    int insertP;
    int tmp1;
    int tmp2;
    *returnSize = K;
    *returnColumnSizes = (int *)malloc(sizeof(int) * K);
    
    for (i = 0; i < K; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }

    for (i = 0; i < row; i++) {
        if (id == 0) {
            res[id][0] = points[i][0];
            res[id][1] = points[i][1];
            id++;
        } else {
            tmp1 = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            tmp2 = res[id - 1][0] * res[id - 1][0] + res[id - 1][1] * res[id - 1][1];
            if (tmp1 >= tmp2) {
                if (id < K) {  //存储没有满k个，直接放入队尾
                    res[id][0] = points[i][0];
                    res[id][1] = points[i][1];
                    id++;
                } 
            } else {
                insertP = InsertPoint(res, tmp1, id);  //二分法，找出待插入位置
                if (id < K) {  //存储没满K个，插入点之后所有元素后移1，然后插入
                    for (j = id; j > insertP; j--) {
                        res[j][0] = res[j - 1][0];
                        res[j][1] = res[j - 1][1];
                    }
                    id++;
                } else {  //存储满K个，插入点之后不含尾部元素后移1，相当于尾部元素被删除，然后插入
                    for (j = (K - 1); j > insertP; j--) {
                        res[j][0] = res[j - 1][0];
                        res[j][1] = res[j - 1][1];
                    }
                }
                res[insertP][0] = points[i][0];
                res[insertP][1] = points[i][1];
            }
        }        
    }
    return res;
}
![image.png](https://pic.leetcode-cn.com/d7483aa5b3c6553f73e4ee7aaad5a6e9845a4c9148c38cd58f3f473c6f94a644-image.png)
