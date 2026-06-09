typedef enum {
    NULL_SATE,
    COVER_STATE,
    COVER_PASS_STATE
}CalcState;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *CreatInterval(int left, int right)
{
    int *returnPtr = (int *)malloc(sizeof(int) * 2);
    
    if (returnPtr == NULL){
        return NULL;
    }
    returnPtr[0] = left;
    returnPtr[1] = right;
    return returnPtr;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    
    int i;
    int **returnPtr;
    int state;
    int coverLeft;
    int coverRight;
    
    
    (*returnSize) = 0;
    (*returnColumnSizes) = NULL;
    
    returnPtr = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
    if (returnPtr == NULL) {
        (*returnSize) = 0;
        (*returnColumnSizes) = NULL;
        return NULL;
    }
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (intervalsSize + 1));
    if ((*returnColumnSizes) == NULL) {
        (*returnSize) = 0;
        (*returnColumnSizes) = NULL;
        free(returnPtr);
        return NULL;
    }
    
    state = NULL_SATE;    
    for (i = 0; i < intervalsSize; i++)
    {
        if (state == NULL_SATE) {
            if (intervals[i][1] < newInterval[0]) {
                returnPtr[(*returnSize)] = CreatInterval(intervals[i][0], intervals[i][1]);
                (*returnSize)++;
                continue;
            }
            
            if (intervals[i][0] > newInterval[1])
            {
                returnPtr[(*returnSize)] = CreatInterval(newInterval[0], newInterval[1]);
                (*returnSize)++;
                returnPtr[(*returnSize)] = CreatInterval(intervals[i][0], intervals[i][1]);
                (*returnSize)++;
                state = COVER_PASS_STATE;
                continue;
            }
            state = COVER_STATE;
            coverLeft = ((intervals[i][0] < newInterval[0]) ? intervals[i][0] : newInterval[0]);
            coverRight = ((intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1]);
        }
        else if (state == COVER_STATE)
        {
            if (coverRight < intervals[i][0]) {
                returnPtr[(*returnSize)] = CreatInterval(coverLeft, coverRight);
                (*returnSize)++;
                returnPtr[(*returnSize)] = CreatInterval(intervals[i][0], intervals[i][1]);
                (*returnSize)++;
                state = COVER_PASS_STATE;
            }
            else {
                coverRight = ((intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1]);
            }                
        }
        else
        {
            returnPtr[(*returnSize)] = CreatInterval(intervals[i][0], intervals[i][1]);
            (*returnSize)++;
        }
    }
    
    if (state == NULL_SATE) {
        returnPtr[(*returnSize)] = CreatInterval(newInterval[0], newInterval[1]);
        (*returnSize)++;
    }
    else if (state == COVER_STATE)
    {
        returnPtr[(*returnSize)] = CreatInterval(coverLeft, coverRight);
        (*returnSize)++;
    }
    
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
        
    return returnPtr;
}

