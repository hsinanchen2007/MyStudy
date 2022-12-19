对 x 进行逐个 除 10 取 个位，一旦溢出，直接跳出循环

```
int reverse(int x) {
    
 long long temp = 0;
  
  while (x % 10 != 0 || x / 10 != 0) {
    int ge = x % 10;
    temp = (long long )(ge + temp * 10);
      if (temp > INT_MAX || temp < INT_MIN) {
        return 0;
      }
    x -= ge;
    x = x/10;
  }
    
  return (int)temp;
    

}
```