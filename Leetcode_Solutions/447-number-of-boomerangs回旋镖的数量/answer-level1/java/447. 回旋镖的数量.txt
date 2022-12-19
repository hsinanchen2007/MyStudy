/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/15
 *
 * 解题思路: 排列组合的使用 
 * 
 * 将当前点作为第一个点，计算与非当前点的距离，保存在hashMap中，若计算距离距离在hashMap中已有值，则表明之前有相同的距离，res，因为可以换位，则乘以2，并更新到当前hash中（可以与当前距离相同
 * 的任意一个点交换位置）.当前点作为第一个点结束之后，清空hashMap，继续以下一个点作为第一个点。
 *
 */

```
public int numberOfBoomerangs(int[][] points) {
    int res = 0;
    HashMap<Integer,Integer> hashMap= new HashMap<>();
    for(int i = 0;i < points.length;i++){
        hashMap.clear();
        for(int j = 0;j < points.length;j++){
            if(i == j){
                continue;
            }
            int d =  (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
            if(hashMap.containsKey(d)){
                res += hashMap.get(d) * 2;               
                hashMap.put(d, hashMap.get(d) + 1);
            }else{
                hashMap.put(d,1);
            }
        }
    }
}
```