### 解题思路
上面都差不多，就是不断约，后面参考了前面判断2的幂的方法

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num<1)return 0;
		while (num % 5 == 0)num /= 5;
		while (num % 3 == 0)num /= 3;
		return(!(num&(num - 1)));//此处判断是不是2的n次幂即可
    }
};
```