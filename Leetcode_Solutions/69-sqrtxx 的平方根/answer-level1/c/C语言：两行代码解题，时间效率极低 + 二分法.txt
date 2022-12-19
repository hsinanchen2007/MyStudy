抖个机灵：时间都节省在写代码上了
```

int mySqrt(int x){
    for (int i = 0; (long)i * i <= x; i++);
    return i - 1;
}

```
补上二分法
```
int mySqrt(int x){
    int i;
    long low = 0, high = x / 2 + 1, mid = 0;
    while (low <= high){
        mid = (low + high) / 2;
        if (mid * mid > x){
            high = mid - 1;
        }
        if (mid * mid <= x){
            low = mid + 1;
        }     
    }
    return high;
}
```

