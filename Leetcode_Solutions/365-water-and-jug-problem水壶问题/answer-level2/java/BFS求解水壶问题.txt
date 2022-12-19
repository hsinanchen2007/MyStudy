### 解题思路
明确状态
防止无休止的搜索下去，用set去重

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        //DFS: 六种操作
        //x清空，x加满，y清空，y加满，x倒入y至其满或者x空，y倒入x至其满或者y空
        //z = x装的水 或者 y装的水 或者 x和y水的总和
        HashSet<state> hs = new HashSet<state>();
        Deque<state> queue = new LinkedList<state>();
        state initialstate = new state(0,0);
        queue.offerLast(initialstate);

        while(queue.size() > 0){
            state s = queue.pollFirst();
            int nowx = s.getX();
            int nowy = s.getY();
            if(nowx == z || nowy == z || nowx+nowy == z){
                return true;
            }
            if(hs.contains(s)){
                continue;
            }else{
                hs.add(s);
            }
            //x清空
            int newx = 0;
            int newy = nowy;
            queue.offerLast(new state(newx,newy));
            //y清空
            newx = nowx;
            newy = 0;
            queue.offerLast(new state(newx,newy));
            //x加满
            newx = x;
            newy = nowy;
            queue.offerLast(new state(newx,newy));
            //y加满
            newx = nowx;
            newy = y;
            queue.offerLast(new state(newx,newy));
            //x清空
            newx = 0;
            newy = nowy;
            queue.offerLast(new state(newx,newy));
            //x倒入y
            int yleft = y - nowy;//y剩余的容量
            if(nowx >= yleft){//x的现有水量大于y剩余的容量
                newy = y;
                newx = nowx - yleft;
            }else{
                newx = 0;
                newy = nowy + nowx;
            }
            queue.offerLast(new state(newx,newy));
            //y倒入x
            int xleft = x - nowx;//x剩余的容量
            if(nowy >= xleft){//y的现有水量大于x剩余的容量
                newy = nowy - xleft;
                newx = x;
            }else{//y的现有水量小于x剩余的容量
                newx = nowx + nowy;
                newy = 0;
            }
            queue.offerLast(new state(newx,newy));
        }
        return false;
    }
}

class state {
    private int x;
    private int y;
    public state(int newx, int newy){
        this.x = newx;
        this.y = newy;
    }
    public int getX(){
        return this.x;
    }
    public int getY(){
        return this.y;
    }
    @Override
    public int hashCode() {
        return this.x + this.y * 37;
    }
    public boolean equals(Object obj) {
        if (!(obj instanceof state)) {
            return false;
        }
        state s = (state) obj;
        return this.x == s.x && this.y == s.y;
    }

}
```