### 解题思路
完整阶梯型其实就是一个等边三角形，完整的row行需要的硬币个数为1+2+3+...+row=(1+row)*row/2

### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) 
    {
        /*
        完整阶梯型其实就是一个等边三角形，完整的row行需要的硬币个数为1+2+3+...+row=(1+row)*row/2
        */
        int left = 0;
        int right = n;
        while (left <= right)
        {
            double middle = (left + right)/2;
            double need = (1+middle)*middle/2;
            if (need == n)
            {
                return middle;
            }
            else if (need < n)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return right;
    }
};
```