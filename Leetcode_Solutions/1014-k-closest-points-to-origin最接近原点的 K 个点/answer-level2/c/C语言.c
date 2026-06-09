复用当前内存进行快排即可(436 ms, 35.2 MB)

    int Compare(const void *p1, const void *p2)
    {
        int **point1 = (int **)p1;
        int **point2 = (int **)p2;

        return point1[0][0] * point1[0][0] - point2[0][0] * point2[0][0] + point1[0][1] * point1[0][1] - point2[0][1] * point2[0][1];
    }

    /**
    * Return an array of arrays of size *returnSize.
    * The sizes of the arrays are returned as *returnColumnSizes array.
    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
    */
    int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
        int i;

        qsort(points, pointsSize, sizeof(int *), Compare);

        *returnSize = K < pointsSize ? K : pointsSize;
        *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
        for (i = 0; i < (*returnSize); i++) {
            (*returnColumnSizes)[i] = 2;
        }

        return points;
    }