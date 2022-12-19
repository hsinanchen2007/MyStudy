```
void lower(int *x, int *y, int d1, int d2){
    int p1 = *x/d1;
    int p2 = *y/d2;
    int min = p1>p2?p2:p1;
    *x = *x-min*d1;
    *y = *y-min*d2;
}

bool isOk(char * command, int x, int y){
    int i=0;
    while(x>=0 && y>=0){
        if(x==0&&y==0)
            return true;
        if(*(command+i)=='U'){
            y--;
        }else{
            x--;
        }
        i++;
    }
    if(x==0&&y==0)
        return true;
    else
        return false;
}

bool robot(char * command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y){
    int nx=x,ny=y;
    int numU=0,numR=0;
    for(int i=0; i<strlen(command); i++){
        if(*(command+i)=='U'){
            numU++;
        }else{
            numR++;
        }
    }
    lower(&nx,&ny,numR,numU);
    if(!isOk(command,nx,ny))
        return false;
    
    for(int i=0; i<obstaclesSize; i++){
        if(obstacles[i][0]>x||obstacles[i][1]>y)
            continue;
        nx=obstacles[i][0];
        ny=obstacles[i][1];
        lower(&nx,&ny,numR,numU);
        if(isOk(command,nx,ny))
            return false;
    }
    
    return true;
}
```
