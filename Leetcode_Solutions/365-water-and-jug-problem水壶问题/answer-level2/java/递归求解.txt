### 解题思路
判断当前的情况下，有哪些状态是可以转换的，放入到队列中。依次搜索即可。 
情况有多种
1. 导入水
2. 不导入水
    * 互相倒水
        * 杯子是否满
    * 直接清空一个杯子
考虑全这几种情况就可以了、
一开始用了boolean的二维数组 内存超限了。因为有些场景永远是不可能访问到的，用了set节约了空间。注意queue的长度大小。已经搜索过了就不要再次放入队列
### 代码

```java
class Solution {

    class Pair<A, B> {
    public final A fst;
    public final B snd;

    public Pair(A var1, B var2) {
        this.fst = var1;
        this.snd = var2;
    }
public boolean equals(Object var1) {
        return var1 instanceof Pair && Objects.equals(this.fst, ((Pair)var1).fst) && Objects.equals(this.snd, ((Pair)var1).snd);
    }

    public int hashCode() {
        if (this.fst == null) {
            return this.snd == null ? 0 : this.snd.hashCode() + 1;
        } else {
            return this.snd == null ? this.fst.hashCode() + 2 : this.fst.hashCode() * 17 + this.snd.hashCode();
        }
    }
    }
    
    Set<Pair> table = new HashSet<>();
    Queue<Pair> queue = new ArrayDeque<>();

    public boolean canMeasureWater(int x, int y, int z) {

        if (z > x + y) {
            return false;
        }

        if (x < y) {
            int t = x;
            x = y;
            y = t;
        }

        if (z == x || z == y || z == x - y || z == x + y) {
            return true;
        }

        queue.offer(new Pair(0,y));
        queue.offer(new Pair(x, 0));
        queue.offer(new Pair(0,0));
        Pair<Integer,Integer> top ;

        while((top = queue.poll()) != null){
            if (table.contains(top) ) {
                continue;
            }
            table.add(top);
            if (top.fst + top.snd == z) {
                return true;
            }
            //找出当前可能的所有操作
            /**
             * 导入水 共两种情况
             *  导入 x 是否满了
             *  导入 y 是否满了
             */

            int tmpx = Math.min(top.fst + x, x);
            enQueue(tmpx, top.snd);

            int tmpy = Math.min(top.snd + y , y);
            enQueue(top.fst, tmpy);

            //不导入水， 直接清空一个杯子
            int curX = top.fst;
            int curY = top.snd;

            enQueue(0, curY);
            enQueue(curX, 0);
            /**
             * 不导入水， 两杯水互相导。
             *
             * x --> y
             *
             *        y没有满
             *        y满了
             *          x剩余的不倒掉
             *          x剩余的倒掉 x为0,在初始情况下就加入队列0,y
             * y --> x
             *         同理
             */

            //x导入y的逻辑

            int curSum = curX + curY;
            if (curSum <= y) {
                enQueue(0, curSum);
            } else {
                int nextX = curSum - y;
                enQueue(nextX, y);
            }

            //y导入x的逻辑

            if (curSum <=x) {
                enQueue(curSum, 0);
            }else  {
                int nextY = curSum -x;
                enQueue(x, nextY);
            }
        }

        return false;
    }


    private void enQueue(int x, int y) {

        if (table.contains(new Pair(x, y))) {
            return;
        }

        queue.offer(new Pair(x, y));
    }
}
```