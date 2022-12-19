执行用时 : 109 ms, 在所有 java 提交中击败了94.44%的用户
内存消耗 : 62.7 MB, 在所有 java 提交中击败了100.00%的用户

```
class Solution {
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        int[] result = new int[queries.length];
        int index = 0;
        Map<Integer,Integer> rowMap = new HashMap<>(lamps.length);
        Map<Integer,Integer> cowMap = new HashMap<>(lamps.length);
        Map<Integer,Integer> leftMap = new HashMap<>(lamps.length);
        Map<Integer,Integer> rightMap = new HashMap<>(lamps.length);
        Set<Integer> sets = new HashSet<>();
        for (int[] la : lamps){
            rowMap.put(la[1],rowMap.containsKey(la[1]) ? rowMap.get(la[1]) + 1 : 1);
            cowMap.put(la[0],cowMap.containsKey(la[0]) ? cowMap.get(la[0]) + 1 : 1);
            int leftPoint = la[0] - la[1];
            leftMap.put(leftPoint,leftMap.containsKey(leftPoint) ? leftMap.get(leftPoint) + 1 : 1);
            int rightPoint = la[0] + la[1];
            rightMap.put(rightPoint,rightMap.containsKey(rightPoint) ? rightMap.get(rightPoint) + 1 : 1);
            sets.add(N * la[0] + la[1]);
        }
        for (int[] qu : queries){
            if ((rowMap.containsKey(qu[1]) && rowMap.get(qu[1]) > 0) ||
                (cowMap.containsKey(qu[0]) && cowMap.get(qu[0]) > 0) ||
                (leftMap.containsKey(qu[0] - qu[1]) && leftMap.get(qu[0] - qu[1]) > 0) ||
                (rightMap.containsKey(qu[0] + qu[1]) && rightMap.get(qu[0] + qu[1]) > 0)){
                // 灯照范围内, 关周围的灯
                for (int x = -1; x < 2; x++){
                    for (int y = -1; y < 2; y++){
                        int[] handlePoint = new int[]{qu[0] + x, qu[1] + y};
                        if (!(handlePoint[0] < 0 || handlePoint[0] >= N || handlePoint[1] < 0 || handlePoint[1] >= N)){
                            // 处在网格内
                            Integer handlePointNum = N * handlePoint[0] + handlePoint[1];
                            if (sets.contains(handlePointNum)){
                                sets.remove(handlePointNum);
                                // 如果是要关的灯,则移除其光照路径
                                rowMap.put(handlePoint[1],rowMap.get(handlePoint[1]) - 1);
                                cowMap.put(handlePoint[0],cowMap.get(handlePoint[0]) - 1);
                                leftMap.put(handlePoint[0] - handlePoint[1],leftMap.get(handlePoint[0] - handlePoint[1]) - 1);
                                rightMap.put(handlePoint[0] + handlePoint[1], rightMap.get(handlePoint[0] + handlePoint[1]) - 1);
                            }
                        }
                    }
                }
                result[index++] = 1;
            }else{
                result[index++] = 0;
            }
        }
        return result;
    }
}
```