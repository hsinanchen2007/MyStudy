### 解题思路
三种解法，大佬们解释的都很清楚了，此处仅做C代码写法参考

### 代码
1. 动态规划：
```c
int isRightNum(int num1, int num2, int k){
	int tmp = 0;
	while (num1){
		tmp += num1 % 10;
		num1 /= 10;
	}
	while (num2){
		tmp += num2 % 10;
		num2 /= 10;
	}
	if (tmp <= k) return 1;
	return 0;
}

int movingCount(int m, int n, int k){
	if (k == 0) return 1;

	//m x n二维数组
	//动态规划
	int i, j, res = 0;
	int **arr = (int **)malloc(sizeof(int *)* m);
	for (i = 0; i < m; i++){
		arr[i] = (int *)calloc(n, sizeof(int));
	}
	arr[0][0] = 1;
	for (i = 0, j = 1; j < n; j++){ //第一行
		if (arr[i][j - 1] && isRightNum(i, j, k)) arr[i][j] = 1;
	}
	for (i = 1, j = 0; i < m; i++){ //第一列
		if (arr[i - 1][j] && isRightNum(i, j, k)) arr[i][j] = 1;
	}
	for (i = 1; i < m; i++){ //行
		for (j = 1; j < n; j++){ //列
			if (arr[i - 1][j] || arr[i][j - 1]) 
				if(isRightNum(i, j, k)) arr[i][j] = 1;
		}
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			if (arr[i][j] == 1) {
				res++;
			}
				
		}
	}
	return res;
}
```

2. 深度优先遍历
```c
int isRightNum(int num1, int num2, int k){
	int tmp = 0;
	while (num1){
		tmp += num1 % 10;
		num1 /= 10;
	}
	while (num2){
		tmp += num2 % 10;
		num2 /= 10;
	}
	if (tmp <= k) return 1;
	return 0;
}
int dfs(int i, int j, int k, int m, int n, int * visited){
    if(i < 0 || i == m || j < 0 || j == n || visited[i * n + j] == 1 || !isRightNum(i, j, k)) return 0;
    visited[i * n + j] = 1;
    return dfs(i + 1, j, k, m, n, visited) + dfs(i, j + 1, k, m, n, visited) + 1;
}
int movingCount(int m, int n, int k){
	if (k == 0) return 1;

	int i = 0, j = 0, res = 0, *visited = (int *)calloc(m * n, sizeof(int));
	res = dfs(i, j, k, m, n, visited);
	return res;
}
```

3. 广度优先遍历
```c
typedef struct Postion{
    int i; //横坐标
    int j; //纵坐标
}Pos;

int isRightNum(int num1, int num2, int k){
	int tmp = 0;
	while (num1){
		tmp += num1 % 10;
		num1 /= 10;
	}
	while (num2){
		tmp += num2 % 10;
		num2 /= 10;
	}
	if (tmp <= k) return 1;
	return 0;
}

int movingCount(int m, int n, int k){
	if (k == 0) return 1;

	int i = 0, j = 0, res = 0, top = 0, bottom = 0, *visited = (int *)calloc(m * n, sizeof(int));
	Pos **que = (Pos **)malloc(sizeof(Pos *)* m * n);
	Pos *p = (Pos *)malloc(sizeof(Pos));
	p->i = 0;
	p->j = 0;
	que[top++] = p;
	while (top > bottom){
		Pos *q = que[bottom % (m * n)];
        bottom++;
		i = q->i;
		j = q->j;
		if (i < 0 || i == m || j < 0 || j == n || visited[i * n + j] == 1 || !isRightNum(i, j, k)) continue;
		res++;
		visited[i * n + j] = 1;
		Pos *p1 = (Pos *)malloc(sizeof(Pos));
		p1->i = (i + 1);
		p1->j = j;
		que[top % (m * n)] = p1;
        top++;
		Pos *p2 = (Pos *)malloc(sizeof(Pos));
		p2->i = i;
		p2->j = (j + 1);
		que[top % (m * n)] = p2;
        top++;
	}

	return res;
}

```