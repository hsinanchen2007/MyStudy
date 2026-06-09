### 解题思路
1.先求出x的位数s
2.将x的低s/2位翻转
3.比较x的高s/2位和高s/2位是否相等(注意若s为奇数，那么舍弃中间那个数)
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        //求出位数
        int temp = x;
        int s = 0;
        while(temp){
            s += 1;
            temp /= 10;
        }
        //求出高s/2位和翻转的低s/2位
        int a = s / 2;
        int res = 0;
        while(a--){
            res = res * 10 + x % 10;
            x /= 10;
        }
        //s为奇数时，舍弃中间位
        if(s % 2 == 1)
            x /= 10;
        return res == x;
    }
};
```