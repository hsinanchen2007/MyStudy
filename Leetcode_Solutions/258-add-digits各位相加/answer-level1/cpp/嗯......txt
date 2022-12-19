### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
           int result = 0;
            while (num>9)
            {
                result += num % 10;
                num /= 10;
            }
            result += num;
            num = result;
        }
        return num;
    }
};
```