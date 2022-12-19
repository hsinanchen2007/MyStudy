由于灯是区间1-n的排列，当区间内的最大值等于区间长度，则区间内的灯一定全部变蓝
使用一个优先级队列来保存当前区间的最大值，或者直接使用一个max变量均可
```
public int numTimesAllBlue(int[] light) {
        PriorityQueue<Integer> q=new PriorityQueue<>();
        int res=0;
        for(int i:light){
            q.add(-i);
            if(q.size()==-q.peek()) res++;
        }
        return res;
}
```
