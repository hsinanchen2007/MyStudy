### 解题思路
本来还在想负整数的情况，结果题目只考虑正整数~
所以一定要注意审题~

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        if(B==1) return A;
        return A+multiply(A,B-1);
    }
};
```