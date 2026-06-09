### 解题思路
	想了半天没想到BFS也没想到数学法，写的暴力循环没用，看了题解发现数学还是王道

### 代码

```c
#include <stdbool.h>

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return a > b ? gcd(b, a%b) : gcd(a, b%a);
}

bool canMeasureWater(int x, int y, int z) {
	if (x + y < z) {
		return false;
	}
    if (z == 0) return true;
    if (x == 0){
        return z==y?true:false;
    }
    if (y == 0){
        return z==x?true:false;
    }
	/* ax + by = z */
	if (z % gcd(x, y) == 0) {
		return true;
	}
	else {
		return false;
	}
}
```