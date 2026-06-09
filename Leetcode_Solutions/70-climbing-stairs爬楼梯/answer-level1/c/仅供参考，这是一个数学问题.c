```
int climbStairs(int n){
int tri=2;
    long long count=3;
    int i,j;
    if(n<=3)
        return n;
  for(i=0;i<n-3;i++)
  {
      count=count+tri;
      tri=count-tri;
  }
    return count;
}
```