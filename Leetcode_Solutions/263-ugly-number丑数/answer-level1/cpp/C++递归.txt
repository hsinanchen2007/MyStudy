### 解题思路
既然判断质数，那就把质数提取出来，递归，直到看最后的数是否为1；
要注意为0的特殊情况（防止无限循环）

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return 0;
    while (1)
    {
        if (num %2 == 0)
        {
            num = num / 2;
            continue;
        }
        if (num % 3 == 0)
        {
            num = num /3;
            continue;
        }
        if (num % 5 == 0)
        {
             num = num /5;
             continue;
        }
       
        if (num == 1)
            return 1;
        else
            return 0;
    }
    }
};
```