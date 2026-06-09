执行用时 :7 ms, 在所有 Java 提交中击败了87.14%的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了50.77%的用户

先按照区间起始数排序建立最小堆，然后就可以逐一合并

```
class Solution {
    public int[][] merge(int[][] intervals) {
        int len = intervals.length;
        if(len<=1){
            return intervals;
        }else{
            Queue<Area> queue = new PriorityQueue<Area>(new Comparator<Area>() {
                @Override
                public int compare(Area a1, Area a2) {
                    Integer i = a1.bgn;
                    Integer j = a2.bgn;
                    return i.compareTo(j);
                }
            });
            for (int j = 0; j < len; j++) {
                queue.offer(new Area(intervals[j]));
            }
            ArrayList<int[]> list = new ArrayList<>();
            Area area = queue.poll();
            while(!queue.isEmpty()){
                Area cur_area = queue.poll();
                if(cur_area.bgn>area.end){
                    addList(list,area);
                    area = cur_area;
                }else{
                    area.bgn = Math.min(area.bgn, cur_area.bgn);
                    area.end = Math.max(area.end, cur_area.end);
                }
            }
            addList(list,area);
            int size = list.size();
            int[][] result = new int[size][2];
            for(int i=0;i<size;i++){
                result[i] = list.get(i);
            }
            return result;
        }
    }
    private void addList(ArrayList<int[]> list, Area area){
        int[] arr = new int[2];
        arr[0]=area.bgn;
        arr[1]=area.end;
        list.add(arr);
    }
    class Area{
        int bgn;
        int end;
        public Area(int[] arr){
            this.bgn = arr[0];
            this.end = arr[1];
        }
    }
}
```
