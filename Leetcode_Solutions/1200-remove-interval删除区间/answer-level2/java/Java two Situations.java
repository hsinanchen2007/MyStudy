```
class Solution {

    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> list=new ArrayList<>();
        int left=toBeRemoved[0],right=toBeRemoved[1];

        for (int i=0;i<intervals.length;i++){
            if (intervals[i][0]<left){
                list.add(Arrays.asList(new Integer[]{intervals[i][0],Math.min(intervals[i][1],left)}));
            }
            if (intervals[i][1]>right){
                list.add(Arrays.asList(new Integer[]{Math.max(intervals[i][0],right),intervals[i][1]}));
            }
        }

        return list;
    }
}
```
