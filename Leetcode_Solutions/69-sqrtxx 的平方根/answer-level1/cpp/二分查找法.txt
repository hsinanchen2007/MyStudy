```
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        int ans;
        int i=1,j=x;
        int mid;
        while(i<=j)     //注意，此处是<=
        {
            mid=i+(j-i)/2;
            if(x/mid<mid)
                j=mid-1;    //mid-1
            else if(x/mid>mid)
                i=mid+1;    //mid+1
            else
                break;
        }
        if(i<j)
            return mid;
        else
            return j;
    }
};
```