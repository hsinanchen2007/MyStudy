### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct stack{
    int (*coordinate)[2];
    int top;
    int size;
}*Stack;

Stack create(){
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->top = 0;
    s->size = 4;
    s->coordinate = (int(*)[2])calloc(s->size * 2, sizeof(int));
    return s;
}

void push(Stack s, int i, int j){
    s->coordinate[s->top][0] = i;
    s->coordinate[s->top ++][1] = j;
    if(s->top == s->size){
        s->size *= 2;
        s->coordinate = (int(*)[2])realloc(s->coordinate, s->size * 2 * sizeof(int));
    }
}

void pop(Stack s, int* i, int* j){
    *i = s->coordinate[--(s->top)][0];
    *j = s->coordinate[s->top][1];
    if(s->top * 4 < s->size){
        s->size /= 2;
        s->coordinate = (int(*)[2])realloc(s->coordinate, s->size * 2 * sizeof(int));
    }
}

bool isempty(Stack s){
    return s->top == 0;
}

void destory(Stack s){
    free(s->coordinate);
    free(s);
}

int dfs(int** grid, int gridSize, int* gridColSize, int row, int column){
    Stack s = create();
    push(s, row, column);
    int area = 0, i, j;
    while(!isempty(s)){
        pop(s, &i, &j);
        if(grid[i][j] == 1){
            area ++;
            grid[i][j] = 0;
        }
        if(j < gridColSize[i] - 1 && grid[i][j + 1] == 1)
            push(s, i, j + 1);
        if(j > 0 && grid[i][j - 1] == 1)
            push(s, i, j - 1);
        if(i < gridSize - 1 && grid[i + 1][j] == 1)
            push(s, i + 1, j);
        if(i > 0 && grid[i - 1][j] == 1)
            push(s, i - 1, j);
    }
    destory(s);
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j, area, maxArea = 0;
    for(i = 0;i < gridSize;i ++)
        for(j = 0;j < gridColSize[i];j ++){
            if(grid[i][j] == 1){
                area = dfs(grid, gridSize, gridColSize, i, j);
                maxArea = (area > maxArea ? area : maxArea);
            }
        }
    return maxArea;
}
```