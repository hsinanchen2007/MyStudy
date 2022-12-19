### 解题思路
![QQ截图20200301005841.png](https://pic.leetcode-cn.com/a9218fd471b48fcc99a42551a410d0b60ec246e6edfe9ecac1810dfeef225efe-QQ%E6%88%AA%E5%9B%BE20200301005841.png)
![2.png](https://pic.leetcode-cn.com/bbb6f289256f1654fa1d4554258e3dc61cf819ccc13181b23ce341dcb3a85941-2.png)

把整数“逆置”，再判断与原数是否相等即可

NOTE
非回文数“逆置”后可能会导致数值增大，有溢出的风险（比如：INT_MAX:+2147483647 逆置后 变为7463847412 超出int可表示范围）可如下处理：
1)选择较大的数据类型存储“逆置”后的整数,对应第一张运行截图
2）循环加一条判定，当逆置后的数据超出INT_MAX后，跳出循环（还减少了一些计算），返回false。对应第二张运行截图

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long n = x % 10, new_x = 0, old_x = x;
        while(n!=0 || (x != 0 && n == 0))
        {
            new_x = new_x*10+n;
            x /=10;
            n = x%10;
        }
        return old_x == new_x ? true : false;
    }

};

class Solution{
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int n = x % 10, new_x = 0, old_x = x;
        while (n != 0 || (x != 0 && n == 0))
        {
            if (new_x > INT_MAX / 10 || (new_x == INT_MAX / 10 && n > INT_MAX % 10))
                return false;
            new_x = new_x * 10 + n;
            x /= 10;
            n = x % 10;
        }
        return old_x == new_x ? true : false;
    }
};
```