### 解题思路
包含头文件math.h，直接用对数函数，哈哈，耍狡的

### 代码

```c
#include <math.h>
bool isPowerOfTwo(int n)
{
if(n==1)return 1;
if(log2(n)==(int)log2(n)) return 1;
else return 0;
}
```