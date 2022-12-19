```
public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        int len = Profits.length;
        int[][] cp = new int[len][2];
               
        for(int i=0 ; i<len ; i++){
            cp[i] = new int[]{Capital[i],Profits[i]};
        }
        
        Arrays.sort(cp,(a,b)->a[0]-b[0]);
        
        int index = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        while(k>0){
            while(index<len && cp[index][0]<=W){
                pq.offer(cp[index][1]);
                index++;
            }
            if(pq.isEmpty()) return W;
            W += pq.poll();
            k--;
        }
        
        return W;        
    }
```
