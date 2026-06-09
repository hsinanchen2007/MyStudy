### 解题思路
- 核心要点：f(n)=(f(n-1)+m)%n
- 执行用时 :8 ms, 在所有 C++ 提交中击败了88.64%的用户
- 内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f=0;
        for(int i=2;i<=n;i++){
            f=(f+m)%i;
        }
        return f;
    }
};
```