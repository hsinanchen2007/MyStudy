我们发现canMeasureWater(x, y, z)的问题可以转化为
canMeasureWater(x, y, |x - z|) || canMeasureWater(x, y, |y - z|)的问题。
如此进行BFS，只要出现z == x || z == y || z == Math.abs(x - y) || z == (x + y 就说明找到了。
递归停止条件应该为当所有重复的z都执行了一次，因此使用一个HashSet了去重
```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x + y){
            return false;
        }
        Set<Integer> set = new HashSet<>();
        return process(x, y, z, set);
    }
    public boolean process(int x, int y, int z, Set<Integer> set){
        if(set.contains(z)){
            return false;
        }
        if(z == x || z == y || z == Math.abs(x - y) || z == (x + y)){
            return true;
        }
        set.add(z);
        return process(x, y, Math.abs(x - z), set) || process(x, y, Math.abs(y - z), set);
    }
}
```
代码看起来及其简单，但是性能很差
执行用时 :
76 ms
, 在所有 Java 提交中击败了
13.92%
的用户
内存消耗 :
598.7 MB
, 在所有 Java 提交中击败了
5.06%
的用户
