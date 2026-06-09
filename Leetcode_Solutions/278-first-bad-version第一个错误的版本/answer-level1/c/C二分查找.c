很好理解，找分界点
```
int firstBadVersion(int n) {
    long i=1,j=n,mid;
    while(i<j){
        mid=(i+j)/2;
        if(isBadVersion(mid)){
            j=mid;
        }else{
            i=mid+1;
        }
    }
    return j;
}
```
