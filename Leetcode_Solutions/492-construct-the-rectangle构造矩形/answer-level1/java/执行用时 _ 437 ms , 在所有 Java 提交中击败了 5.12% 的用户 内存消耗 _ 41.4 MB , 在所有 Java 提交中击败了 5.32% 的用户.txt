### 解题思路
本题实际上是求解针对一个固定的整数，计算有多少种整数相乘可以得到该整数，且必须能够整除，加入限制条件后，我们很容易想到利用map集合中的键和对应的值来存储长和宽，并随后遍历该集合，不断计算长和宽的差，找到差距最小的一组，并把它输出。

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
        if(area == 1) {
            return new int[]{1,1};
        }
        int w = 0;
        int l = 0;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(l = 1;l<=area;l++) {
            if(area%l==0 && l>=area/l) {
                w = area/l;
                map.put(l,w);
            }
        }
        int[] arr = new int[2];
        int count = area;
        Set<Integer> set = map.keySet();
        for(Integer i:set) {
            if(count>=Math.abs(i-map.get(i))) {
                arr[0] = i;
                arr[1] = map.get(i);
                count = Math.abs(i-map.get(i));
            }
        }
        return arr;
    }
}
```