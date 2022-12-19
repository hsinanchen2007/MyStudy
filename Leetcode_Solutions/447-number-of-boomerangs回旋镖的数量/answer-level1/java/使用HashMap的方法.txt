尝试把每一个点都当做第一个点，然后计算与其它点的距离，并保存在hashMap中，若计算出的距离在hashMap中已有值，则表明之前有相同的距离，累加到count，由于可以换位，则乘以2.当前点作为第一个点结束之后，清空hashMap，继续以下一个点作为第一个点。
```
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        HashMap<Integer,Integer> hashMap = new HashMap<>();
        int count = 0;
        for(int i = 0;i < points.length;i++){
            hashMap.clear();
            for(int j = 0;j < points.length;j++){
                if(i == j){
                    continue;
                }
                int distance = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                count += hashMap.getOrDefault(distance,0)*2;
                hashMap.put(distance,hashMap.getOrDefault(distance,0) + 1);
            }
        }
        return count;
    }
}
```
