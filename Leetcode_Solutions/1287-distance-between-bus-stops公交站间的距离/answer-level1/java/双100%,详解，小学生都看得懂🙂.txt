![image.png](https://pic.leetcode-cn.com/b4254e2be1365c7ef75ed6478feff4811b696ebed7f8a8fb846213ef9e310db2-image.png)


```
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        //SUM记录全路线路程
        int SUM = 0;
        for (int i = 0; i < distance.length; i++){
            SUM += distance[i];
        }
       //指定一个方向，那就是从角标小的站台去角标大的站台。利用Math.min()和Math.max()
        int s = start;
        int d = destination;
        start = Math.min(s,d);
        destination = Math.max(s,d);
        
        //选定了方向则算路程，start到destination，sum记录路程。
        int sum = 0;
        for (int i = start; i < destination; i++){
            sum += distance[i];
        }
        
        //返回其中更小的即是答案。
        return Math.min(sum,SUM-sum);
    }
}
```
