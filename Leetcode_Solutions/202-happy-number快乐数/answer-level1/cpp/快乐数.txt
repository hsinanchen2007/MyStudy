### 解题思路

方法：使用“**快慢指针**”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。
注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个题目给出的整数是int型而投机取巧。

作者：rachy
链接：https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/

### 代码

```cpp
class Solution {
public:
    int sq_sum(int x)
    {
        int sum = 0;
        while(x)
        {
            int cur = x % 10;
            sum += cur * cur;
            x /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int fast = n,slow = n;
        do
        {
            slow = sq_sum(slow);
            fast = sq_sum(fast);
            fast = sq_sum(fast);
        }while(fast != slow);
        if(slow == 1) return true;
        return false;
    }
};
```