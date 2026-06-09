/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* KRow(int rowIndex)
{
    int* ret, * temp;
    int i;

    ret = (int* )malloc((rowIndex + 1) * sizeof(int));

    if(rowIndex == 0)
    {
        ret[0] = 1;
    }
    else
    {
        temp = KRow(rowIndex - 1);

        ret[0] = ret[rowIndex] = 1;

        for(i = 1; i < rowIndex; i++)
        {
            ret[i] = temp[i-1] + temp[i];
        } 

        free(temp);
    }

    return ret;
}

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;

    return KRow(rowIndex);
}