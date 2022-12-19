### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if(num == 1)
            return false;
        for(int i = 2; i*i < num; i++)
        {
            if(num % i == 0)
            {
                int factor = num / i;
                sum += i + factor;
            }
        }
        return (sum+1 == num);
    }
};
```