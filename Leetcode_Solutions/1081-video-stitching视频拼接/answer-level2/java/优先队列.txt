java 3ms 
```
    public int videoStitching(int[][] clips, int T) {
        Comparator<int[] > c = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0]!=o2[0]){
                    return o1[0]-o2[0];
                }else{
                    return o2[1]-o1[1];
                }
            }
        };
        int ans = 0;
        PriorityQueue<int[]> p = new PriorityQueue<>(c);
        for(int i=0;i<clips.length;i++){
            p.add(clips[i]);
        }
        int cur = 0;
        int next = 0;
        while(next<T&&!p.isEmpty()&&next>=p.peek()[0]){
            cur = next;
            ans ++;
            while(!p.isEmpty()&&p.peek()[0]<=cur){
                next = Math.max(next,p.poll()[1]);
            }
        }
        if(next<T){
            return -1;
        }else{
            return ans;
        }
    }
```