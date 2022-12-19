这道题目的难度是中等。如果题解都看不懂..很有可能是题解的思路有点问题。当然我们的目的是训练和学习，把很绕的思路吃透不能说是没有益处的 ：）

言归正传，我想有必要把最易理解的思路分享给大家，万一以后遇到原题这种思路应该是最方便回忆写出来的。使用最大公约数的数学方法我相信绝大多数人不可能自己短时间内想出来，了解定理之后又没什么可解释的，不再赘述。我们把精力放在BFS方法上。

首先，最终我们还是需要用这个两个水壶装水，那么`z>x+y`的情况就不需要考虑了。

然后，我们能做的操作无非是把水倒来倒去。假设这一坨水的体积为`tmp`，初始`tmp==0`，任何时候我们能做的操作没那么复杂，最多四种
- 加上x罐的水得到 tmp + x 
- 加上y罐的水得到 tmp + y
- 把水到满空的x罐 得到 tmp - x
- 把水到满空的y罐 得到 tmp - y

当然这其中很多情况是不可能发生的，水的体积不可能大于 x+y，本身比x或y少倒进去也没有意义等等。
这其中能够实现的情况就说明我们可以组合得到这么多水！这时
- 一方面要把它记录在下来（不妨使用一个HashSet），
- 另一方面要把它当作新的`tmp`去考察一遍新的可能性（不妨每次把能够实现的情况压入一个队列中稍后回来考察）。

当所有的可能性都考察完毕之后，我们在Set中寻找是否存在z，便可知道能不能得到z升水了。

下面是我的java代码。注意`set.add`的用法，当set中已经存在同样的数字时，add方法返回false。

```java
public boolean canMeasureWater(int x, int y, int z) {
    if (z > x + y) {
        return false;
    }

    Set<Integer> set = new HashSet<>();
    Queue<Integer> queue = new LinkedList<>();
    queue.offer(0); 
    while (!queue.isEmpty()) {
        int tmp = queue.poll();
        if (tmp + x <= x + y && set.add(tmp + x)) {
            queue.offer(tmp + x);
        }
        if (tmp + y <= x + y && set.add(tmp + y)) {
            queue.offer(tmp + y);
        }
        if (tmp - x >= 0 && set.add(tmp - x)) {
            queue.offer(tmp - x);
        }
        if (tmp - y >= 0 && set.add(tmp - y)) {
            queue.offer(tmp - y);
        }
        if (set.contains(z)) {
            return true;
        }
    }
    return false;
}
```
没有很难把。





我实现的GCD解法代码也贴在这里，如果需要欢迎查阅。

```java
public boolean canMeasureWater(int x, int y, int z) {
    if (z > y + x)
        return false;
    // assume x is not smaller
    if (x < y)
        return canMeasureWater(y, x, z);

    if (y == 0)
        return z == 0 || z == x;
    return z % gcb(x, y) == 0;
}

// m >= n
private int gcb(int x, int y) {
    if (x % y == 0) {
        return y;
    } else { 
        return gcb(y, x % y);
    }
}
```