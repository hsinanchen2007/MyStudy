```
class Solution {
    int[] parent;
    public boolean validTree(int n, int[][] edges) {
        parent = new int[n];
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int[] edge: edges)
        {
            int x = find(edge[0]);
            int y = find(edge[1]);
            if(x == y)
                return false;
            parent[x] = y;
        }
        int father = find(0);
        for(int i = 0; i < n; i++)
        {
            if(find(i) != father)
                return false;
        }
        return true;
    }
    public int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
}
```
