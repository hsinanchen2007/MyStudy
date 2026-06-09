click here

```
bool valid(int row, int col, int k)
{
    int digiSum = 0;

    while(row)
    {
        digiSum += row % 10;
        row /= 10;
    }

    while(col)
    {
        digiSum += col % 10;
        col /= 10;
    }

    return digiSum <= k;
}

int around[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void dfs(int m, int n, int k, int row, int col, char **record, int *res)
{
    if( (row >= 0 && row < m)   && 
        (col >= 0 && col < n )  && 
        (record[row][col] == 0) &&
        valid(row, col, k)        )
    {
        record[row][col] = 1;

        (*res)++;

        for(int i = 0; i < 4; i++)
        {
            dfs(m, n, k, row + around[i][0], col + around[i][1], record, res);
        }
    }
}

int movingCount(int m, int n, int k){

    // init a record table to record trace
    char **record = malloc(sizeof(char *) * m);

    for(int i = 0; i < m; i++)
    {
        record[i] = malloc(n);
        memset(record[i], 0, n);
    }

    int res = 0;

    dfs(m, n, k, 0, 0, record, &res);

    // release the record table
    for(int i = 0; i < m; i++)
    {
        free(record[i]);
    }

    free(record);

    return res;
}

```
