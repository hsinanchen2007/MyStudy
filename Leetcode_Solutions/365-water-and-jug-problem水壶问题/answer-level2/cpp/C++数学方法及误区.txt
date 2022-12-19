![}ZE{4~WF937DNZLENSQ~C\[U.png](https://pic.leetcode-cn.com/572b557c990e0ab0a08fddfbeb0a46866aacdfeabf66b302a49ef7eeac2d1e87-%7DZE%7B4~WF937DNZLENSQ~C%5BU.png)
# 题目的误区
用x升容器和y升容器通过三种方法，恰好可以得到y升水。
不需要一次性得到y升水，而是假设有一个y升的水壶，允许你一次次倒入一定量的水，最后刚好填满不溢出。
# 方法
可以利用每次的操作来进行递归迭代进行深度搜索
而更简单的方法是利用x升和y升水壶得到最小的水量（最大公约数）来一次次填满y升水。
# 扩展
1.经过多少次给定的操作恰好得到y升水？
2.经过操作的顺序是什么？
# 代码
时间线性，空间常数
```
class Solution {
public:
    int getMaxYueShu(int x, int y) {
        while(x != y) {
            if(x > y)
                x -= y;
            else
                y -= x;    
        }
        return x;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x+y < z) 
            return false;
        if(x == 0 || y == 0)
            return z == 0 || x+y == z;
        return z % getMaxYueShu(x, y) == 0;
    }
};

```
