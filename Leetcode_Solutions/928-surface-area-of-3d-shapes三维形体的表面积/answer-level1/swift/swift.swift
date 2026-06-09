        func surfaceArea(_ grid: [[Int]]) -> Int {
            var area = 0
            for i in 0 ..< grid.count {
                for j in 0 ..< grid[i].count {
                    guard grid[i][j] > 0 else {
                        continue
                    }
                    area += grid[i][j] * 4 + 2
                    if i > 0 {
                        area -= min(grid[i][j], grid[i - 1][j]) * 2
                    }
                    if j > 0 {
                        area -= min(grid[i][j - 1], grid[i][j]) * 2
                    }
                }
            }
            
            return area;
        }