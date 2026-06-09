### 解题思路
遍历a的所有可能，然后利用sqrt函数判断b是否能得出一个整数。

### 代码

```c
#include <math.h>

bool judgeSquareSum(int c){
   for (int a = 0; a <= sqrt(c); ++a) {
		double b = sqrt(c - a * a);
        if (b == (int)b) {
            return true;
        }
	}
    return false;
}
```