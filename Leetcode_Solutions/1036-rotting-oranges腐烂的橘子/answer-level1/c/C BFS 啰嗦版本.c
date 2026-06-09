```
typedef struct{
  int row;
  int col;
}Grid;

Grid queue[101];
Grid *head;
Grid *tail;
int count;

void initQueue()
{
  head = NULL;
  tail = NULL;
  count = 0;
}

bool empty()
{
  return count == 0;
}

void enQueue(int row, int col)
{
  Grid grid;
  grid.row = row;
  grid.col = col;
  
  if(empty())
  {
    head = queue;
    tail = queue;
  }
  else tail++;
  
  *tail = grid;
  count++;
}

Grid deQueue()
{
  Grid grid = *head;
  head++;
  count--;
  return grid;
}

int getCnt()
{
  return count;
}

int around[4][2] = {
  {1, 0},
  {-1, 0},
  {0, -1},
  {0, 1},
};

int orangesRotting(int** grid, int gridSize, int* gridColSize){
  
  initQueue();
  
  int orangeCnt = 0;
  int rottenCnt = 0;
  int min = -1;
  
  for(int row = 0; row < gridSize; row++)
  {
    for(int col = 0; col < *gridColSize; col++)
    {
      if(grid[row][col])
      {
        orangeCnt++;
        
        if(grid[row][col] == 2)
        {
          rottenCnt++;
          enQueue(row, col);
        }
      }
    }
  }
  
  if(orangeCnt == 0)  return 0;   // no orange, just return 0
  if(empty())         return min; // no rotten orange, return -1
  
  while(!empty())
  {
    int cnt = getCnt();
    min++;
    
    while(cnt--)
    {
      Grid rottenOrange = deQueue();
      
      for(int i = 0; i < 4; i++)
      {
        int newRow = rottenOrange.row + around[i][0];
        int newCol = rottenOrange.col + around[i][1];
        
        if(newRow >= 0 && newRow < gridSize && newCol >= 0 && newCol < *gridColSize && grid[newRow][newCol] == 1)
        {
          grid[newRow][newCol] = 2;
          rottenCnt++;
          enQueue(newRow, newCol);
        }
      }
    }
  }
  
  if(rottenCnt == orangeCnt) return min;  // return min if all oranges turned rotten
  else return -1; // there is at least one orange won't be rotten
}
```
