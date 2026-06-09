### 解题思路
采用循环的方法实现，将运算式以4个为一个划分，计算结果，最后不足4的部分分类考虑加上。
int clumsy(int N){
    int div = N/4;
    int div2 = N%4;
    int i=0;
    int val1=0;
    int val2=0;
    while(i<div)
    {
        if(i==0)
            val1+=(N)*(N-1)/(N-2)+(N-3);
        else
            val1-=(N)*(N-1)/(N-2)-(N-3);
        N=N-4;
        i++;
    }
    switch(div2){
    case 0:val2=0;break;
    case 1:val2=1;break;
    case 2:val2=2;break;
    case 3:val2=6;break;
    }
    if(div!=0)
        val1=val1-val2;
    else
        val1=val2;
    return val1;
}

### 代码

```c
int clumsy(int N){
    int div = N/4;
    int div2 = N%4;
    int i=0;
    int val1=0;
    int val2=0;
    while(i<div)
    {
        if(i==0)
            val1+=(N)*(N-1)/(N-2)+(N-3);
        else
            val1-=(N)*(N-1)/(N-2)-(N-3);
        N=N-4;
        i++;
    }
    switch(div2){
    case 0:val2=0;break;
    case 1:val2=1;break;
    case 2:val2=2;break;
    case 3:val2=6;break;
    }
    if(div!=0)
        val1=val1-val2;
    else
        val1=val2;
    return val1;
}
```