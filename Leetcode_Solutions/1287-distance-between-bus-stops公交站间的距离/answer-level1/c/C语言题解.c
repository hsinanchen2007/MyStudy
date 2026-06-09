思路就是分两边遍历，到头后从另一侧继续开始，最后比较哪一条路会更小
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int left = 0,right = 0;
    int rightDes = destination - start;
    if(rightDes<0)
        rightDes += distanceSize;
    int leftDes = distanceSize - rightDes;
    int b1=start,b2=start;
    for(int i = 0;i<leftDes;i++)
    {
        if(b1==0)
            b1 = distanceSize;
        left+=distance[b1-1];
        b1--;
    }
    for(int i = 0;i<rightDes;i++)
    {
        right+=distance[b2++];
        if(b2==distanceSize)
            b2 = 0;
    }
    //printf("left is %d,right is %d\n",left,right);
    
    if(left<right)
        return left;
    else
        return right;
}