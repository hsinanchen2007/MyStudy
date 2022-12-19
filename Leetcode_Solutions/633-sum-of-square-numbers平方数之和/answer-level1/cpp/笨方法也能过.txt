### 解题思路

![image.png](https://pic.leetcode-cn.com/a70f9c3700154ecbad50aed23e06b8b46e7b584996e3785f8cf3aed63ebc7efa-image.png)

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 2) {
            return true;
        }
        long long  left = 0;//设定左右边界
        int right = sqrt(c);//右边界的设定，绝对不会超过c的平方根
        while (left <= right) {
            long long target = left* left + right * right;//换成long long类型以防溢出
            if (target == c) {//直接找到了，返回即可
                return true;
            } else if (target > c) {
                right --;
            } else if (target < c) {
                left ++;
            }
        }
        return false;

    }
};
```