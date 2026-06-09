#define MIN(x, y) ((x) < (y) ? (x) : (y))

int CalMinNum(int** triangle, int x, int y);

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int minNum = 0x0FFFFFFF;
    int i,j;
    
    for (i = 0; i < triangleSize; i++) {
        for (j = 0; j < i + 1; j++) {
            triangle[i][j] = CalMinNum(triangle, i, j);   
            if ((i == triangleSize - 1) && (triangle[i][j] < minNum)) {
                minNum = triangle[i][j];
            }
        }
        
    }
    
    return minNum;
}

int CalMinNum(int** triangle, int x, int y){
    int minNum = 0;
    
    if ((x == 0) && (y == 0)){
        minNum = triangle[x][y];
    }
    else if (y == 0) {
        minNum = triangle[x - 1][y] + triangle[x][y];
    }
    else if (x == y) {
        minNum = triangle[x - 1][y - 1] + triangle[x][y];
    }
    else {
        minNum = triangle[x][y] + MIN(triangle[x - 1][y - 1], triangle[x - 1][y]);
    }
    
    return minNum;
}

