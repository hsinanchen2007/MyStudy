### 解题思路
java BFS和DFS实现

### 代码BFS

```java
class Water{
    int x;
    int y;
    public Water(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Water water = (Water) o;
        return x == water.x &&
                y == water.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return "Water{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}

class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        Water initWater = new Water(0,0);
        HashSet<Water> hashSet = new HashSet<>();
        Deque<Water> deque = new LinkedList<>();
        if(x + y < z)
            return false;
        if(x == z || y == z || x + y == z)
            return true;
        deque.offer(initWater);
        while(!deque.isEmpty()){
            Water pollWater = deque.poll();
            if(pollWater.x == z || pollWater.y == z || pollWater.x+pollWater.y == z)
                return true;
            hashSet.add(pollWater);
            //八个方向逐一判断
            //倒满X
            Water waterFullX = new Water(x, pollWater.y);
            if(!hashSet.contains(waterFullX))
                deque.offer(waterFullX);
            //倒满Y
            Water waterFullY = new Water(pollWater.x, y);
            if(!hashSet.contains(waterFullY))
                deque.offer(waterFullY);
            //清空X
            Water waterXEmpty = new Water(0, pollWater.y);
            if(!hashSet.contains(waterXEmpty))
                deque.offer(waterXEmpty);
            //清空Y
            Water waterYEmpty = new Water(pollWater.x, 0);
            if(!hashSet.contains(waterYEmpty))
                deque.offer(waterYEmpty);

            //将X倒向Y
            int temp = Math.min(pollWater.x, y-pollWater.y);
            Water waterFromXToY = new Water(pollWater.x-temp, pollWater.y+temp);
            if(!hashSet.contains(waterFromXToY))
                deque.offer(waterFromXToY);
            //将Y倒向X
            temp = Math.min(pollWater.y, x-pollWater.x);
            Water waterFromYToX = new Water(pollWater.x+temp, pollWater.y-temp);
            if(!hashSet.contains(waterFromYToX))
                deque.offer(waterFromXToY);
        }
        return false;
    }
}
```

### 代码DFS
注意不能用递归，会出现栈溢出错误
```java
class Water{
    int x;
    int y;
    public Water(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Water water = (Water) o;
        return x == water.x &&
                y == water.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return "Water{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}

class Solution {
    public boolean res = false;
    public boolean canMeasureWater(int x, int y, int z) {
        HashSet<Water> hashSet = new HashSet<>();
        Water waterInit = new Water(0, 0);
        Stack<Water> stack = new Stack<>();
        stack.push(waterInit);
        boolean res = false;
        while(!stack.isEmpty()){
            Water popWater = stack.pop();
            if(popWater.x == z || popWater.y == z || popWater.x + popWater.y == z){
                res = true;
                break;
            }

            if(hashSet.contains(popWater))
                continue;
            hashSet.add(popWater);

            stack.push(new Water(x, popWater.y));
            stack.push(new Water(popWater.x, y));

            stack.add(new Water(0, popWater.y));
            stack.add(new Water(popWater.x, y));

            int temp = Math.min(popWater.x, y-popWater.y);
            stack.add(new Water(popWater.x -temp, popWater.y+temp));

            temp = Math.min(x-popWater.x, popWater.y);
            stack.add(new Water(popWater.x+temp, popWater.y-temp));
        }
        return res;
    }

    //stackOverFlow
     public void dfs(Water water, HashSet<Water> hashSet, int x, int y, int z){
        if(res == true)
            return;
        if(water.x == z || water.y == z || water.x + water.y == z){
            res = true;
            return;
        }
        if(hashSet.contains(water))
            return;
        hashSet.add(water);
        //X灌满
        dfs(new Water(x, water.y), hashSet, x, y, z);
        //Y灌满
        dfs(new Water(water.x, y), hashSet, x, y, z);
        //X倒空
        dfs(new Water(0, water.y), hashSet, x, y, z);
        //Y倒空
        dfs(new Water(water.x, 0), hashSet, x, y, z);
        //将X全部导入Y,直到灌满或倒空
        int temp = Math.min(water.x, y-water.y);
        dfs(new Water(water.x -temp, water.y+temp), hashSet, x, y, z);
        //将Y全部倒入X,直到灌满或倒空
        temp = Math.min(x-water.x, water.y);
        dfs(new Water(water.x+temp, water.y-temp), hashSet, x, y, z);
        return;
    }
}
```