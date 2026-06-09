```递归（stack） []
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x==0 || y==0) return z == 0|| x+y == z;
        Stack<Pair<Integer,Integer>> stack = new Stack<>();
        Set<Pair<Integer,Integer>> set = new HashSet<>();
        stack.push(new Pair<>(0,0));
        while(!stack.isEmpty()){
            Pair<Integer,Integer> pair = stack.pop();
            int x_ = pair.getKey().intValue(), y_ = pair.getValue().intValue();
            if(x_ == z || y_ == z || x_+y_ == z) return true;
            if(set.contains(pair)) continue;
            set.add(pair);
            stack.push(new Pair<>(x,y_));
            stack.push(new Pair<>(x_,y));
            stack.push(new Pair<>(0,y_));
            stack.push(new Pair<>(x_,0));
            stack.push(new Pair<>((x_+y_)%y,Math.min(x_+y_,y)));
            stack.push(new Pair<>(Math.min(x,x_+y_),(x_+y_)%x));
        }
        return false;
    }
}
```
```gcd []
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x+y <z) return false;
        if(x == 0 || y==0) return z==0 || x+y==z;
        return z % gcd(x,y) == 0;
    }

    int gcd(int x, int y){
        if(y==0) return x;
        return gcd(y, x%y);
    }
}
```
