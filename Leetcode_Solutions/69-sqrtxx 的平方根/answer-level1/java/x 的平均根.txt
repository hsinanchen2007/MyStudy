二分查找 
- 将区域划分为 [1, mid-1] [mid, x]


```
    public int mySqrt(int x) {
        int l=1, r=x;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(mid <= x/mid) l = mid; 
            else r = mid-1;
        }
        
        return r;
    }
```
