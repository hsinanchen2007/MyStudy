### 解题思路
   

### 代码

```c
bool isPerfectSquare(int num){
    long n = 1;
    if (num == 1){
        return true;
    }
    while (n*n < num){
        n++;
        if (n * n == num){
           return true;
        }
    }
    return false;
}
```