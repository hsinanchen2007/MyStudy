以N=12为例，漂亮数组为[1,9,5,3,11,7,2,10,6,4,12,8] = 左边数组[1,9,5,3,11,7] append 右边数组[2,10,6,4,12,8]
(左数组+1)/2 = 右数组/2 = [1,5,3,2,6,4]
所以N=12的解可以根据N=6的解就可以算出来

N=6的漂亮数组[1,5,3,2,6,4] = 左边数组[1,5,3] append 右边数组[2,6,4]
(左数组+1)/2 = 右数组/2 = [1,3,2]
所以N=6的解可以根据N=3的解就可以算出来

N=3的漂亮数组[1,3,2] = 左边数组[1,3] append 右边数组[2]
(左数组+1)/2 = [1,2]
右数组/2 = [1]
所以N=3的左数组可以根据N=2的解算，右数据可以根据N=1的解算

N=2的漂亮数组[1,2] = 左边数组[1] append 右边数组[2]
(左数组+1)/2 = [1]
右数组/2 = [1]
所以N=2的解可以根据N=1的解算出来

过程中可以发现很多数组都需要重新计算，所以可以把过程数据存起来，提高效率

第一版代码：（16 ms，16.8 MB）

    int* GetBeautifulArray(int num, int* size)
    {
        int* outArray = NULL;
        int* leftArray = NULL;
        int* rightArray = NULL;
        int leftSize = 0;
        int rightSize = 0;
        int i;

        if (num == 1) {
            outArray = (int *)malloc(sizeof(int));
            outArray[0] = 1;
            *size = 1;
            return outArray;
        }

        leftArray = GetBeautifulArray((num + 1) / 2, &leftSize);
        rightArray = GetBeautifulArray(num / 2, &rightSize);
        *size = leftSize + rightSize;
        outArray = (int *)malloc(sizeof(int) * (*size));
        for (i = 0; i < leftSize; i++) {
            outArray[i] = leftArray[i] * 2 - 1;
        }
        for (i = 0; i < rightSize; i++) {
            outArray[i + leftSize] = rightArray[i] * 2;
        }
        free(leftArray);
        free(rightArray);
        return outArray;
    }


    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* beautifulArray(int N, int* returnSize)
    {
        return GetBeautifulArray(N, returnSize);
    }


第二版代码： （8 ms， 8.2 MB）

    int* GetBeautifulArray(int num, int** saveArray, int* size)
    {
        int* outArray = NULL;
        int* leftArray = NULL;
        int* rightArray = NULL;
        int leftSize = 0;
        int rightSize = 0;
        int i;

        if (saveArray[num] != NULL) {
            *size = num;
            return saveArray[num];
        }

        if (num == 1) {
            outArray = (int *)malloc(sizeof(int));
            outArray[0] = 1;
            *size = 1;
            saveArray[num] = outArray;
            return outArray;
        }

        leftArray = GetBeautifulArray((num + 1) / 2, saveArray, &leftSize);
        rightArray = GetBeautifulArray(num / 2, saveArray, &rightSize);

        *size = leftSize + rightSize;
        outArray = (int *)malloc(sizeof(int) * (*size));
        for (i = 0; i < leftSize; i++) {
            outArray[i] = leftArray[i] * 2 - 1;
        }
        for (i = 0; i < rightSize; i++) {
            outArray[i + leftSize] = rightArray[i] * 2;
        }

        saveArray[num] = outArray;

        return outArray;
    }


    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* beautifulArray(int N, int* returnSize)
    {
        int* outArray = NULL;
        int i;
        int** saveArray = (int **)malloc(sizeof(int *) * (N + 1));

        (void)memset(saveArray, 0, sizeof(int *) * (N + 1));
        outArray = GetBeautifulArray(N, saveArray, returnSize);
        for (i = 0; i < N; i++) {
            if (saveArray[i] != NULL) {
                free(saveArray[i]);
            }
        }
        free(saveArray);
        return outArray;
    }