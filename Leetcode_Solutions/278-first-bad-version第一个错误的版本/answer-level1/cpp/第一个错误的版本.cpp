```c++
    //二分法
    int firstBadVersion(int n) {
        if(n<=1)return n;
        if(isBadVersion(1))return 1;
        return firstBadVersion(1,n);
    }
    //保证end是坏版本,k是好版本
    int firstBadVersion(long long start, long long end){
        long long k = (start+end)/2;
        if(end-start==1)return end;
        if(isBadVersion(k))return firstBadVersion(start,k);
        else return firstBadVersion(k,end);
    }
```
