### 解题思路

简单题

T: O(LOGN)

S: O(1)

### 代码

```c
int subtractProductAndSum(int n){
    int sum = 0;
    int multi = 1;
    while (n) {
        int temp = n % 10;
        n /= 10;
        sum += temp;
        multi *= temp;
    }

    return multi - sum;
}
```