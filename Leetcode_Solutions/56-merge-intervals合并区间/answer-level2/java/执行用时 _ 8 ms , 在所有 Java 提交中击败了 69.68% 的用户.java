### 解题思路
1、升序排列
2、排除intervals为null、长度为0、长度为1的情况
3、本题分为三种情况：第一种是intervals[i][1] < intervals[i+1][0]，直接把数对加入list
                   第二种是intervals[i][1] > intervals[i+1][1]，将intervals[i+1][0]的值改为intervals[i][1]，intervals[i + 1][1]改为intervals[i][1];
                   第三种是intervals[i][1] <= intervals[i+1][1] 并且intervals[i][1] >= intervals[i+1][0]，将intervals[i + 1][0]的值改为intervals[i][0];

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> list= new ArrayList<>();
        if(intervals == null || intervals.length == 0){
            return list.toArray(new int[0][]);
        } 
        if(intervals.length == 1){
            list.add(new int[]{intervals[0][0],intervals[0][1]});
             return list.toArray(new int[0][]);
        } 
        //升序排列
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[0] == o2[0]) return o1[1] - o2[1];
                return o1[0] - o2[0];
            }
        });
        for(int i = 0; i < intervals.length - 1; i++){
            if(intervals[i][1] < intervals[i+1][0]){
                list.add(new int[]{intervals[i][0],intervals[i][1]});
            }else if(intervals[i][1] > intervals[i+1][1]){
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = intervals[i][1];
            }else{
                intervals[i + 1][0] = intervals[i][0];
            }
            if(i == intervals.length - 2){
                list.add(new int[]{intervals[i+1][0],intervals[i+1][1]});
            }
        }
        return list.toArray(new int[0][]);
    }
}
```