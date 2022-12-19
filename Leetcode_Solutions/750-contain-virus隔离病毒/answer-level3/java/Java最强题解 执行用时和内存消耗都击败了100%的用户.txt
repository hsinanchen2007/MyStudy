首先这道题是真的麻烦，稍微一不注意就爆炸了。我也是写了很多次才正儿八经的写对了。
我们一步一步来解析一下，首先是题意，这道题要我们求的是给病毒扩散的矩阵设置防火墙，求这个墙壁的数量。而且一次只能给一片区域设置，所以A区域设置之后，B区域依然在感染。我们要得到，最后设置的防火墙的数量。

开始计算。

第一步，是梳理大致流程，就是既然每一次都只能给一片区域进行安装防火墙，那么我们就可以写一个方法来得到，当前最大的使用防火墙的数量，将这部分防火墙数量进行输出，并将这部分的病毒设置为不活动的状态，在之后的比较中不把这个第一次最大的区域拿来进行比较。
然后将每一次最大的防火墙数量进行累加，即可得到结果。

第二步，如何来写这个方法？首先，写一个双层for循环来遍历当前数组grid,并使用dp数组stateArray来记录状态，写一个DFS方法来计算出当前点相连的病毒区域即将感染的面积maxArea；对这个maxArea值和当前最大的感染面积cnt进行判断，谁大，与之相关的参数就设置为谁的。这样的循环遍历，就已经得到了第一次的最大值。该方法的返回值就输出对应的墙壁数量即可。注意：这个地方之所以我没有直接使用int walls,而是使用了wall.walls;是因为基本数据类型在方法中是纯粹的值传递，无论在方法中如何改变，都不会使得方法外的参数改变。而使用引用数据类型的对象类型的话，虽然从本质上来讲，java只有值传递，没有引用传递。但是引用类型的参数，传递的是栈内存中的指向堆内存内容的地址值，所以，虽然也是进行的值传递，但由于操作的是同一个地址，所以可以保留下修改的内容，从而实现我们想要的结果。

第三步，完善后续，使得这个方法可以不断的得到当前最大感染面积及相关参数。
这部分应当分为两部分，第一部分是将当前最大感染面积的部分设置为-1的不活动状态，使得这部分不会感染其他区域；第二部分是对于进行了第一步之后的当前状态，进行病毒感染操作，从而得到一个新的当前矩形区域数组。

第四步，完成第一步的整体流程设计，循环累加得到结果即可。

代码如下：

    class Solution {
        public int containVirus(int[][] grid) {
                int result=0;
                while (true){
                    int walls=process(grid);
                    if (walls==0){
                        break;
                    }
                    result+=walls;
                }
                return result;
        }

        //对整个场景进行业务逻辑梳理
        private int process(int[][] grid) {
            int rows = grid.length;
            int cols = grid[0].length;
            // cnt 是最大面积，ans是对应的墙
            int cnt = 0, res = 0, color = -1, row = -1, col = -1;
            //用一个数组来装当前这个点的状态
            int[][] stateArray=new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if(grid[i][j]==1&&stateArray[i][j]==0){
                        Wall wall = new Wall();
                        wall.walls=0;
                        int maxArea = getMaxAreaDfs(grid, stateArray, i, j, color, wall);
                        if(maxArea>cnt){
                            cnt=maxArea;
                            res=wall.walls;
                            row=i;
                            col=j;
                        }
                        color--;
                    }
                }
            }
            //修墙，将目标区域设置为未活动
            buildWall(grid,row,col);
            //另一块传播病毒
            //spread(grid,stateArray,row,col);
            stateArray=new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 1 && stateArray[i][j] == 0){
                        spread(grid, stateArray, i, j);
                    }
                }
            }
            return res;

        }

        private void spread(int[][] grid, int[][] stateArray, int row, int col) {
            int rows = grid.length;
            int cols = grid[0].length;
            if (row < 0 || row >= rows || col < 0 || col >= cols || stateArray[row][col] == 1) {
                return;
            }
            if (grid[row][col] == 0){
                grid[row][col] = 1;
                stateArray[row][col] = 1;
            }else if (grid[row][col] == 1){
                stateArray[row][col] = 1;
                int[] dir = { -1, 0, 1, 0, -1 };
                for (int i = 0; i < 4; i++){
                    spread(grid, stateArray, row + dir[i], col + dir[i + 1]);
                }
            }
        }

        private void buildWall(int[][] grid, int row, int col) {
            int rows = grid.length;
            int cols = grid[0].length;
            if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1){
                return;
            }
            //设置为不活动
            grid[row][col] = -1;
            int[] dir = { -1, 0, 1, 0, -1 };
            //DFS
            for (int i = 0; i < 4; i++){
                buildWall(grid, row + dir[i], col + dir[i + 1]);
            }
        }

        private int getMaxAreaDfs(int[][] grid, int[][] stateArray, int row, int col, int color, Wall wall) {
            int rows = grid.length;
            int cols = grid[0].length;
            int res = 0;
            //异常排除
            if (row < 0 || row >= rows || col < 0 || col >= cols){
                return 0;
            }
            //0不是病毒
            if (grid[row][col] == 0) {
                wall.walls++;
                //第二次进入
                if (stateArray[row][col] == color){
                    return 0;
                }
                //第一次进入
                stateArray[row][col] = color;
                return 1;
            }
            // 不是grid[i][j]==1 or 0
            if (stateArray[row][col] == 1 || grid[row][col] != 1){
                return 0;
            }
            //grid[i][j]==1
            stateArray[row][col] = 1;
            //前后左右,再来一次，直到出现不再是1的结果。DFS的思想。
            int[] dir = { -1, 0, 1, 0, -1 };
            for (int i = 0; i < 4; i++){
                res += getMaxAreaDfs(grid,stateArray, row + dir[i], col + dir[i + 1], color, wall);
            }
            return res;
        }

        class Wall{
            public int walls;

        }

    }