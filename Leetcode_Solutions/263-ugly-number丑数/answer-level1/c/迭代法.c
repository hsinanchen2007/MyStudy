### 解题思路
如果num%2||3||5 == 0，则num /= 2||3||5，继续上述操作，直到某一次的num不是2，3，5的倍数，则返回false，如果一直执行到num == 1，则说明num是丑数

### 代码

```c
bool isUgly(int num){
    if(num < 1)
        return false;
    int i;
    while(num != 1){
        if(0 == num%2)
            num /= 2;
        else if(0 == num%3)
            num /= 3;
        else if(0 == num%5)
            num /= 5;
        else 
            return false;
    }
    return true;
}
```