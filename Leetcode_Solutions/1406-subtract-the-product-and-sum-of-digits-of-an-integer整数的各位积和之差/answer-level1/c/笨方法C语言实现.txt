### 解题思路
思路比较简单，从右往左循环取n的每个位上的数字，进行求和及求积，最后返回差值。
有个技巧就是当n这个数字中包含0时，积是为0的就不用继续求积了，继续求和即可

### 代码

```c
int subtractProductAndSum(int n){
    int product = 1;
    int sum = 0;
    int temp = 0;
    while(n){
        temp = n % 10;
        if(product != 0){
            product *= temp;
        }
        sum += temp;
        n /= 10;
    }
    return product - sum;
}
```