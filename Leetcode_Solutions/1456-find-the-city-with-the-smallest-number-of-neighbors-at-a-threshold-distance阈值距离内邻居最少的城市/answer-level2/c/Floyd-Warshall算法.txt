### 解题思路
先用Floyd-Warshall算法处理，然后再按照顶点扫就行了。
### 代码

```c
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold){
    int map[101][101];
    int i,j,k;
    for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
            if(i!=j) map[i][j]=0x7ffffff;
            else map[i][j]=0;
        }
    }
    for(i=0;i<edgesSize;i++){
        int f=edges[i][0],t=edges[i][1],d=edges[i][2];
        map[f][t]=d;
        map[t][f]=d;
    }
    for(k = 0; k < n; k++){
	    for(i = 0; i < n; i++){
		    for(j = 0; j < n; j++){
			    if(map[i][k] < 0x7ffffff && map[k][j] < 0x7ffffff && map[i][j] > map[i][k] + map[k][j])
				    map[i][j] = map[i][k] + map[k][j];
		    }
	    }
    }
    int min=0x7ffffff,id;
    for(i = 0; i < n; i++){
        int count=0;
        for(j = 0; j < n; j++){
            if(i!=j&&map[i][j]<=distanceThreshold) count++;
        }
        if(min>=count){
            min=count;
            id=i;
        }
    }
    return id;
}
```