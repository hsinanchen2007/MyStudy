### 解题思路
分析题目：1、 x<0，直接返回false；
         2、 0<x<9，一定是回文数；
         3、 9<x<2147483647, 反转并与原数作比较。
注意点：1、对输入做溢出判断；
       2、反转的数学核心： reverse = reverse * 10 + x%10; x /= 10;
       3、没必要在程序开头写条件语句判断与0和9的大小关系，因为输入绝大部分是                    9<x<2147483647，在开头写0、9判断是否直接返回对于所有情况实际上并没有save             cost
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse = 0;
        int y = x;
        while (x > 0)
        {
            reverse = reverse * 10 + x%10;//提取末位并左移
            x /= 10;
            if (reverse > 2147483647)return false;//overflow
            //这里还是要及时停止循环，不要放到最后一个return去判断，不然增大耗时
        }
        return y<0 ? 0 : reverse == y ;
        
    }
};
```