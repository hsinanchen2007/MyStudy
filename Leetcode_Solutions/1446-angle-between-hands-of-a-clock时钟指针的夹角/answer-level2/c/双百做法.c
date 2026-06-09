### 解题思路
此处撰写解题思路
以指向十二为起点，分别算出时针和分针，然后再相减，再判断结果与180的大小，最后返回就完事了
### 代码

```c
double angleClock(int hour, int minutes){
    hour = hour * 5 % 60;
    double a = minutes * 6;
    double b = hour * 6 + (double)(minutes % 60)/2;
    double ans = a > b ? a-b : b-a;
    if(ans <= 180)
    return ans;
    else
    return 360-ans;
}
```