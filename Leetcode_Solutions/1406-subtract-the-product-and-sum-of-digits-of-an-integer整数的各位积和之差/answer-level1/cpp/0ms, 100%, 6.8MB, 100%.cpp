### 解题思路
首先定和(sum)为0，乘积(product)为1.然后再利用循环每次加/乘上去。
再用while loop 取n的模，从而获得个位数，然后把个位数(加/乘)进 (和/乘积)
在while loop的结尾把n/ 10 从而在下一次循环中可以找到下一个个位数。
最后return 积和之差。

### 代码

```c
int subtractProductAndSum(int n){
    int pro = 1, sum = 0;
    while(n != 0){
        pro *= n % 10;
        sum += n % 10;
        n /= 10;
    }
    return pro - sum;
}
```