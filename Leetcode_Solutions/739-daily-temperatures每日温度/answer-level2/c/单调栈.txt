int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* iRtn = (int*)malloc(TSize*sizeof(int));
    *returnSize = TSize;
    int* iStack = (int*)malloc(TSize*sizeof(int));
    int  iStackSize = 0;
    for(int i=TSize-1;i>=0;i--)
    {
        if(iStackSize==0)
        {
            iRtn[i] = 0;
            iStack[iStackSize++] = i;
        }
        else
        {
            while((iStackSize>0)&&(T[i]>=T[iStack[iStackSize-1]]))
            {
                iStackSize--;
            }
            if(iStackSize==0)
            {
                iStack[iStackSize++] = i;
                iRtn[i] = 0;
            }
            else
            {
                iRtn[i] = iStack[iStackSize-1] - i;
                iStack[iStackSize++] = i;
            }
        } 
    }
    free(iStack);
    return iRtn;
}