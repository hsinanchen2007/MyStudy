```
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        
        int len = intervals.length;
        if(len == 0){//快判
            return 0;
        }
        
        Intervals[] arr = new Intervals[len];
        
        for(int i = 0;i<len;i++){
            arr[i] = new Intervals(intervals[i]);//二维数组转对象
        }
        
        PriorityQueue<Integer> queue = new PriorityQueue<>(len,new Comparator<Integer>(){
            @Override
            public int compare(Integer o1, Integer o2){
                return o1-o2;//小顶堆
            }
        });
        
        Arrays.sort(arr,new Comparator<Intervals>(){
            @Override
            public int compare(Intervals o1,Intervals o2){
                return o1.getStart() - o2.getStart();
            }
        }); //按开始时间排序
        
        queue.add(arr[0].getEnd());
        
        for(int i = 1;i<len;i++){
            if(arr[i].getStart() >= queue.peek()){//开始时间不超过最早结束的时间,可以用现成的会议室,在堆元素数不变的情况下更新结束时间
                queue.poll();
            }
            queue.add(arr[i].getEnd());//不断向堆添加结束时间(或保持对元素数量不变但更新结束时间),其堆顶保存了最早的结束时间
        }
        return queue.size();
        
    }
    
    private class Intervals {//定义一个类似Pair的对象
        private int start;
        private int end;
        public Intervals(int[] input){
            start = input[0];
            end = input[1];
        }
        
        public int getStart(){
            return start;
        }
        
        public int getEnd(){
            return end;
        }
    }
    
}
```
