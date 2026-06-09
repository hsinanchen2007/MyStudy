void dfsuniquePathsIII(int** grid,int iRow,int iCol,int iStart,int jStart,int* pRtn,int* pCount,int iTotalCount)
{
    if(iStart<0 || jStart<0 || iStart>=iRow || jStart>=iCol || grid[iStart][jStart]==-1)
    {
        return;
    }
    if (grid[iStart][jStart]==2)
    {
        if( (*pCount)==iTotalCount)
        {
            (*pRtn)++;
        }
        return;
    }
    if((grid[iStart][jStart] = 0) || (grid[iStart][jStart] = 1))
    {
        (*pCount)++;
        int iTmp = grid[iStart][jStart];
        grid[iStart][jStart] = -1;
        dfsuniquePathsIII(grid,iRow,iCol,iStart,jStart+1,pRtn,pCount,iTotalCount);
        dfsuniquePathsIII(grid,iRow,iCol,iStart,jStart-1,pRtn,pCount,iTotalCount);
        dfsuniquePathsIII(grid,iRow,iCol,iStart+1,jStart,pRtn,pCount,iTotalCount);
        dfsuniquePathsIII(grid,iRow,iCol,iStart-1,jStart,pRtn,pCount,iTotalCount);
        grid[iStart][jStart] = iTmp;
        (*pCount)--;
        
    }
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize){

    int iZeroCount = 0;
    int iRow = gridSize;
    int iCol = *gridColSize;
    int iStart = 0;
    int jStart = 0;
    int iRtn = 0;
    int Count = 0;
    for(int i=0;i<iRow;i++)
    {
        for(int j=0;j<(iCol);j++)
        {
            if(grid[i][j]==0)
            {
                iZeroCount++;
            }
            if(grid[i][j]==1)
            {
                iStart = i;
                jStart = j;
                iZeroCount++;
            }
        }
    }
    dfsuniquePathsIII(grid,iRow,iCol,iStart,jStart,&iRtn,&Count,iZeroCount);
     
    return iRtn;
}
