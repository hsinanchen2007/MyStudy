int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int i=0;
    int sum=0;
    int a=0,b=0;
    if(!points)
    {
        return 0;
    }  
       for (i;i<pointsSize-1;i++)
    {
        a=abs(points[i][0]-points[i+1][0]);
        b=abs(points[i][1]-points[i+1][1]);
        if (a>=b)
        {   
            sum=sum+a;
        }
       else
        {
            sum=sum+b;
        }
    }
    return sum;
}