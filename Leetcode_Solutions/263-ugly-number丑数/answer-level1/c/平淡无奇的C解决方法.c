### 解题思路

就是不断的去和2，4，5进行相除，如果最终是1，那么就是true，如果中间无法整除，就是false

### 代码

原来是

```c
bool isUgly(int num){
    if (num == 1) return true;
    while (true){
        int last = num;
        num = num % 2 ? num : num >> 1; //整除2
        num = num % 3 ? num : num / 3;  //整除3
        num = num % 5 ? num : num / 5;  //整除5
        if (num == last) return false;  //无法继续整除
        if (num == 1) break;            //最终得到1
    }
    return true;


}
```

后来修改成

```c
bool isUgly(int num){
    if (num <= 0) return false;
    if (num == 1) return true;
    while (num != 1){
        if ( num % 2 == 0){
            num /= 2;
        } else if ( num % 3 == 0){
            num /= 3;
        } else if ( num % 5 == 0){
            num /= 5;
        } else{
            return false;
        }
    }
    return true;
}
```