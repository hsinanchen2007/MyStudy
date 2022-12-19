### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        if (A==1) return B;
        if(A>B) return multiply(B,A);
        return multiply(A/2,B)+multiply(A-A/2,B);
    }
};
```