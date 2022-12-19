### 解题思路
用了两种思路来解题，看到该题的第一反应是递归，因此按照递归来做。该方法看着比较乱，不推荐使用
1 判断num是否为0
2 判断num为偶数，然后递归调用，f++
3 判断num为基数，num-1，f++,然后递归调用
### 代码

```c
int numberOfSteps (int num){
    int f = 0;
    printf("%d ", num);
    if(num == 0)
    {
        f = 0;
    }
    else if(num %2 == 0)
    {
        f = numberOfSteps(num/2)+1;
    }
    else
    {
        num = num-1;
        f = +1;
        f = numberOfSteps(num)+1;
    }
    return f;
}
```

第二种方法是利用迭代，思路简单，代码易于实现
```

int numberOfSteps(int num)
{
    int f = 0;
    while(num > 0)
    {
        if(num%2 == 0)
        {
            num = num/2;
            f++;
        }
        else if(num%2 == 1)
        {
            num = num-1;
            f++;
        }
    }
    return f;
}
```
