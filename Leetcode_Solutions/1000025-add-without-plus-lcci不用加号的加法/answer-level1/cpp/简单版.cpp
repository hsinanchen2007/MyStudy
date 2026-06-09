### 解题思路
既然加与减是相对的，那么a+(-b)会将a-b,那么a-(-b)等于a+b。
### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        return a-(-b);
    }
};
```