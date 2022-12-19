int maxArea(int* height, int heightSize){
    int i,j;
    int max=0;
    int nowarea=0;
    for (i=0;i<heightSize-1;i++)
        for (j=i+1;j<heightSize;j++)
        {
            nowarea=(j-i)*((height[i]<height[j])?height[i]:height[j]);
            if (nowarea>max)
                max=nowarea;
        }
    return max;
}