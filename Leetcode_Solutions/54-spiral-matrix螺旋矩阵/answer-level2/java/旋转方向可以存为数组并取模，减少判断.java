class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int rows=matrix.length;
        
        if(rows==0) {
            return Collections.emptyList();
        }
        
        int cols=matrix[0].length;
        
        int row=0;
        int col=0;
        
        int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int currentDir=0;
        
        boolean[][] vis = new boolean[rows][cols];
        List<Integer> ans = new ArrayList<>(rows*cols);
        
        for(int i=0;i<rows*cols;i++) {
            vis[row][col]=true;
            ans.add(matrix[row][col]);
            
            int movedRow=row+dir[currentDir][0];
            int movedCol=col+dir[currentDir][1];
            
            if(movedRow<0||movedRow>=rows||movedCol<0||movedCol>=cols||vis[movedRow][movedCol]) {
                currentDir=(currentDir+1)%4;
                movedRow=row+dir[currentDir][0];
                movedCol=col+dir[currentDir][1];
            }
            
            row=movedRow;
            col=movedCol;
        }
        
        return ans;
    }
}