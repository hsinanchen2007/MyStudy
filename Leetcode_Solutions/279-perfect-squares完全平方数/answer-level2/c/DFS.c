![image.png](https://pic.leetcode-cn.com/fe00bcf169adec7d8ec31bbe5472eb79fa6d2aa12471c936a3384676ac70089a-image.png)

### 解题思路

递归时从当前n的平方根开始由大到小进行遍历，每次取到接近n的最大i的平方。
对于可以确定不满足条件的数，可以直接跳出，不需要计算

### 代码

```c
int min = 0;

void GetNum(int n, int num)
{
    int m, i;
    if (n == 0) {
        if (num < min) {
            min = num;
        }
        return;
    } else if (n < 0) {
        return;
    }

    for (i = sqrt(n); i > 0; i--) {
        m = n / (i * i);
        if (m + num > min) {
            break;
        }
        GetNum(n - m * i * i, num + m);
    }
}

int numSquares(int n){
    min = n;
    GetNum(n, 0);
    return min;
}
```