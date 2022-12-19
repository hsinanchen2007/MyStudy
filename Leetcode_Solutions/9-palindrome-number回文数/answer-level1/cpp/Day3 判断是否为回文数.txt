### 解题思路
1. 如果数字为负数，则一定不会是回文数
2. 后面思路与整数回转思路相同，判断回转后的数字与原来的整数是否相同即可
3. 这里需要考虑一下整数的范围，第一次将i设置为了int型，执行出错，因为一些个位比较大的整数回转之后会超出int型表示范围，将i设置为long型则运行通过。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long i = 0;
        int t = x;
        
        // 判断是否为负数
        if (x < 0)
            return false;
        
        while(t)
        {
            i = i*10 + t%10;
            t = t/10;
        }

        if (i == x)
            return true;
        else
            return false;
    }
};
```