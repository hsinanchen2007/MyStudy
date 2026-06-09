```java

class NumMatrix {
    // 用线段树记录区域间的和
    // 每一片区域(row1, col1) <-> (row2, col2) 可以以((row1+row2)/2, (col1+col2)/2)为中心分为四块
    int rowNum;
    int colNum;
    Area root;
    Stack<Area> stack = new Stack<>();
    int[][] mat;

    public NumMatrix(int[][] matrix) {
        rowNum = matrix.length;
        if (rowNum!=0) {
            colNum = matrix[0].length;
            mat = matrix;
            root = new Area(0, rowNum-1, 0, colNum-1);
            dfs(matrix, root);
        }
    }

    private void dfs(int[][] matrix, Area cur) {
        if (cur.row1==cur.row2 && cur.col1==cur.col2) {
            cur.sum = matrix[cur.row1][cur.col1];
            return;
        }
        int midRow = (cur.row1+cur.row2)>>1;
        int midCol = (cur.col1+cur.col2)>>1;
        if (cur.row1<cur.row2 && cur.col1==cur.col2) {
            cur.leftTop = new Area(cur.row1, midRow, cur.col1, cur.col1);
            cur.leftBottom = new Area(midRow+1, cur.row2, cur.col1, cur.col1);
            dfs(matrix, cur.leftTop);
            dfs(matrix, cur.leftBottom);
            cur.sum = cur.leftTop.sum + cur.leftBottom.sum;
        } else if (cur.row1==cur.row2 && cur.col1<cur.col2) {
            cur.leftTop = new Area(cur.row1, cur.row1, cur.col1, midCol);
            cur.rightTop = new Area(cur.row1, cur.row1, midCol+1, cur.col2);
            dfs(matrix, cur.leftTop);
            dfs(matrix, cur.rightTop);
            cur.sum = cur.leftTop.sum + cur.rightTop.sum;
        } else {
            cur.leftTop = new Area(cur.row1, midRow, cur.col1, midCol);
            cur.leftBottom = new Area(midRow+1, cur.row2, cur.col1, midCol);
            cur.rightTop = new Area(cur.row1, midRow, midCol+1, cur.col2);
            cur.rightBottom = new Area(midRow+1, cur.row2, midCol+1, cur.col2);
            dfs(matrix, cur.leftTop);
            dfs(matrix, cur.leftBottom);
            dfs(matrix, cur.rightTop);
            dfs(matrix, cur.rightBottom);
            cur.sum = cur.leftTop.sum + cur.leftBottom.sum + cur.rightTop.sum + cur.rightBottom.sum;
        }
    }

    public void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        if (diff==0)
            return;
        stack.push(root);
        while (!stack.isEmpty()) {
            Area area = stack.pop();
            area.sum += diff;
            if (locate(row, col, area.leftTop))
                stack.push(area.leftTop);
            if (locate(row, col, area.leftBottom))
                stack.push(area.leftBottom);
            if (locate(row, col, area.rightTop))
                stack.push(area.rightTop);
            if (locate(row, col, area.rightBottom))
                stack.push(area.rightBottom);
        }
        mat[row][col] = val;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int rtn = 0;
        if (contains(row1, col1, row2, col2, root)) {
            return root.sum;
        }
        stack.push(root);
        while (!stack.isEmpty()) {
            Area area = stack.pop();
            if (intersect(row1, col1, row2, col2, area.leftTop)) {
                if (contains(row1, col1, row2, col2, area.leftTop))
                    rtn += area.leftTop.sum;
                else
                    stack.push(area.leftTop);
            }
            if (intersect(row1, col1, row2, col2, area.leftBottom)) {
                if (contains(row1, col1, row2, col2, area.leftBottom))
                    rtn += area.leftBottom.sum;
                else
                    stack.push(area.leftBottom);
            }
            if (intersect(row1, col1, row2, col2, area.rightTop)) {
                if (contains(row1, col1, row2, col2, area.rightTop))
                    rtn += area.rightTop.sum;
                else
                    stack.push(area.rightTop);
            }
            if (intersect(row1, col1, row2, col2, area.rightBottom)) {
                if (contains(row1, col1, row2, col2, area.rightBottom))
                    rtn += area.rightBottom.sum;
                else
                    stack.push(area.rightBottom);
            }
        }
        return rtn;
    }
    
    private boolean locate(int row, int col, Area area) {
        if (area==null)
            return false;
        return (row>=area.row1 && row<=area.row2 && col>=area.col1 && col<=area.col2);
    }
    
    private boolean contains(int row1, int col1, int row2, int col2, Area area) {
        return (row1<=area.row1 && col1<=area.col1 && row2>=area.row2 && col2>=area.col2);
    }
    
    private boolean intersect(int row1, int col1, int row2, int col2, Area area) {
        if (area==null)
            return false;
        if (row1>area.row2 || row2<area.row1 || col1>area.col2 || col2<area.col1)
            return false;
        return true;
    }
}

class Area {
    int row1;
    int row2;
    int col1;
    int col2;
    int sum;
    Area leftTop;
    Area leftBottom;
    Area rightTop;
    Area rightBottom;
    public Area(int r1, int r2, int c1, int c2) {
        row1 = r1;
        row2 = r2;
        col1 = c1;
        col2 = c2;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
```