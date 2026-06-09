### 解题思路
AxB=(Ax2)x(B/2+(B%2))
	=(A<<1)x(B>>1+(B&1))
	=(A<<1)x(B>>1)+(A<<1)x(B&1)
	=........
一直往下递归，若B最低位为1，做加法。

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
	    if (A == 0 || B == 0) return 0;
	    if (B & 1) 
		    return A + multiply(A<<1, B >> 1);
	    else 
		    return multiply(A<<1, B >> 1);
    }
};


```