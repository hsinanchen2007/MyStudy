
执行用时 :4 ms, 在所有 C++ 提交中击败了99.38% 的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 解题思路
使用两个传统艺能：
1. while循环把一个整数的最低位%10求余得到；
2. sum = sum*10 + x 将得到的数字从高位到低位排成翻转后的数

### 代码

```cpp
class Solution {
public:
bool isPalindrome(int x0) {
    int x = x0;
    if(x<0) return false;
    unsigned y = 0;
    while( x != 0 ){
        y = y * 10 + x%10;
        x = x/10;
    }
    if(x0 == y) return true;
    return false;
}   
};
```