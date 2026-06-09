```rs
impl Solution {
    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {

        fn search_neighbors(grid: &mut Vec<Vec<i32>>, w: usize, h: usize, i: usize, j: usize, max_island: &mut i32) {
            let mut stack = vec![(i, j)];
            let mut island = 0;
            while !stack.is_empty() {
                let (i, j) = stack.pop().unwrap();
                if grid[i][j] == 1 {
                    island += 1;
                    grid[i][j] = 0;
                    if i > 0 {
                        stack.push((i-1, j));
                    }
                    if i < h-1 {
                        stack.push((i+1, j));
                    }
                    if j > 0 {
                        stack.push((i, j-1));
                    }
                    if j < w-1 {
                        stack.push((i, j+1));
                    }
                }
            }
            *max_island = island.max(*max_island);
        }

        let mut grid = grid;
        let w = grid[0].len();
        let h = grid.len();

        let mut max_island = 0;
        for i in 0..h {
            for j in 0..w {
                if grid[i][j] == 1 {
                    search_neighbors(&mut grid, w, h, i, j, &mut max_island)
                }
            }
        }

        max_island
    }
}
```