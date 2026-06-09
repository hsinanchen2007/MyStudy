### 解题思路
当第n天时,在n天开始的时间段里优先选择结束时间最短的那个时间段,来作为当天参加的会议

### 代码

```java
class Solution {
    public int maxEvents(int[][] events) {
        // 会议按照开始时间排序
        Arrays.sort(events,(e1,e2)->Integer.compare(e1[0],e2[0]));
         // 优先队列按照结束时间排序
        PriorityQueue<int[]> q=new PriorityQueue<>((e1,e2)->Integer.compare(e1[1],e2[1]));
        int day=1;
        int i=0;
        int cout=0;
        while(i<events.length||!q.isEmpty()){
        // 模拟第 d 天的决策
        // 将已经开始的会议加入队列
        while(i<events.length&&events[i][0]==day){
            q.add(events[i]);
            i++;
        }
        while(!q.isEmpty()){
        // 把最早结束的会议拿出来
            int[] a=q.poll();
            if(a[1]>=day){
            cout++;
            //一天一个会议
            break;
            }
        }
        day++;
        }
        return cout;
    }
}
```