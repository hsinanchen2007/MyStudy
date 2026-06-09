```
class Solution {
    public int mySqrt(int x) {
        if(x<1){
            return 0;
        }
        if(x==1){
            return 1;
        }
        int start = 1;
        int end = x/2+1;
        int mid = 0;
        while(start<end){
            mid = (end+start)/2;
            int temp = x/mid;
            if(mid==temp||(mid<temp&&(mid+1)>(x/(mid+1)))){
                return mid;
            }
            if(temp>mid){
                start = mid;
            }else{
                end=mid;
            }
            
        }
        return mid;
    }
}
```
