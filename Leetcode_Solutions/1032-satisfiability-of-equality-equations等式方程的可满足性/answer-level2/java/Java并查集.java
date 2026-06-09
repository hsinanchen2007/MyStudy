```
class Solution {
    
    static class DSU {
        int[] parent;
        
        DSU(int len) {
            parent = new int[len];
            for(int i = 0; i < len; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void union(int x, int y) {
            parent[find(x)] = find(y);
        }
    }
    
    public boolean equationsPossible(String[] equations) {
        DSU dsu = new DSU(26);
        List<int[]> list = new ArrayList();
        
        for(String e : equations) {
            char x = e.charAt(0);;
            char y = e.charAt(e.length() - 1);
            String exp = e.substring(1, e.length() - 1);
            
            if (exp.equals("==")) {
                dsu.union(x - 'a', y - 'a');
            } else {
                list.add(new int[] {x - 'a', y - 'a'});
            }
        }
        
        for(int[] arr : list) {
            if (dsu.find(arr[0]) == dsu.find(arr[1])) {
                return false;
            }
        }
        
        return true;
    }
}
```
