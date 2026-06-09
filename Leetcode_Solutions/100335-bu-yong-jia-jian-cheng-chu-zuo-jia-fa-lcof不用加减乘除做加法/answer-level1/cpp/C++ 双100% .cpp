
![image.png](https://pic.leetcode-cn.com/2b7060078448f9ce69ce8db6735187bd02d3496d768b579f4fcf2d91bd98aa11-image.png)

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        int sum,carry;
        while(b)
        {
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1; //保存进位的结果，当不再需要进位时，求和结束
            a = sum;
            b = carry;
        }
        return a;
    }
};
```