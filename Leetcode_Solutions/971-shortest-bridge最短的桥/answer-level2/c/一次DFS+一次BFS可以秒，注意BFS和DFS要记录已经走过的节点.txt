struct node{
    int x;
    int y;
}nodes[10005];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int row,col;
int front,rear,trear;
int x,y;
int count;

void firstD(int** A){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(A[i][j]==1){
                x=i;
                y=j;
                return;
            }
        }
    }
    return;
}

void DFS(int** map, int x, int y){
    if(map[x][y]==1){
        map[x][y]=2;
    }
    int i,nx,ny;
    for(i=0;i<4;i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=0&&nx<row&&ny>=0&&ny<col){
            if(map[nx][ny]==1){
                DFS(map, nx, ny);
            }
        }
    }
    return;
}

void BFS(int** A){

    rear = 0;
    int i,j,fx,fy,nx,ny;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(A[i][j]==1){
                nodes[rear].x=i;
                nodes[rear].y=j;
                rear++;
            }
        }
    }

    trear = rear;
    while(front!=rear){
        fx = nodes[front].x;
        fy = nodes[front].y;
        A[fx][fy]=3;
        for(i=0;i<4;i++){
            nx = fx+dx[i];
            ny = fy+dy[i];
            if(nx>=0&&nx<row&&ny>=0&&ny<col){
                if(A[nx][ny]==2){
                    return;
                }
                if(A[nx][ny]==0){
                    A[nx][ny]=4;
                    nodes[rear].x=nx;
                    nodes[rear].y=ny;
                    rear++;
                }
            }
        }
        front++;
        if(front == trear){
            trear = rear;
            count++;
        }
    }
    return;
}

int shortestBridge(int** A, int ASize, int* AColSize){
    row = ASize;
    col = AColSize[0];
    front = rear = trear = count = 0;
    memset(nodes, 0, 10005*sizeof(struct node));
    firstD(A);
    DFS(A, x, y);
    BFS(A);
    return count;
}


![image.png](https://pic.leetcode-cn.com/c9bda0d8e8816376013295b1234067d534d1c17c3ca4dccc4042b0afc897246a-image.png)
