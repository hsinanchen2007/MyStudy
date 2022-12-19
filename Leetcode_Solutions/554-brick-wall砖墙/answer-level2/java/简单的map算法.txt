### 解题思路
1.将每行的砖块列表转化为缝隙的位置列表，并删除尾部元素。例如：{1,2,2,1}->{1,3,5}；
2.问题转化为从多个列表中查找频次最多的数字；
3.将每个数字与其出现的次数存入map;
4.轻松从map中得到频次最大的数字，使用墙的高度减去缝隙最大次数得到穿过砖块数量。

### 代码

```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int mostCracks = 0;
        Map<Integer, Integer> cracks = new HashMap<>();
        for (List<Integer> bricks : wall) {
            for (int i = 0; i < bricks.size() - 1; i++) {
                if (i != 0) {
                    bricks.set(i, bricks.get(i -1) + bricks.get(i));
                }
                if (cracks.containsKey(bricks.get(i))) {
                    cracks.put(bricks.get(i), cracks.get(bricks.get(i)) + 1);
                } else {
                    cracks.put(bricks.get(i), 1);
                }
                mostCracks = Math.max(cracks.get(bricks.get(i)), mostCracks);
            }
        }
        return wall.size() - mostCracks;
    }
}
```