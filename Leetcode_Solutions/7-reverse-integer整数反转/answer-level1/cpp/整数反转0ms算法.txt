### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了89.92%的用户

当y大于INT_MAX / 10的时候，再*10必定溢出
当y等于INT_MAX / 10的时候，由于原数据的高位数据只能为1或2（-2147483648~2147483647），所以不存在溢出风险（即>7或<-8）

### 代码

```cpp
class Solution 
{
public:
    int reverse(int x) 
    {
        int y = 0;

        while(x != 0)
        {
            int t = x % 10;

            if(y > (INT_MAX / 10))
            {
                return 0;
            }

            if(y < (INT_MIN / 10))
            {
                return 0;
            }

            y = y * 10 + t;
            x /= 10;
        }

        return y;
    }
};
```