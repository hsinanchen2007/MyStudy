### 解题思路

正常的广度优先搜索，需要注意的是：
1、队列保存的值:   使用二维数组 
2、防止重复遍历:   将二维数组转换为字符串保存在set中  **Arrays.deepToString()很慢，慎用**

还有一点分享一下，Java中数组的clone()函数是浅拷贝，要小心

### 代码

```java
class Solution {
    public int slidingPuzzle(int[][] board) {
        Set<String> set = new HashSet<>();
        Queue<int[][]> queue = new LinkedList<>();
        queue.offer(board);
        
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int res = -1;
        String target = getStr(new int[][]{{1,2,3},{4,5,0}});
        
        while(!queue.isEmpty()){
            int size = queue.size();
            ++res;
            for(int i=0 ; i<size ; i++){
                int[][] b = queue.poll();
                String str = getStr(b);
                if(str.equals(target)) return res;
                int[] index = getIndex(b);
                for(int[] dir : dirs){
                    int x = index[0] + dir[0];
                    int y = index[1] + dir[1];                    
                    if(x>=0 && x<2 && y>=0 && y<3){
                        int[][] copy = new int[2][3];
                        for(int j=0 ; j<2 ; j++){
                            copy[j] = Arrays.copyOf(b[j],3);
                        }
                        copy[x][y] = b[index[0]][index[1]];
                        copy[index[0]][index[1]] = b[x][y];
                        if(set.add(getStr(copy))){
                            queue.offer(copy);
                        }
                    }
                }
            }
        }
        return -1;
    }
    
    public String getStr(int[][] board){
        StringBuilder sb = new StringBuilder();
        for(int i=0 ; i<board.length ; i++){
            for(int j=0 ; j<board[0].length ; j++){
                sb.append((char)(board[i][j] + '0'));
            }
        }
        return sb.toString();
    }
    public int[] getIndex(int[][] board){
        int[] res = new int[2];
        for(int i=0 ; i<board.length ; i++){
            for(int j=0 ; j<board[0].length ; j++){
                if(board[i][j]==0){
                    return new int[]{i,j};
                }
            }
        }
        return res;
    }
}
```