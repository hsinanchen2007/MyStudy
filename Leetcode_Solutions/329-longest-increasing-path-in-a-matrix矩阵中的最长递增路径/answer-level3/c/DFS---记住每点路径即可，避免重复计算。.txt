struct trace_h {
	int max;
};
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
struct trace_h **trace_lip = NULL;
int longestIncreasingPath_DFS(int** matrix, int x_max, int y_max, int x, int y) {
	int i = 0;
	int max = 0;
	int ret = 0;
	int x_tmp = 0;
	int y_tmp = 0;

	if (trace_lip[x][y].max != -1)
		return trace_lip[x][y].max;

	for (i = 0; i < 4; i++)	{
		x_tmp = x + dir[i][0];
		y_tmp = y + dir[i][1];

		if ((x_tmp < 0) || (x_tmp >= x_max) || (y_tmp < 0) || (y_tmp >= y_max)) {
			continue;
		}

		if (matrix[x][y] <= matrix[x_tmp][y_tmp]) {
			continue;
		}

		ret = longestIncreasingPath_DFS(matrix,x_max,y_max,x_tmp,y_tmp);
		if (ret > max) {
			max = ret;
		}
	}

	max ++;
	trace_lip[x][y].max = max;
	return max;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
	int i = 0;
	int j = 0;
	int x_max = 0;
	int y_max = 0;
	int ret = 0;
	int max = 0;
	int x_tmp = 0;
	int y_tmp = 0;

	if ((matrix == NULL) || (matrixSize == 0) || (*matrixColSize == 0)) {
		return 0;
	}

	x_max = matrixSize;
	y_max = *matrixColSize;
	trace_lip = (struct trace_h **)malloc(x_max * sizeof(struct trace_h *));
	for (i = 0; i < x_max; i++) {
		trace_lip[i] = (struct trace_h *)malloc(y_max * sizeof(struct trace_h));
	}
	for (i = 0; i < x_max; i++) {
		for (j = 0; j < y_max; j++) {
			trace_lip[i][j].max = -1;
		}
	}
	printf("Init ok");
	
	for (i = 0; i < x_max; i++) {
		for (j = 0; j < y_max; j++) {
			if(trace_lip[i][j].max != -1) {
				continue;
			}
						
			ret = longestIncreasingPath_DFS(matrix,x_max,y_max,i,j);
			if (ret > max) {
				max = ret;
			}
		}
	}

	for (i = 0; i < x_max; i++) {
		free(trace_lip[i]);
	}
	free(trace_lip);
	
	return max;
}