### 解题思路
随便找个数，对这个数按题意进行计算。我选择2，2^2=4, 4^2=16, 1^2+6^2=37, 3^2+7^2=58, 5^2+8^2=89, 8^2+9^2=145, 1^2+4^2+5^2=42, 4^2+2^2=20, 2^2+0^2=4, 4^2=16...已经出现了规律，只要n为其中一个数就不是快乐数。

### 代码

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)return false;  //题意必须保证正整数
        if(n==1)return true;
        if(n==4 || n==16 || n==37 || n==58 || n==89 || n==145 || n==42 || n==20)
            return false;
        int temp = 0;  //存放各位平方和
        while(n)
        {
            temp += (n%10)*(n%10);
            n /= 10;
        }
        return isHappy(temp);
    }
};
```