        void swap(int* a, int* b)
        {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }
        bool isValid(int** retArr, int* returnSize, int* arr, int numsSize)
        {
            int i;
            int j;
            for (i = 0; i < *returnSize; i++) {
                for (j = 0; j < numsSize; j++) {
                    if (retArr[i][j] != arr[j]) {
                        break;
                    }
                    if (retArr[i][j] == arr[j] && j == numsSize - 1) {
                        return false;//表示在其中
                    }
                }
            }
            return true;
        }
        void backTrack(int* nums, int numsSize, int begin, int** retArr, int* returnSize, int* returnColumnSizes)
        {
            int i;
            if (begin == numsSize - 1 && isValid(retArr, returnSize, nums, numsSize)) {
                retArr[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
                returnColumnSizes[*returnSize] = numsSize;
                for (i = 0; i < numsSize; i++) {
                    retArr[*returnSize][i] = nums[i];
                }
                (*returnSize)++;
            } else {
                for (i = begin; i < numsSize; i++) {
                    swap(&nums[i], &nums[begin]);
                    backTrack(nums, numsSize, begin + 1, retArr, returnSize, returnColumnSizes);
                    swap(&nums[i], &nums[begin]);
                }
            }
        } 
        int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
            int MAX = 50000;
            int** retArr = (int**)malloc(sizeof(int*) * MAX);
            *returnSize = 0;
            returnColumnSizes[0] = (int*)malloc(sizeof(int) * MAX);
            backTrack(nums, numsSize, 0, retArr, returnSize, returnColumnSizes[0]);
        
            return retArr;
        }