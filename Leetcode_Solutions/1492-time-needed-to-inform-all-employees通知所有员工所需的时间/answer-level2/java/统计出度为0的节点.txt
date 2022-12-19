```
public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {               
        List<Integer> leafs = new ArrayList<>();
        for(int i =0;i<n;i++){
            if(informTime[i] == 0) leafs.add(i);
        }
        int[] times = new int[leafs.size()];
        int count = 0;
        for(int leaf:leafs){
            leaf = manager[leaf];
            while (leaf != -1){
                times[count] += informTime[leaf];
                leaf = manager[leaf];
            }
            count++;
        }
        return Arrays.stream(times).max().getAsInt();
}
```
