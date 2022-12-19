### 解题思路
1.排除负数
2.判断反转后的数是否与原数相同

### 代码

```c
bool isPalindrome(int x)
{
    int tmp = x;
    long output = 0;

    if (x < 0) {
        return false;
    }

    while (tmp) {
        output = output * 10 + tmp % 10;
        tmp = tmp / 10;
    }

    if (x == output) {
        return true;
    }

    return false;
}
```