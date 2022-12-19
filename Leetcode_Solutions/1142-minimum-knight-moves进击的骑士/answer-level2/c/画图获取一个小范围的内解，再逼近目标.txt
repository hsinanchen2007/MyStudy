C语言 用时 4ms，6.7MB
画图获取一个小范围的内解（如5格时最小步数）；然后根据x和y的大小，一步步逼近目标，根据前面获取的解，获取最后需要走几步，完成

int arr[6][6] = {0, 3, 2, 3, 2, 3, 
                 3, 2, 1, 2, 3, 4,
                 2,1,4,3,2,3,
                 3,2,3,2,3,4,
                 2,3,2,3,4,3,
                 3,4,3,4,3,4};

int minKnightMoves(int x, int y)
{
    x = abs(x);
    y = abs(y);
    int num = 0;
    while (x > 5 || y >5) {
        if (x > y) {
            x -= 2;
            y = y < 2 ? y+1 : y-1;
        } else {
            x = x < 2 ? x+1 : x-1;
            y-= 2;
        }
        num++;
    }

    return arr[x][y] + num;

}


