### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/03d5dcaf543fef3cc7cbbfabfeb3819ff8cecb489b28a52d549c2d36bb493e3c-image.png)

有了前面的经验，这里聪明了：
1）判断mid是否满足预期，一定不能用 mid * mid.
2）另外一定要判断 num % mid == 0, 不然 26 / 5 == 5的条件会满足，答案不符合预期。
3）计算mid的时候，一定不要使用 (left + right) / 2, 因为 left + right可能会溢出
### 代码

```c
bool isPerfectSquare(int num){
    int left = 0;
    int right = num;
    int mid;

    if (!num || num == 1) {
        return true;
    }

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid == num / mid && num % mid == 0) {
            return true;
        }
        else if(mid > num / mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;
}
```