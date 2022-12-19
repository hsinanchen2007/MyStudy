C语言BFS+DFS


//https://leetcode-cn.com/problems/number-of-islands/submissions/

#define MAX_X_Y 1000

typedef struct xy_piont
{
	int x;
	int y;
}point;

int x_max;
int y_max;
int queue_len = 0;
int queue_head = 0;
int queue_tail = 0;
point *queue_base[MAX_X_Y];

void enqueue(point *p)
{
	if (queue_len >= MAX_X_Y) {
		printf("out of stack %d\n", queue_len);
		return;
	}
	queue_len ++;
	queue_base[queue_tail] = p;
	queue_tail ++;
	queue_tail = queue_tail % MAX_X_Y;
}

point * outqueue(void)
{
	point *tmp = NULL;
	if (queue_len <= 0) {
		printf("stack %d is empty\n", queue_len);
		return NULL;
	}
	queue_len --;
	tmp = queue_base[queue_head];
	queue_head ++;
	queue_head = queue_head % MAX_X_Y;
	return tmp;
}

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void mapTheIsland(char** grid)
{
	point *pop_point = outqueue();
	point *new_point = NULL;
	int x;
	int y;
	int i;
	
	while (pop_point != NULL) {
		if (grid[pop_point->x][pop_point->y] == '1') {
			grid[pop_point->x][pop_point->y] = '2';
		}
		else
			goto goon;

		for (i = 0; i < 4; i++) {
			x = pop_point->x + dir[i][0];
			y = pop_point->y + dir[i][1];
			if ((x < x_max) && (x >= 0) && (y < y_max) && (y >= 0) && (grid[x][y] == '1')) {
				new_point = (point *)malloc(sizeof(point));
				new_point->x = x;
				new_point->y = y;
				enqueue(new_point);
			}
		}
goon:
		free(pop_point);
		pop_point = outqueue();
	}
}

int numIslands_bfs(char** grid, int gridSize, int* gridColSize){
	int x_index;
	int y_index;
	int island_count = 0;
	point *island_start_point = NULL;

	x_max = gridSize;
	if ((x_max == 0) || (grid == NULL)) 
        return 0;
	
	y_max = *gridColSize;
    
	for (x_index = 0; x_index < x_max; x_index ++) {
		for (y_index = 0; y_index < y_max; y_index ++) {
			if (grid[x_index][y_index] == '1') {
				printf("point[%d][%d]==1, in\n", x_index, y_index);
				island_count ++;
				
				island_start_point = (point *)malloc(sizeof(point));
				island_start_point->x = x_index;
				island_start_point->y = y_index;
				
				enqueue(island_start_point);
				
				mapTheIsland(grid);
			}
		}
	}

	return island_count;
}


void island_dfs(char** grid, int x, int y)
{
	int i, new_x, new_y;

	if (grid[x][y] != '1')
		return;

	grid[x][y] = '2';
	
	for (i = 0; i < 4; i++) {
		new_x = x + dir[i][0];
		new_y = y + dir[i][1];
		if ((new_x < x_max) && (new_x >= 0) && 
            (new_y < y_max) && (new_y >= 0) && 
            (grid[new_x][new_y] == '1')) 
		{
			island_dfs(grid, new_x, new_y);
		}
	}
}


int numIslands(char** grid, int gridSize, int* gridColSize){
	int x_index;
	int y_index;
	int island_count = 0;

	x_max = gridSize;
	if ((x_max == 0) || (grid == NULL)) 
        return 0;
	
	y_max = *gridColSize;
    
	for (x_index = 0; x_index < x_max; x_index ++) {
		for (y_index = 0; y_index < y_max; y_index ++) {
			if (grid[x_index][y_index] == '1') {
				island_count ++;
				island_dfs(grid, x_index, y_index);
			}
		}
	}

	return island_count;
}