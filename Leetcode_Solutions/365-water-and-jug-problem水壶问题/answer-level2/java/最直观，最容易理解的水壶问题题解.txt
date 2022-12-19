先排除掉肯定失败的情况，比如：
1. `x`, `y`是偶数，而 `z`是奇数，因为倒水的本质是加减法，两个偶数通过加减不可能得到一个奇数。
2. `z<0`
3. `z>x+y`

另外我们也可以得到一些肯定成功的情况，如下
`z == x || z == y || z == 0 || z == x + y || z % x == 0;`

然后再回到倒水问题本身。我们假设`x < y`，如果`z`大于`x`，那么该问题等价于
> 使用x, y能不能倒出z%x的水。因为 `z = z%x + n*x`;

经过这样一次等价转化，我们得到一个性质：`z < x < y`;

此问题可以拆分为两个子问题：
1. `x`容器最终盛有`z`升水，这意味着`x`容器倒掉了`x-z`升水；如果`x`容器能够倒掉`x-z`升水，那么在此之前`y`容器肯定盛有`y-(x-z)`升水;
2. `y`容器最终盛有`z`升水，这意味着`y`容器倒掉了`y-z`升水；如果`y`容器能够倒掉`y-z`升水，那么在次之前`x`容器肯定盛有`x-(y-z)`升水,

上述两个子问题中任意一个成立，即可保证最终可以利用 `x`,`y`升的容器倒出`z`升水。
即：
```
measure(x, y, z) = measure(x, y, x - (y - z)) || measure(x, y, y - (x - z));
```

最后考虑一下，在什么时候，永远不会成功呢？
答案是，`z`重复出现了，即 **死循环递归了** ，可以通过Set记录一下`z`值，如果当前的`z`值，在此之前碰到过，那么分两种情况考虑，
1. 上一次失败了，那么直接返回`false`
2. 上一次成功了（其实不会发生，因为成功了马上就会返回，不会考虑其它分支），那么不用考虑当前分支了，

解释得有点乱……

代码如下：

```java []
import java.util.HashSet;
import java.util.Set;

class Solution {
    Set<Integer> scanned = new HashSet<Integer>();
    
    public boolean canMeasureWater(int x, int y, int z) {
        int min = Math.min(x, y);
        int max = Math.max(x, y);
        if ((x & 1) == (y & 1) && (x & 1) == 0 && (z & 1) == 1 || z < 0 || z > x + y) {
            return false;
        }
        return this.measureWater(min, max, z);
    }

    public boolean measureWater(int x, int y, int z) {
        if (z == x || z == y || z == 0 || z == x + y || z % x == 0) {
            return true;
        }
        z = z % x;
        if (scanned.contains(z)) {
            return false;
        }
        scanned.add(z);
        int z1 = x - (y - z);
        int z2 = y - (x - z);
        return measureWater(x, y, z1) || measureWater(x, y, z2);
    }
}
```