class Solution 
{
    public boolean carPooling(int[][] trips, int capacity) 
    {
        int count=1;
        int num=0;
        for(;count<=1000;count++)
        {
            for(int k=0;k<trips.length;k++)//k站的上下车情况；
            {
                if(trips[k][2]==count)//如果有人下车；
                    num-=trips[k][0];
                if(trips[k][1]==count)//如果有人上车;
                {
                    num+=trips[k][0];
                }
            }
             if(num>capacity)//本站是否超载；
                return false;
        }
        return true;
    }
}