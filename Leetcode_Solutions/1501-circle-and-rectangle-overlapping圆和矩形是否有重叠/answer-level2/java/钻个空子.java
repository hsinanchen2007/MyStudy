class Solution
{
    public boolean checkOverlap(int radius,int x_center,int y_center,int x1,int y1,int x2,int y2)
    {
        int a1=(x2+x1)/2,b1=(y2+y1)/2;
        double dd=Math.sqrt((x_center-a1)*(x_center-a1)+(y_center-b1)*(y_center-b1));
        double len=Math.sqrt((x1-a1)*(x1-a1)+(y1-b1)*(y1-b1));
        double rr=(double)radius;
        return len+rr>=dd;
    }
}