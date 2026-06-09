### 解题思路
这个只是好玩，二分法效率更高

### 代码

```c
int mySqrt(int x){
    for(long i = 0;i<=x/2+1;i++)if(i*i>x)return i-1;
    return 1;
}
```