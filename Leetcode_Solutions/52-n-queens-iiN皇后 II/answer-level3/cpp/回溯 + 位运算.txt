### 解题思路

执行用时 :4 ms, 在所有 C++ 提交中击败了90.32% 的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了96.97%的用户

### 代码

```cpp
class Solution {
private:
    int res = 0;
    int L;
public:
    int totalNQueens(int n) {
        L = n;
        backtrack(0, 0, 0, 0);
        return res;
    }
    
    void backtrack(int i, int col, int ld, int rd) {
        if(i == L) {
            res++;
            return;
        }
        
        int bits = ~(col | ld | rd) & ((1 << L) - 1);
        while(bits) {
            int place = bits & -bits;
            backtrack(i + 1, col | place, (ld | place) << 1, (rd | place) >> 1);
            bits &= (bits - 1);
        }
    }
};
```