#define VERTICES 2000

void initial(int *parent, int MSize)
{
    int i;
    for(i = 0; i < MSize; ++i) {
        parent[i] = -1;        
    }
}

int findRoot(int x, int *parent)
{
    int xRoot = x;
    while (parent[xRoot] != -1) {
        xRoot = parent[xRoot];
    }
    return xRoot;
}

int unionSet(int x, int y, int *parent, int *rank)
{
    int xRoot = findRoot(x, parent);
    int yRoot = findRoot(y, parent);

    if (xRoot == yRoot) {
        return 0;
    }

    if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else if(rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else {
        parent[xRoot] = yRoot;
        rank[yRoot]++;
    }
    return 1;
}

void pritfgrid(char **grid, int gridSize, int* gridColSize)
{
	int i, j;
	for (i = 0; i < gridSize; ++i) {
		for (j = 0; j < *gridColSize; ++j) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}


int numIslands(char** grid, int gridSize, int* gridColSize)
{
	int i, j;
	int MSize = 0;
	int count = 0;
	int paretS = 0;
    int parent[VERTICES] = { 0 };
    int rank[VERTICES] = { 0 };
	MSize = gridSize * (*gridColSize);
	initial(parent, MSize);
    if (MSize == 0) {
        return 0;
    } 

	for (i = 0; i < (gridSize); ++i) {
		for (j = 0; j < ((*gridColSize)); ++j) {
			if (grid[i][j] == '1') {
				count++;
				paretS = i * (*gridColSize) + j;				
				if ((i + 1) < gridSize) {
					if (grid[i + 1][j] == '1') {
						if (unionSet(paretS, paretS + *gridColSize, parent, rank) == 1) {
							count--;
						}
					}
				}

				if ((j+1) < (*gridColSize)) {
					if (grid[i][j + 1] == '1') {
						if (unionSet(paretS, paretS + 1, parent, rank) == 1) {
							count--;
						}
					}
				}

			}
		}
	}
	return count;
}

