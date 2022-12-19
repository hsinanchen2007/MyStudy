### 解题思路
设置最多循环10次就可以了

### 代码

```c
bool isHappy(int n){
    int count  = 0;
    int sum = 0;
    while(count < 10)
    {
        while(n > 0)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        if(sum == 1) {
            return true;
        } else {
            n = sum;
            sum = 0;
        }
        count++;
    }
    return false;
}
```