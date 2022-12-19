public class Solution
    {
        private int[] dx = { 1, 1, 1 };
        private int[] dy = { 0, -1, 1 };
        private List<IList<string>> result = new List<IList<string>>();
        public List<IList<string>> SolveNQueens(int n)
        {

            int[][] nums = new int[n][];
            for (int i = 0; i < n; i++)
            {
                int[] onenum = new int[n];
                for (int j = 0; j < n; j++)
                {
                    onenum[j] = 0;
                }
                nums[i] = onenum;
            }

            rowset(nums, 0, n);



            return result;
        }
        /// <summary>
        /// 下棋
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="row"></param>
        /// <param name="n"></param>
        public void rowset(int[][] nums, int row, int n)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[row][i] == 0)
                {
                    set(nums, i, row, n);

                    if (row == n - 1)
                    {
                        List<string> tt = new List<string>();
                        for (int j = 0; j < n; j++)
                        {
                            string str = "";
                            for (int a = 0; a < n; a++)
                            {
                                str += nums[j][a] == 2 ? "Q" : ".";
                            
                            }
                            tt.Add(str);
                        }
                        result.Add(tt);
                        break;

                    }
                    rowset(nums, row + 1, n);
                }
            }
            re(nums, row, n);
        }
        /// <summary>
        /// 落子
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="col"></param>
        /// <param name="row"></param>
        /// <param name="n"></param>
        public void set(int[][] nums, int col, int row, int n)
        {
            nums[row][col] = 2;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < 3; j++)

                {
                    int new_x = row + i * dx[j];
                    int new_y = col + i * dy[j];
                    if ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n))
                    {
                        nums[new_x][new_y] = 1;
                    }

                }
            }
        }

        /// <summary>
        /// 回溯
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="x"></param>
        /// <param name="n"></param>
        public void re(int[][] nums, int x, int n)
        {
            if (x != 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (nums[x - 1][i] == 2)
                    {
                        nums[x - 1][i] = 1;
                    }

                }
            }
            for (int i = x; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    nums[i][j] = 0;
                }
            }
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (nums[i][j] == 2)
                    {
                        set(nums, j, i, n);

                    }
                }
            }
        }


    }