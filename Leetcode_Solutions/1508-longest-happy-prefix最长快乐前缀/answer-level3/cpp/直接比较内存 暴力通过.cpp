### 解题思路
memcmp 比较内存中两个地址的前N 个字节，底层实现其实也是O(N)算法，只不过用了寄存器，可以加速计算

### 代码

```cpp
    string longestPrefix(string s) {
        int N = s.size();
        for (int i = 1; i < N; ++i) {
            if (0 == memcmp(s.c_str(), s.c_str() + i, N-i)) { //直接地址比较，不能用substr，空间超限
                return s.substr(0, N-i);
            }
        }
        return "";
    }
```

memcmp 参考实现
```
#include <ansidecl.h>
#include <stddef.h>

int
memcmp (const PTR str1, const PTR str2, size_t count)
{
  register const unsigned char *s1 = (const unsigned char*)str1;
  register const unsigned char *s2 = (const unsigned char*)str2;

  while (count-- > 0)
    {
      if (*s1++ != *s2++)
	  return s1[-1] < s2[-1] ? -1 : 1;
    }
  return 0;
}
```

refs: https://github.com/gcc-mirror/gcc/blob/master/libiberty/memcmp.c

