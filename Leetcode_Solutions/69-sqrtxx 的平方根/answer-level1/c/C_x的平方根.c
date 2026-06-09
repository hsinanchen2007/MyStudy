### 解题思路
牛顿法

### 代码

```c
int mySqrt(int x){
    if(x<2)
     return x;

    long r = x;
    while(r*r > x) r = (r + x/r) / 2;
    return (int)r;

}
```