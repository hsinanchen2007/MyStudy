### 解题思路
直接引头文件进来<math.h>进来，里面有关于开平方的函数，直接调用，然后强制转换为int整型数据

### 代码

```c
#include <math.h>
int mySqrt(int x)
{
int result=sqrt(x);
return result;
}
```