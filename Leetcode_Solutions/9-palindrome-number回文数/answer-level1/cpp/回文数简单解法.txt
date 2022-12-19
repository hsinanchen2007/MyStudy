### 解题思路
把整数翻转一下，如果翻转的和原来的相等就是回文数了。
没考虑翻转之后溢出的情况是因为，如果翻转之后溢出了就肯定不是回文数了。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int i = 0;long j = 0;int xx = x;
        while(xx > 0)
        {
            j = xx % 10 + j * 10;  
            xx = xx / 10;
            i++;
        }
        if((int)j == x)
        {
            return true;
        }else{
            return false;
        }
    }
};
```