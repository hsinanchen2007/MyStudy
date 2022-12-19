```
    /**
     * 其实就是看x和y的最大公约数能否整除z，
     * 具体解释如下：
     * 若a,b是整数,且gcd(a,b)=d，那么对于任意的整数x,y,ax+by都一定是d的倍数，特别地，一定存在整数x,y，使ax+by=d成立。
     * 之后百科了一下发现这其实是裴蜀定理：
     * 如果所需要的水量是两个水壶容量的最大公约数的倍数，且水量不大于两个水壶的容量之和，那么必然可以用这两个水壶操作得到所需要的水量。
     *
     * 裴蜀定理 : https://baike.baidu.com/item/%E8%A3%B4%E8%9C%80%E5%AE%9A%E7%90%86/5186593?fr=aladdin
     */
    public boolean canMeasureWater(int x, int y, int z) {
        // 在一个瓶子为空的情况，另一个瓶子只能等于水的容量，不然没法搞
        if (x == 0 || y == 0) {
            if (x == z || y == z) return true;
            return false;
        }
        // 特判：x+y<z时一定是false！！！ 仔细品一品
        if (x + y < z) return false;
        // 辗转相除法  是不是特别眼熟 3.12的每日一题 -> 1071. 字符串的最大公因子
        int tmp = gcd(x, y);
        return z % tmp == 0;
    }

    private int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
```
