### 解题思路
两个循环搞定

### 代码

```cpp
class Solution {
public:
    int addDigits(int num)
    {
        int sum;
        do {
            sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        } while (sum > 9);
        return sum;
    }
};
```