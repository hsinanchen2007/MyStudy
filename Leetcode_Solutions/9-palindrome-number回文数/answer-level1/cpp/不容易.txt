### 解题思路
暴力解决，这是我在力扣提交的第一个程序，关键还是出错了很多次才能提交成功的程序，一开始打算用转换成字符去解决，发现出现对于10这类不能解决的数字，又苦于没有办法，于是暂停了这种想法。后来改到暴力解决，在这里开始将y设置为int类型，又报错了，于是改成long long解决。太不容易了，加油。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long y = 0;
        int num = x;
        while(num > 0){
            int j = num%10;
            y = y * 10 + j;
            num = num/10;
        }
        return x == y;
    }
};
```