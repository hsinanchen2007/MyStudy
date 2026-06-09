```
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int[][] job = new int[difficulty.length][2];
        for(int i = 0 ;i<difficulty.length;i++){
            job[i][0] = difficulty[i];
            job[i][1] = profit[i];
        }
        Arrays.sort(job,new Comparator<int[]>(){ //快排按照工作难度升序
            @Override
            public int compare(int[] first,int[] second){
                if(first[0]==second[0]) return second[1]-first[1];
                return first[0]-second[0]; 
            }
        });
        int ans = 0 ;
        for(int i = 1;i<job.length;i++){  //将最大收益更新  可以做当前难度工作也可以做比当前难度更小难度的工作 取收益最大值
            job[i][1] = Math.max(job[i-1][1],job[i][1]);
        }
        /*TreeMap<Integer,Integer> table = new TreeMap<>(); //TreeMap 有现成的floor方法也可以用
        for(int i = 0;i<job.length;i++)
            table.put(job[i][0],job[i][1]);
        for(int i = 0;i<worker.length;i++){
            Integer temp = table.floorKey(worker[i]);
            if(temp!=null)
                ans +=table.get(temp);
        }*/
        for(int i = 0;i<worker.length;i++){  //二分查找小于等于该工作难度的最大难度对应的工作
            int left = 0,right = job.length-1;
            while(left<=right){
                int mid = (left+right)>>1;
                if(job[mid][0]>worker[i]){
                    right = mid-1;
                }else 
                    left = mid +1;
                }
                ans +=(right==(-1)?0:job[right][1]);
            }  
        return ans;
    }
}
```
