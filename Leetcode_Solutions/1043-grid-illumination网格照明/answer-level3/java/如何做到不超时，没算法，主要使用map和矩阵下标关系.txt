### 解题思路
此处撰写解题思路
代码写的有点挫哈
搞了几次都超时，主要关注N的取值很大，两个数组也不小，20000
1 <= N <= 10^9
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
所以八个方向一个个比较肯定会超时

因此，先遍历一遍亮灯的数组，把亮着的灯加入亮灯map，每盏灯对应的横、竖、斜线，反斜线的贡献累加到对应map
然后遍历查询数组，判断当前位置是否亮灯，这个判断是关键，就这里会超时，只要横、竖、斜线、反斜线任一大于0，则亮灯
然后把当前位置+八个方向的位置的等关掉，关闭即把灯从亮灯map移除，同时把横、竖、斜线、反斜线map值减一

最后得到的就是结果

### 代码

```java
class Solution {
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        int[] result = new int[queries.length];
        if(lamps.length == 0 || queries.length == 0){
            return result;
        }
        int[][] direction = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        List<int[]> lampsList = new ArrayList<int[]>(Arrays.asList(lamps));
        Map<String, int[]> mem = new HashMap<String, int[]>();
        Map<Integer, Integer> rowMap = new HashMap<Integer, Integer>();
        Map<Integer, Integer> colMap = new HashMap<Integer, Integer>();
        Map<Integer, Integer> xieMap = new HashMap<Integer, Integer>();
        Map<Integer, Integer> fanxieMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < lampsList.size(); i++){
            int x = lampsList.get(i)[0];
            int y = lampsList.get(i)[1];
            String key = x + "_" + y;
            mem.put(key, lampsList.get(i));
            if(!rowMap.containsKey(x)){
                rowMap.put(x, 1);
            }
            else{
                rowMap.put(x, rowMap.get(x) + 1);
            }

            if(!colMap.containsKey(y)){
                colMap.put(y, 1);
            }
            else{
                colMap.put(y, colMap.get(y) + 1);
            }

            int sum = x + y;
            if(!xieMap.containsKey(sum)){
                xieMap.put(sum, 1);
            }
            else{
                xieMap.put(sum, xieMap.get(sum) + 1);
            }

            int cha = x - y;
            if(!fanxieMap.containsKey(cha)){
                fanxieMap.put(cha, 1);
            }
            else{
                fanxieMap.put(cha, fanxieMap.get(cha) + 1);
            }
        }
        for(int i = 0; i < queries.length; i++){
            if(lightResult(mem, rowMap, colMap, xieMap, fanxieMap, queries[i])){
                result[i] = 1;
            }
            removeLightAround(queries[i], direction, N, mem, rowMap, colMap, xieMap, fanxieMap);
        }
        return result;
    }

    private void removeLightAround(int[] query, int[][] direction, int n, Map<String, int[]> mem,
                                   Map<Integer, Integer> rowMap, Map<Integer, Integer> colMap,
                                   Map<Integer, Integer> xieMap, Map<Integer, Integer> fanxieMap) {
        if(mem.isEmpty()){
            return;
        }
        String key = query[0] + "_" + query[1];
        if(mem.containsKey(key)){
            mem.remove(key);
            rowMap.put(query[0], rowMap.get(query[0]) - 1);
            colMap.put(query[1], colMap.get(query[1]) - 1);
            int sum = query[0] + query[1];
            xieMap.put(sum, xieMap.get(sum) - 1);
            int cha = query[0] - query[1];
            fanxieMap.put(cha, fanxieMap.get(cha) - 1);
        }

        for(int j = 0; j < direction.length; j++){
            int[] pos = new int[] {query[0] + direction[j][0], query[1] + direction[j][1]};
            if(pos[0] >= 0 && pos[0] < n && pos[1] >= 0 && pos[1] < n){
                key = pos[0] + "_" + pos[1];
                if(mem.containsKey(key)){
                    mem.remove(key);
                    rowMap.put(pos[0], rowMap.get(pos[0]) - 1);
                    colMap.put(pos[1], colMap.get(pos[1]) - 1);
                    int sum = pos[0] + pos[1];
                    xieMap.put(sum, xieMap.get(sum) - 1);
                    int cha = pos[0] - pos[1];
                    fanxieMap.put(cha, fanxieMap.get(cha) - 1);
                }
            }
        }
    }

    private boolean lightResult(Map<String, int[]> mem, Map<Integer, Integer> rowMap, Map<Integer, Integer> colMap,
                                Map<Integer, Integer> xieMap, Map<Integer, Integer> fanxieMap, int[] query) {
        if(mem.isEmpty()){
            return false;
        }
        if(rowMap.containsKey(query[0]) && rowMap.get(query[0]) > 0){
            return true;
        }
        if(colMap.containsKey(query[1]) && colMap.get(query[1]) > 0){
            return true;
        }
        int sum = query[0] + query[1];
        if(xieMap.containsKey(sum) && xieMap.get(sum) > 0){
            return true;
        }
        int cha = query[0] - query[1];
        if(fanxieMap.containsKey(cha) && fanxieMap.get(cha) > 0){
            return true;
        }
        return false;
    }
}
```