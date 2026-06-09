### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了95.68%的用户
内存消耗 :5.8 MB, 在所有 C++ 提交中击败了100.00%
的用户

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int rt = 0;
        while(x > rt){
            rt = rt * 10 + x % 10;
            x /= 10;
        }
        return x == rt || rt / 10 == x;
    }
};
```