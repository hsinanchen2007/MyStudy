### 解题思路

就像跑步一样，快乐数跑的是100m冲刺，非快乐数则是在1个400米的环形跑道里无休止的跑下去。

快慢指针就像是专业运动员和业务运动员，在100m的跑道上，两个都会跑到1. 而在环形跑道上，两个指针虽然见面了，但是估计慢指针才跑完一圈，快指针已经跑完两圈了

### 代码

```c
int calcSquare(int n){
    int res = 0 ;
    while (n > 0){
        res += ( n % 10) * ( n % 10);
        n = n / 10;
    }
    return res;
}

bool isHappy(int n){
    int fast = n, slow = n;
    do {
        fast = calcSquare(fast);
        fast = calcSquare(fast);
        slow = calcSquare(slow);
    } while ( fast != slow);
    return slow == 1;

}
```