            int[] sp=new int[grid[0].Length];
            int[] sz = new int[grid[0].Length];
            int count=0;
            sp[0] = sz[0] = grid[0][0];
           
            // 获取天际线
            for (int i = 0; i < grid[0].Length; i++)
            {
                for (int j = 0; j < grid[i].Length; j++)
                {
                    if (sp[i]<grid[i][j])
                    {
                        sp[i] = grid[i][j];
                    }
                    if (sz[i] < grid[j][i])
                    {
                        sz[i] = grid[j][i];
                    }
                }        
            }
            
            // 遍历取当前行,列最小值
            for (int i = 0; i < grid[0].Length; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    if (sp[j]>sz[i])
                    {
                        count += sz[i] - grid[i][j];
                    }
                    else
                    {
                        count += sp[j] - grid[i][j];
                    }
                }
            }

            return count;