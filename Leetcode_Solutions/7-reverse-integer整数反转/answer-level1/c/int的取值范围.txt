### 解题思路
int 类型的取值范围在- 2,147,483,648——2,147,483,647之间
若采用long long 型即可包含int类型的取值范围

### 代码

```c

int reverse(int x){
    
    int r = 0;
    long long sum = 0;
    while(x != 0){
        r = x % 10;
        x = x / 10;
        sum = sum * 10 + r; 
    }
    if(sum > INT_MAX || sum < INT_MIN) return 0;
    else return sum;
}
```