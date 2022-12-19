```
class Solution {
    
    private static final int len = 1000000;
    
    private int[][] directions = new int[][] {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    private boolean checkPath(int[][] blocked, int[] source, int[] target) {
        Set<String> blockSet = new HashSet();
        for(int[] block : blocked) {
            blockSet.add(block[0] + "#" + block[1]);
        }
        
        Set<String> visited = new HashSet();
        Queue<String> queue = new LinkedList();
        String key = source[0] + "#" + source[1];
        queue.offer(key);
        visited.add(key);
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            if (size > blocked.length) {
                return true;
            }
            
            for(int i = 0; i < size; i++) {
                String[] arr = queue.poll().split("#");
                int x = Integer.parseInt(arr[0]);
                int y = Integer.parseInt(arr[1]);
                
                for(int[] d : directions) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (nx < 0 || nx >= len || ny < 0 || ny >= len) {
                        continue;   
                    }
                    if (nx == target[0] && ny == target[1]) {
                        return true;
                    }
                    
                    String nKey = nx + "#" + ny;
                    if (visited.contains(nKey) || blockSet.contains(nKey)) {
                        continue;
                    }
                    
                    visited.add(nKey);
                    queue.offer(nKey);
                }
            }
        }
        
        return false;
    }
    
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        return checkPath(blocked, source, target) && checkPath(blocked, target, source);
    }
}
```
