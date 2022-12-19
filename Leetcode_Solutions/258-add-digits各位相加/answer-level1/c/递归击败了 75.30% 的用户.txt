### 解题思路
击败了
75.30%
的用户
### 代码

```c
int addDigits(int num){
    int x = 0;
    if (num / 10 == 0) return num;
    while (num != 0)
    {
        x += num % 10;
        num /= 10;
    }
    return addDigits(x);
}
```