Java ac代码：
```
class Solution {
    public int countComponents(int n, int[][] edges) {
        
        int ans = 0;
        int[]set = new int[n];
        for(int i = 0;i < n;i++)
            set[i] = i;
        for(int[]edge : edges){
            int v1 = edge[0],v2 = edge[1];
            addSet(set,v1,v2);
        }
        for(int v = 0;v < n;v++)
            if(findRoot(set,v) == v)
                ans++;
        return ans;
    }
    
    void addSet(int[]set,int i,int j){
        int f1 = findRoot(set,i);
        int f2 = findRoot(set,j);
        if(f1 < f2)
            set[f2] = f1;
        else
            set[f1] = f2;
    }
    int findRoot(int[]set,int i){
        if(i == set[i])return i;
        return set[i] = findRoot(set,set[i]);
    }
  
}
```
