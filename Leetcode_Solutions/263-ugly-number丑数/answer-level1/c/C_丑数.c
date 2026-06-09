### 解题思路
0 和 1 需要特别判断一下

### 代码

```c
bool isUgly(int num){
    if (num == 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}
```