```
class Solution {
    public int mySqrt(int x) {
        if(x==0)  return 0;
        if(x==1||x==2||x==3) return 1;
        int left=2;
        int right=46340;
        int res=0;
        while (left<=right){
            int mid=(left+right)/2;
            int mid2=mid*mid;
            if(mid2<=x) {
                res=mid;
                left=mid+1;
            }
            else {
                res=mid-1;
                right=mid-1;
            }
        }
        return res;
    }
}
```
