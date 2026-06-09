class Solution 
{
public:
    int mySqrt(int x) 
    {//from two sides to inside
        int l = 1, h = x;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;   //prevent digital from pouring out
            //maybe "mid = (l + h) / 2;" is right, but we still choose the first one.
            if(mid == x / mid)
                return mid;
            else if(mid < x / mid)
                l = mid + 1;
            else
                h = mid - 1;
        }     
        //finally, h == l - 1, so return h
        return h;
    }
};