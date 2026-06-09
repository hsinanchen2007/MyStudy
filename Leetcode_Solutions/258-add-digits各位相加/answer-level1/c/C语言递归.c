### 解题思路
递归解决，结果不是个位数的话就接着算
![image.png](https://pic.leetcode-cn.com/be980143b7528600d3120236539c17d03531f3c974531b14491c99956c9cb444-image.png)


### 代码

```c
int addDigits(int num){
    if(num < 10) {
        return num;
    }
    int sum = 0;
    while(num > 0) {
        sum += (num % 10);
        num /= 10;
    }
    return addDigits(sum);
}
```