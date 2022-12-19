
![爬楼梯2.PNG](https://pic.leetcode-cn.com/a252fd1d7863d99095ae05037046d92dddc589b33e018e6d627fb0da4d34dd5f-%E7%88%AC%E6%A5%BC%E6%A2%AF2.PNG)

```
int climbStairs(int n){
    int step[2] = {0, 1};
    for (int i = 0; i < n; ++i) {
        step[i & 1] = step[i & 1] + step[(i - 1) & 1];
    }
    return step[(n - 1) & 1];
}
```

