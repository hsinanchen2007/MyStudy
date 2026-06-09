无脑暴力查找法，刚接触编程的同学可以参考。简单易懂。一个个数字去试就可以了。
```
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 1)
            return true;
        for (int i = 0; i <= num / 2; i ++){
            if (i * i ==num)
                return true;
        }
        return false;
    }
}
```