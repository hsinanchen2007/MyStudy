### 解题思路
一直除4，如果<=0，则不符合要求
如果%4不为0，则不符合要求
直到除到1为止
![123.PNG](https://pic.leetcode-cn.com/ad0b0e23d7bc6f75992a810eac10ef6d2ebcc1ca022a7a6b184d04a6d68f62c7-123.PNG)

### 代码

```c
bool isPowerOfFour(int num){
    if (num <= 0) {
        return false;
    }
    if (num == 1) {
        return true;
    }
    if (num % 4 != 0) {
        return false;
    } else {
        return isPowerOfFour(num / 4);
    }
}
```