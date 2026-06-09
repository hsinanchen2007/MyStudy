虽然很慢，但代码比较短的广度优先搜索（手动狗头）

```
class Solution {
    HashSet<Integer> hs = new HashSet();
    public boolean canMeasureWater(int x, int y, int z) {
        if(z < 0 || z > (x + y) ||hs.contains(z)){
            return false;
        }else if(z == x || z == y){
            return true;
        }else{
            hs.add(z);
            return canMeasureWater(x,y, y - z) || canMeasureWater(x,y, x - z) ||canMeasureWater(x,y, z - x) || canMeasureWater(x,y, z - y);
        }
    }
}
```

