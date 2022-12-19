### 解题思路
关键在反转时的范围问题，由于Python负数模10时结果不是本题想要的，后用C++更方便；
由于数字大于 2\*\*31=2147483648 左右会报错，在将其**乘10前检验其大小**，乘10后会超标则直接终止循环，返回0；

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
		int res = 0;                // 结果
		while (x != 0){
            if (res > 214748364)    // 2**31 = 2147483648，判断除各位外大小
            {
                res = 0;
                break;
            }

            if (res < -214748364)   // 同上
            {
                res = 0;
                break;
            }

			res = 10*res + x%10;
			x /= 10;
		}
		
		return res;
    }
};
```