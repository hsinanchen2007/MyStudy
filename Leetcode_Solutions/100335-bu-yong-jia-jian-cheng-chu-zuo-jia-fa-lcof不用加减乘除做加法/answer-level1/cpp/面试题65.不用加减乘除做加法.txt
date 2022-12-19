### 解题思路
- 核心要点：异或运算可以看成无进位的加法，按位与运算再左移一位可以看成求两数相加的进位值运算
- 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
- 内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        int sum,carry;
        while(b!=0){
            sum=a^b;
            carry=(unsigned)(a&b)<<1;
            
            a=sum;
            b=carry;
        }
        return a;
    }
};
```