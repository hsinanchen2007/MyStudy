题解：

思路1：数学公式法

能用数学公式解决的，一定可以通过代码解决；
        ![asd.png](https://pic.leetcode-cn.com/01c3de83abccba4c7da867cf7194d472748e447b825cec9f80d28f658b2460d9-asd.png)

```
    var arrangeCoins = function(n) {

        return Math.floor(Math.sqrt(2*n+0.25)-0.5);

    };
```

思路2：递增法

像这种线性递增，规律太明显，可以用条件法或循环来解决，当累加得值大于给定的n时，返回上个行数；

```
    var arrangeCoins = function(n) {

        let i = 0,sum = 0;

        while (++i) {

            sum += i;

            if (sum > n) return i - 1;

        }

    }
```

公众号  惊天码盗   回复算法  参与活动