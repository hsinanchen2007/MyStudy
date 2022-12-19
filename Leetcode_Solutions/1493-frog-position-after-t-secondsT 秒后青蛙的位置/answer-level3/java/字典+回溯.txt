用时大概7ms，内存41m，算是空间换时间把。感觉可能还有优化空间，有想法的欢迎留言指教

```java
class Solution {
    
    public double frogPosition(int n, int[][] edges, int t, int target) {
        boolean[] status = new boolean[n];
        Map<Integer, List<Integer>> map = new HashMap<>(n);
        Map<Integer, Integer> parents = new HashMap<>();
        
        status[0] = true;
        resolveTree(map, parents, status, edges, 1, target);
        
        
        int[] r = flashBack(t, target, map, parents);
        if (r == null) {
            return 0;
        }
        if (r[0] < t) {
            List<Integer> clds = map.get(target);
            if (clds != null) {
                return 0;
            }
        }
        return (double) 1 / r[1];
    }

    private void resolveTree(Map<Integer, List<Integer>> map, Map<Integer, Integer> parents, boolean[] status, int[][]edges, int idx, int target)  {
        List<Integer> list = new ArrayList<>();
        for (int[] e : edges) {
            if (e[0] == idx && !status[e[1] - 1]) {
                list.add(e[1]);
                status[e[1] - 1] = true;
                parents.put(e[1], idx);
                
            } else if (e[1] == idx && !status[e[0] - 1]) {
                list.add(e[0]);
                status[e[0] - 1] = true;
                parents.put(e[0], idx);
                
            }
        }
        
        if (list.size() > 0) {
            map.put(idx, list);
        }
        if (idx == target) {
            return;
        }
        
        for (Integer cld : list) {
            resolveTree(map, parents, status, edges, cld, target);
        }
    }
    
    private int[] flashBack(int maxPath, int target, Map<Integer, List<Integer>> map, Map<Integer, Integer> parents) {
        int[] r = new int[2];
        Integer parent = null;
        int pathCount = 0;
        int c = 1;
        while ((parent = parents.get(target)) != null) {
            pathCount++;
            if (pathCount > maxPath) {
                return null;
            }
            c *= map.get(parent).size();
            target = parent;
        }
        
        r[0] = pathCount;
        r[1] = c;
        return r;
    }
}
```

