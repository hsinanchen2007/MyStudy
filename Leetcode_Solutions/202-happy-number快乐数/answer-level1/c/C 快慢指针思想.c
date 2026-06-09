### 解题思路
不快乐的数，不会停止，那么一定是有循环。
那么如何区分是否有循环呢？
第一种可以记录计算平方的中间值，利用哈希，如果之后出现过之前的平方和，那么就是出现循环了（想想我们如何寻找无限循环小数的），但是保存中间值的大小不好确定。
第二种就是评论大神说的快慢指针思想，如果不是快乐数，那么平方和一定是循环的，快慢指针找循环。
如果是快乐数，也会在平方和为1时终结。
因此，打破循环的条件就是快慢指针相等。此时如果平方和为1，就是快乐数。否者不快乐。

### 代码

```c
int getSquare(int num) {
    int tmp = 0;
    int sum = 0;
    while (num > 0) {
        tmp = num % 10;
        sum = sum + tmp * tmp;
        num = num / 10;
    }
    return sum;
}

bool isHappy(int n){
    int slow = getSquare(n);
    int fast = getSquare(n);
    fast = getSquare(fast);
    
    while (slow != fast) {
        slow = getSquare(slow);
        fast = getSquare(fast);
        fast = getSquare(fast);
    }
    return slow == 1;
}
```