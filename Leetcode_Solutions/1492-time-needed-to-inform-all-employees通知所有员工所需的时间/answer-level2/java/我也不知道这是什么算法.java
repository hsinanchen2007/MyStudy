```
public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int maxDepth = 0;
        int t=0;
        for(int i=0;i<n;i++){
            int dep=0;
            int ma=manager[i];
            while(ma!=-1){
                dep=dep+informTime[ma];
                ma=manager[ma];
            }
            maxDepth=Math.max(dep,maxDepth);
        }


        return maxDepth;
    }
```
