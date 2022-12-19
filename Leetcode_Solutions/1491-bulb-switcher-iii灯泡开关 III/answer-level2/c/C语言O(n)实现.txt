仔细读题后可以发现若点亮第`k`个灯全部灯变蓝，则第`1`至第`k-1`个灯都已经被点亮，即`1`至`k-1`都已经在数组中出现过。因此可以将每次出现的数字累加求和，与等差数列`1、2、3...k`的数列和对比，若和相等，即出现一次全部灯点亮。

```c
int numTimesAllBlue(int* light, int lightSize){
    int i;
    int sum1 = 0;
    int sum2 = 0;
    int cnt = 0;
    for(i=0;i<lightSize;i++){
        sum1+=i+1;
        sum2+=light[i];
        if(sum1==sum2)
            cnt++;
    }
    return cnt;
}
```
