# 思路
假设巨无霸汉堡$x$个，小皇堡$y$个，那么可得二元一次方程如下：
$4x + 2y = tomatoSlices$
$x + y = cheeseSlices$

求解方程可得：
$x = tomatoSlices / 2 - cheeseSlices$
$y = cheeseSlices - x$

因此，在x和y必须是非负整数的前提下，从上面x和y的解可发现以下几个规律：
1. $tomatoSlices$ 必须是偶数；
2. $tomatoSlices / 2 - cheeseSlices$ 必须 $>= 0$
3. $cheeseSlices - x$ 必须 $>= 0$

代码如下：
```java
  public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> ansList = new ArrayList<>();
        if ((tomatoSlices & 1) == 1) {
            return ansList;
        }

        int x = tomatoSlices / 2 - cheeseSlices;
        if (x < 0) {
            return ansList;
        }

        int y = cheeseSlices - x;
        if (y < 0) {
            return ansList;
        }

        ansList.add(x);
        ansList.add(y);

        return ansList;
    }
```


