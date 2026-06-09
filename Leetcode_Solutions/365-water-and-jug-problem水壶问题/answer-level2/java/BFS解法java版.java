### 解题思路
和其他题解的bfs思路一样，六种壶操作那里和官方一样

### 代码

```java
class Solution {
    /*不能用数组作为Set中的泛型类型,但可以用List。因为分两次new的两个数组中值相同但Set会把它们看作不同，
    但分两次new的两个ArrayList中值相同Set会把它们看成同一个*/
    Queue<List<Integer>> queue;
    Set<List<Integer>> set;
    public boolean canMeasureWater(int x, int y, int z) {
        if(z==0)
            return true;
        if(x+y<z)
            return false;
        queue=new LinkedList<>();
        set=new HashSet<>();
        /*用new的时候直接初始化，泛型必须后面也必须写完整类型，
        * 即new ArrayList<Integer>(){{add(0);add(0);}};*/
        List<Integer> start=new ArrayList<Integer>(){{add(0);add(0);}};
        queue.offer(start);
        set.add(start);
        while(!queue.isEmpty()){
            List<Integer> t=queue.poll();
            int curX=t.get(0);
            int curY=t.get(1);
            if(curX==z||curY==z||curX+curY==z)
                return true;
            //把第一个壶倒满
            addQueue(x,curY);
            //把第二个壶倒满
            addQueue(curX,y);
            //把第一个壶倒空
            addQueue(0,curY);
            //把第二个壶倒空
            addQueue(curX,0);
            //把第一个壶中的水倒入第二个壶中，倒空或倒满
            addQueue(curX-Math.min(curX,y-curY),curY+Math.min(curX,y-curY));
            //把第二个壶中的水倒入第一个壶中，倒空或倒满
            addQueue(curX+Math.min(curY,x-curX),curY-Math.min(curY,x-curX));
        }
        return false;
    }
    private void addQueue(int x,int y){
        List<Integer> t=new ArrayList<Integer>(){{add(x);add(y);}};
        if(!set.contains(t)){
            set.add(t);
            queue.offer(t);
        }
    }
}
```