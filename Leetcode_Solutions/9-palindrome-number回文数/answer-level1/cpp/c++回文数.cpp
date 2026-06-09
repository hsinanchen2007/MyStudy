### 解题思路
此处撰写解题思路

### 代码
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
85.56%
的用户
内存消耗 :
5.9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long val = 0;
        long last = x;

        for(long i = 10; ; i++)
        {
            val = val * 10 +last%10;
            last /= 10;
            if(last == 0)
                break;
        }
        if(x == val)
            return true;

        return false;
    }
};
```