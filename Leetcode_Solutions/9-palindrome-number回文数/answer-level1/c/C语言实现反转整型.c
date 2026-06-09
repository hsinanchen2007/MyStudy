思路：通过将整型数据进行倒转，比较两个值，如果相等，则为回文，否则不是。
特殊情况：需要考虑整型溢出情况
```
bool isPalindrome(int x){
    if (x < 0) return false;
    if (x == 0) return true;

    unsigned int val = 0;
    int rem = 0;
    int backUp = x;
    while (x > 0) {
        rem = x % 10;
        x = x / 10;
        val = val * 10 + rem;
    }

    if (val != backUp) return false;
    return true;
}

```
