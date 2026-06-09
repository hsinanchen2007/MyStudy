**1.递归**
```c
int addDigits(int num){
    if(num == 0)
        return 0;
    int ans = 0;
    while(num != 0){
        ans += num % 10;
        num /= 10;
    }
    return ans < 10 ? ans : addDigits(ans);
}
```
**2.O(1)**
```
int addDigits(int num){
    return (num - 1) % 9 + 1;
}
```
