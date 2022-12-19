// 因为C语言没有queue等，所以只能用struct和双指针来实现一个类似的队列功能了
typedef struct {
    int row;
    int column;
} node;

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize == 0){
        return 0;
    }

    node* queue = (node*)malloc(gridSize*(*gridColSize)* sizeof(node));
    
    int num = 0;
    int head =0; //queue的游标，用来判断现在遍历到了那个值
    int tail = 0; //queue的游标，用来判断现在添加到了那个值
    int queueSize =0 ;  //queue的容量大小，用于遍历是否empty判断
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j] == '1'){
                num++;
                queue[tail].row = i;
                queue[tail].column = j;
                tail++;
                queueSize++;
                while(queueSize != 0){
                    grid[queue[head].row][queue[head].column] = '0';
                    queueSize--;
                    if(queue[head].row -1>=0 && grid[queue[head].row -1][queue[head].column] == '1'){
                        queue[tail].row = queue[head].row -1;
                        queue[tail].column = queue[head].column;
                        grid[queue[head].row -1][queue[head].column] = '0'; //防止重复遍历插入queue，导致越界
                        tail++;
                        queueSize++;
                    }
                    if(queue[head].row +1 < gridSize && grid[queue[head].row + 1][queue[head].column] == '1'){
                        queue[tail].row = queue[head].row  + 1;
                        queue[tail].column = queue[head].column;
                        grid[queue[head].row + 1][queue[head].column] = '0';
                        tail++;
                        queueSize++;
                    }
                    if(queue[head].column -1>=0 && grid[queue[head].row][queue[head].column -1] == '1'){
                        queue[tail].row = queue[head].row;
                        queue[tail].column = queue[head].column - 1;
                        grid[queue[head].row][queue[head].column -1] = '0';
                        tail++;
                        queueSize++;
                    }
                    if(queue[head].column +1 < *gridColSize && grid[queue[head].row ][queue[head].column+1] == '1'){
                        queue[tail].row = queue[head].row ;
                        queue[tail].column = queue[head].column + 1;
                        grid[queue[head].row ][queue[head].column+1] = '0';
                        tail++;
                        queueSize++;
                    }
                    head++;
                }

            }
        }
    }
    free(queue);
    return num;
}