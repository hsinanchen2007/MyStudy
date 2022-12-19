
```
int climbStairs(int n){
    int floor[1000];
    int j;
    floor[1] = 1;
    floor[2] = 2;
    for (j=3; j<=n; j++) {
        floor[j] = floor[j-1] + floor[j-2];
    }
   return floor[n];
}

```

