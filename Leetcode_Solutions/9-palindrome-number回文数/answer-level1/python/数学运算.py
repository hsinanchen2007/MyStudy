## 思路：

当然直接用字符串反转比较就行了 `[::-1]`

也可以通过数学运算，找到取反的数

## 代码：

```Python []
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0) or (x != 0 and x % 10 == 0):
            return False
        cmp_num = 0
        while x > cmp_num:
            cmp_num = cmp_num * 10 + x % 10
            x //= 10
        #print(x,cmp_num)
        return x == cmp_num or x == cmp_num // 10
```
```C++ []
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int cmp_num = 0;
        while(x > cmp_num){
            cmp_num = cmp_num * 10 + x % 10;
            x /= 10;
        }
        return x == cmp_num || x  == cmp_num/10;
        
    }
};
```

