    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.size() <= 0)
        {
            return 0;
        }

        // 1. 从矩阵中心出发，检查周边八个格子的距离，取最小距离
        // 2. 迭代向最小距离移动，每次检查周边八个格子的距离
        // 3. 直到周边八个格子距离都比中心点大，则此为矩阵质心

        // 计算矩阵中心
        pair<int, int> gridCenter;
        gridCenter.first = (grid.size() % 2 == 0) ? (grid.size() / 2) : (grid.size() / 2 + 1);
        gridCenter.second = (grid[0].size() % 2 == 0) ? (grid[0].size() / 2) : (grid[0].size() / 2 + 1);

        // 逐渐向质心移动
        pair<int, int> center;
        center = gridCenter;
        for (int i = 0; i < gridCenter.first + gridCenter.second; i++) 
        {
            auto newCenter = FindCenter(center, grid);
            if (newCenter == center)
            {
                return m_knownDistance[center];
            }
            else
            {
                center = newCenter;
            }
        }

        // 到这里就出错了
        cout << "Error! can't find center." << endl;
        return 0;
    }