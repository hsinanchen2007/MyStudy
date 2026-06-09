### 解题思路
用数组保存goto labels，然后用关系表达式的值作为数组的下标访问label并跳转。
类似的，还可以用数组保存函数指针并不断地通过函数调用来完成计算。

时间复杂度 O(n)
空间复杂度 O(1)

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        int r = 0;
        void* label[] = {&&end, &&repeat};
    repeat:
        r += n;
        n--;
        goto *label[n > 0];
    end:
        return r;
    }
};
```