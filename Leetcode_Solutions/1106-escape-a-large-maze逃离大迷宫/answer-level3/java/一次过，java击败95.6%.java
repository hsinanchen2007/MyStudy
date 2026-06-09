一共只有200个障碍，而图的大小的999999，所以广搜肯定是行不通的，可以考虑source和target是否会被block包围住。

如果source和target都不能被包围，那么返回true， 如果一个被包围，一个没有被包围，那么返回false，如果都被包围，就检查他们是否在一个包围圈内，如果是，返回false；

在检测source和target是否被包围时，有些不够简洁，我的方法是，找到block的上下界，然后在结界内，做广搜，如果能到达边界，则表明无法被包围。

140多行代码，一次就通过，让人欣喜，速度也可以。

```
private boolean sourceClose;
    private boolean targetClose;

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {

        Map<Integer, List<Integer>> rowmap = new HashMap<>();
        Map<Integer, List<Integer>> colmap = new HashMap<>();

        for(int i=0; i<blocked.length; i++){
            if(rowmap.containsKey(blocked[i][0])){
                rowmap.get(blocked[i][0]).add(blocked[i][1]);
            }else{
                List<Integer> tmp = new ArrayList<>();
                tmp.add(blocked[i][1]);
                rowmap.put(blocked[i][0], tmp);
            }
            if(colmap.containsKey(blocked[i][1])){
                colmap.get(blocked[i][1]).add(blocked[i][0]);
            }else{
                List<Integer> tmp = new ArrayList<>();
                tmp.add(blocked[i][0]);
                colmap.put(blocked[i][1], tmp);
            }
        }

        int[] sourceBoundary = getBoundary(source[0], source[1], rowmap, colmap);
        int[] targetBoundary = getBoundary(target[0], target[1], rowmap, colmap);

        //System.out.print(String.format("%d %d %d %d\n", sourceBoundary[0], sourceBoundary[1], sourceBoundary[2], sourceBoundary[3]));
        //System.out.print(String.format("%d %d %d %d\n", targetBoundary[0], targetBoundary[1], targetBoundary[2], targetBoundary[3]));

        this.sourceClose = true;
        this.targetClose = true;

        int[][] sourceState = this.getState(source[0], source[1], sourceBoundary[0], sourceBoundary[1],
                sourceBoundary[2], sourceBoundary[3], rowmap, true);
        int[][] targetState = this.getState(target[0], target[1], targetBoundary[0], targetBoundary[1],
                targetBoundary[2], targetBoundary[3], rowmap, false);

        //System.out.print(String.format("%b %b\n", this.sourceClose, this.targetClose));

        if(this.targetClose == false && this.sourceClose == false){
            return true;
        }else{
            if(this.targetClose == true && this.sourceClose == true && sourceState[target[0] - sourceBoundary[1]][target[1] - sourceBoundary[3]] == 1){
                return true;
            }else{
                return false;
            }
        }



    }

    public int[] getBoundary(int row, int col, Map<Integer, List<Integer>> rowmap, Map<Integer, List<Integer>> colmap){
        int[] boundary = new int[4];
        for(boundary[0] = row; boundary[0] < 1000000; boundary[0]++){
            if(!rowmap.containsKey(boundary[0])){
                break;
            }
        }
        boundary[0]--;
        for(boundary[1] = row; boundary[1] >= 0; boundary[1]--){
            if(!rowmap.containsKey(boundary[1])){
                break;
            }
        }
        boundary[1]++;
        for(boundary[2] = col; boundary[2] < 1000000; boundary[2]++){
            if(!colmap.containsKey(boundary[2])){
                break;
            }
        }
        boundary[2]--;
        for(boundary[3] = col; boundary[3] >= 0; boundary[3]--){
            if(!colmap.containsKey(boundary[3])){
                break;
            }
        }
        boundary[3]++;
        return boundary;
    }

    public int[][] getState(int sourceRow, int sourceCol, int maxRow, int minRow, int maxCol,
                            int minCol, Map<Integer, List<Integer>> rowmap, boolean isSource){
        int row = maxRow - minRow + 1;
        int col = maxCol - minCol + 1;

        //System.out.print(String.format("%d %d\n", row, col));

        if(row <= 0 || col <= 0){
            if(isSource)
                this.sourceClose = false;
            else
                this.targetClose = false;

            return null;
        }

        int[][] state = new int[row][col];
        Queue<Integer> queue = new LinkedList<>();

        state[sourceRow - minRow][sourceCol - minCol] = 1;
        ((LinkedList<Integer>) queue).add((sourceRow - minRow)*col + sourceCol - minCol);

        int direction[][] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!queue.isEmpty()){
            int tmp = queue.poll();
            int tmpRow = tmp / col;
            int tmpCol = tmp % col;

            for(int i=0; i<4; i++){
                int newrow = tmpRow + direction[i][0];
                int newcol = tmpCol + direction[i][1];
                int newmaprow = newrow + minRow;
                int newmapcol = newcol + minCol;

                if(newrow >= 0 && newrow < row && newcol >= 0 && newcol < col){
                    if(state[newrow][newcol] == 0 && !rowmap.get(newmaprow).contains(newmapcol)){
                        state[newrow][newcol] = 1;
                        queue.add(newrow*col+newcol);
                        if(newmaprow > 0 && newmapcol > 0 && newmaprow < 999999 && newmapcol < 999999
                                && (newrow == 0 || newrow == row - 1 || newcol == 0 || newcol == col -1)){

                            //System.out.print(String.format("%b: %d %d \n", isSource, newrow, newcol));
                            //System.out.print(String.format("%b: %d %d \n", isSource, newmaprow, newmapcol));

                            if(isSource)
                                this.sourceClose = false;
                            else
                                this.targetClose = false;
                        }
                    }
                }
            }
        }
        return state;
    }
```
