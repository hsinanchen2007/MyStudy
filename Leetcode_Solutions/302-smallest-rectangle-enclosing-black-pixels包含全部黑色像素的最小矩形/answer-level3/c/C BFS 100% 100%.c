int minArea(char** image, int imageSize, int* imageColSize, int x, int y){
    int L = y;
    int R = y;
    int U = x;
    int D = x;
    int Black[10000][2];
    int head = 0;
    int rear = 1;
    int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    Black[0][0] = x;
    Black[0][1] = y;
    int xNext;
    int yNext;
    int S;
    while (head < rear){
        for (int i = 0; i < 4; i++){
            xNext = Black[head][0] + direction[i][0];
            yNext = Black[head][1] + direction[i][1];            
            if (xNext >= 0 && xNext < imageSize && yNext >= 0 && yNext < imageColSize[0]){
                if (image[xNext][yNext] == '1'){
                    Black[rear][0] = xNext;
                    Black[rear][1] = yNext;
                    rear++;
                    image[xNext][yNext] = '2';
                    if (xNext < U){
                        U = xNext;
                    }
                    if (xNext > D){
                        D = xNext;
                    }
                    if (yNext < L){
                        L = yNext;
                    }
                    if (yNext > R){
                        R = yNext;
                    }
                }
            }   

        }
        head++;
    }
    S = (D - U + 1)*(R - L + 1);
    printf("U:%d,D:%d,L:%d,R:%d\n",U,D,L,R);
    return S;
}