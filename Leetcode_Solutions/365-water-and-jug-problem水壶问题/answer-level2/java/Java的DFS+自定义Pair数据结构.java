官方答案的java版本，自己写了一个Pair的数据结构，重写了equals和hashCode方法。
```
class Solution {
    //深度优先遍历两个水壶所有可能的状态
    public boolean canMeasureWater(int x, int y, int z) {
        Set<Pair> reachable = new HashSet<>();
        Stack<Pair> stack = new Stack<>();
        Pair init = new Pair(0,0);
        stack.push(init);
        while(!stack.isEmpty()){
            Pair cur = stack.pop();
            int remainX = cur.first;
            int remainY = cur.second;
            if(remainX==z || remainY==z || remainX+remainY==z){
                return true;
            }
            if(reachable.contains(cur)){
                continue;
            }
            reachable.add(cur);
            //把x填满
            if(remainX < x){
                stack.push(new Pair(x,remainY));
            }
            //把y填满
            if(remainY < y){
                stack.push(new Pair(remainX,y));
            }
            //清空x
            stack.push(new Pair(0,remainY));
            //清空y
            stack.push(new Pair(remainX,0));
            //把x的倒入到y中，y满或者x空为止
            int acceptableY = y-remainY;
            if(remainX>0 && acceptableY>0){
                if(remainX <= acceptableY){
                    stack.push(new Pair(0,remainY+remainX));
                }else{
                    stack.push(new Pair(remainX-acceptableY,y));
                }
            }
            //把y的倒入到x中,x满或者y空为止
            int acceptableX = x-remainX;
            //如果y中还有水，且x没满
            if(remainY>0 && acceptableX>0){
                if(remainY <= acceptableX){
                    stack.push(new Pair(remainY+remainX,0));
                }else{
                    stack.push(new Pair(x,remainY-acceptableX));
                }
            }
        }
        return false;
    }
}
class Pair{
    int first;
    int second;
    public Pair (int first,int second){
        this.first = first;
        this.second = second;
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return first == pair.first &&
                second == pair.second;
    }
    @Override
    public int hashCode() {
        return Objects.hash(first)+Objects.hash(second);
    }
}
```
