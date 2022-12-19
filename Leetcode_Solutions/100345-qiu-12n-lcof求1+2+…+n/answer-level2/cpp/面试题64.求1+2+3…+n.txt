### 解题思路
- 核心要点：递归+逻辑运算短路原则
- 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
- 内存消耗：6.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        int sum=0;
        (n>0)&&((sum+=sumNums(n-1)+n)>0);
        return sum;
    }
};
```