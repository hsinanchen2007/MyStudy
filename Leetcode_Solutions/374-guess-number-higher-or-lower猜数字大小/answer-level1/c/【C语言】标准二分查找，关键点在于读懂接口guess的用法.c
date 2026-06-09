### 解题思路
- LeetCode374. 猜数字大小
- 数组[1, 2,..., n]自动按升序排列
- 标准二分查找
- 关键点：读懂题目的接口guess(int num)的用法，题意为 
(1) 预先选定的数target比猜测的数num小，返回-1;
(2) 预先选定的数target比猜测的数num大，返回1;
(3) 预先选定的数target等于猜测的数num，返回0。

### 代码

```c

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number   (<)
 *			      1 if num is higher than the guess number  (>)
 *               otherwise return 0                         (=)
 * int guess(int num);
 */

int guessNumber(int n)
{
    int left = 1;
    int right = n;
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;  // 防止溢出
        if (guess(mid) == -1) {
            right = mid - 1;
        } else if (guess(mid) == 1) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    
    return left;
}
```