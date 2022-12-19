将hel设置为较大的桶，之后进入while循环，获得所有状态。
如果hel大于较小的桶，则hel减去较小桶的水量。
如果hel小于较小的桶，则hel加上最大桶的水量。
与纯粹的数学做法相比，时间空间消耗都会多很多，但是能AC。
```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x+y==z || z==0)
            return true;
        if (x+y<z)
            return false;
        if (x==y)
            return x==z;
        //保证y>x
        if (x>y){
            int c = x;
            x = y;
            y = c;
        }
        Map<Integer,Integer> map = new HashMap();
        int hel = y;
        while (!map.containsKey(hel)){
            map.put(hel, 1);
            if (hel<x)
                hel += y;
            else
                hel -= x;
            if (hel == z)
                return true;
        }
        return false;
    }
}
```
