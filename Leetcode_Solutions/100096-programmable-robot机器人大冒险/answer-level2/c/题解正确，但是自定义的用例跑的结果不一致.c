为什么题解正确，下面用例结果不一致
```
"URRURRRRRUUUUURRURUURURURUURURUURURUUUUURRRRRUURUURUUUUURRRRRUUUUURUUUURUUUUURUUUUURUUUUU"
[[12,22],[44,88]]
33
55
```

代码如下：
```
// 判断是否经过x,y点
bool isPassPoint(int *tarX, int *tarY, int cmdLen, int x, int y)
{
    //printf("calc is pass point:[%d,%d], cmdlen=%d\n", x, y, cmdLen);
	int cycleTarX = tarX[cmdLen];
	int cycleTarY = tarY[cmdLen];
    
    //printf("cycleTar:[%d,%d]\n", cycleTarX, cycleTarY);
	
	int needCycleX = x/cycleTarX;
	int needCycleY = y/cycleTarY;
    
    int tmpX = x%cycleTarX;
	int tmpY = y%cycleTarY;
    
    //printf("tmp:[%d,%d]\n", tmpX, tmpY);
    
    if ((tmpX != 0) && (tmpY != 0) && (needCycleX != needCycleY)) {
        return false;
    }
    
    int minNeedCycle = (needCycleX < needCycleY) ? needCycleX : needCycleY;
    
    //printf("need cycle:%d-%d->%d\n", needCycleX, needCycleY, minNeedCycle);
    
    tmpX = x- minNeedCycle * cycleTarX;
	tmpY = y- minNeedCycle * cycleTarY;
    
    //printf("tartmp:[%d,%d]\n", tmpX, tmpY);
	
	int start = (tmpX > tmpY) ? tmpX: tmpY;
	
	for (int i = start;i < cmdLen + 1; i++) {
		if ((tarX[i] == tmpX)&&(tarY[i] == tmpY)){
			return true;
		}
		
		if ((tarX[i] > tmpX)||(tarY[i] > tmpY)) {
			return false;
		}
	}
	
	return false;
}

bool robot(char * command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y)
{
	if (command == NULL || strlen(command) == 0) { 
		return  false;
	}
	
	
	
	int cmdLen = strlen(command);
	int *tarX = (int *)malloc((cmdLen + 1) * sizeof(int));
	int *tarY = (int *)malloc((cmdLen + 1) * sizeof(int));
	
	// 起点
	tarX[0] = 0;
	tarY[0] = 0;
	for (int i = 0; i < cmdLen; i++) {
		// U: 向y轴正方向移动一格
		// R: 向x轴正方向移动一格。
		if (command[i] == 'U') {
			tarX[i + 1] = tarX[i];
			tarY[i + 1] = tarY[i] + 1;	
		} else {
			tarX[i + 1] = tarX[i] + 1;
			tarY[i + 1] = tarY[i];	
		} 
        
        //printf("'%c'[%d,%d]\n", command[i], tarX[i + 1], tarY[i + 1]);
	}
	

	
	for (int j = 0; j < obstaclesSize; j++) {
        if ((obstacles[j][0] > x) || (obstacles[j][1] > y)) {
            continue;
        }
		if (isPassPoint(tarX, tarY, cmdLen, obstacles[j][0], obstacles[j][1])) {
			return false;
		}
	}
	
	return isPassPoint(tarX, tarY, cmdLen, x, y);
}
```

