### 解题思路
num大于零时循环，偶数除2奇数减1

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int cont=0;
        while(num > 0)
        {
            if(num%2 == 0)
            {
                num = num/2;
                cont++;
                continue;
            }
            if(num%2 == 1)
            {
                num = num-1;
                cont++;
                continue;
            }
        }
    return cont;
    }
};
```