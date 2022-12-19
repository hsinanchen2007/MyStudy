1. 关于int和long表示的数的范围
- **早期的操作系统是16位系统，**

    int用二字节表示，范围是-32768~32767；
    long用4字节表示，范围是-2147483648~2147483647。

- **后来发展到32位操作系统，**

    int 用4字节表示，与long相同。

- **目前的操作系统已发展到64位操作系统，但因程序编译工艺的不同，两者表现出不同的差别：**

    32位编译系统：int占四字节，与long相同。
    64位编译系统：int占四字节，long占8字节，long数据范围变为：-2^63~2^63-1

2. 在#include<climits>中，INT_MAX表示int的最大值，INT_MIN表示int的最小值
    也可以`int max = 0x7fffffff, min = 0x80000000`表示int的最值


3. 下面是代码


```
int reverse(int x){
    long y = 0;
    while (x != 0){
        int n = x % 10;
        y = y * 10 + n;
        x /= 10;
    }
    return (y > INT_MAX || y < INT_MIN) ? 0 : y;
}
```

也可以这样，不过上面空间换时间。
```
int reverse(int x){
    int y = 0;
    while (x != 0){
        int n = x % 10;
        if (y > INT_MAX / 10 || y < INT_MIN / 10)
            return 0;
        y = y * 10 + n;
        x /= 10;
    }
    return y;
}
```
