### 解题思路
就是从0开始，不断递归向四周找能走的路，一个深度遍历，加上一个走过的flag，防止重复行走，迷路。

### 代码

```c
bool inBoard(int row, int column, int m, int n){
    if(row>-1 && row < m && column > -1 && column < n)  return true;
    return false;
}


bool sumBit(int row, int column, int k){
    int sum = 0;
    while(row){
        sum += (row % 10);
        row = (int)(row / 10);
    }
    while(column){
        sum += (column % 10);
        column = (int)(column / 10);
    }
    return (sum > k)?false:true;
}


int find(int **nums, int row, int column, int count, int k, int m, int n){
    if(inBoard(row-1, column, m, n)){
        if(sumBit(row-1, column, k)){
            if(nums[row-1][column] != 1){
                printf("(%d,%d)\n", row-1, column);
                count++;
                nums[row-1][column] = 1;
                count = find(nums, row-1, column, count, k, m, n);
            }
        }
    }
    if(inBoard(row+1, column, m, n)){
        if(sumBit(row+1, column, k)){
            if(nums[row+1][column] != 1){
                count++;
                nums[row+1][column] = 1;
                count = find(nums, row+1, column, count, k, m, n);
            }
        }
    }
    if(inBoard(row, column-1, m, n)){
        if(sumBit(row, column-1, k)){
            if(nums[row][column-1] != 1){
                count++;
                nums[row][column-1] = 1;
                count = find(nums, row, column-1, count, k, m, n);
            }
        }
    }
    if(inBoard(row, column+1, m, n)){
        if(sumBit(row, column+1, k)){
            if(nums[row][column+1] != 1){
                count++;
                nums[row][column+1] = 1;
                count = find(nums, row, column+1, count, k, m, n);
            }
        }
    }
    
    return count;
}


int movingCount(int m, int n, int k){
    int **nums = (int **)malloc(m*sizeof(int *));
    for(int index = 0; index < m; index++){
        nums[index] = (int *)malloc(n*sizeof(int));
    }

    nums[0][0] = 1;
    return find(nums, 0, 0, 1, k, m, n);
}
```