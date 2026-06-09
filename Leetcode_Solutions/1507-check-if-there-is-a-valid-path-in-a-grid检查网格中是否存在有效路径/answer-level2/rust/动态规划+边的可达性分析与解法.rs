### 解题思路

一种比较复杂的解法，作为思路的补充给大家参考。

解体中首先考虑构建一个可以解释“可到达”这个概念的模型，我这里选择将每一个方块四个边是否可以到达作为其模型的数据，按照上右下左的顺序记录在数组dp中（这里的命名是不合理的，应该为grid_access之类的），即用一个三维数组来储存其道路的信息。
在该模型下，每一个grid数组的值均被扩展为四个方位的边是否可达，如1代表的可达性数组为[0,1,0,1]，也就是右左两个方向可达，即为左边到右边的通路。

有了模型之后我们选择用动态规划的方式来解决问题，dp[i][j]的值代表该位置是否可以由[0][0]位置到达。然后根据刚才得出的可达性数组，分别递归至其他的位置。

总结一下的话，该方法实现较为麻烦，但建立了一个解释性较强的模型，如果题目稍作改变，一个方块可以有“岔路”，那么依旧可以通过这个可达性的数组进行分析，后续动态规划的内容也近乎一致。不足之处就是麻烦，而且不能处理带环的路线。

RUST新手，代码风格还需要进一步优化，有更好的写法或者哪里写的啰嗦了希望大家在评论指出，鞠躬🙇‍♀️
### 代码

```rust
fn access_dp(dp_a: &mut Vec<Vec<i32>>,dp:&Vec<Vec<Vec<i32>>>,x:i32,y:i32) -> bool {
    let m:i32 = dp_a.len() as i32;
    let n:i32 = dp_a[0].len() as i32;
    
    if x < 0 || y < 0 || x > m -1 || y > n - 1 || dp_a[x as usize][y as usize ] == -1 {
        return false;
    }
    let x = x as usize;
    let y = y as usize;
    if dp_a[x][y] == 1 {
        return true;
    }
    dp_a[x][y] = -1;
    let mut result:bool = false;
    if dp[x][y][0] == 1 {
        result = result || (x > 0 && dp[x - 1][y][2] == 1 && access_dp(&mut *dp_a,& *dp,(x - 1) as i32,y as i32))
    }
    if dp[x][y][1] == 1 {
        result = result || (y > 0 && dp[x][y - 1][3] == 1 && access_dp(&mut *dp_a,& *dp,x as i32,(y - 1) as i32))
    }
    if dp[x][y][2] == 1 {
        result = result || (x < (m - 1) as usize && dp[x + 1][y][0] == 1 && access_dp(&mut *dp_a,& *dp,(x + 1) as i32,y as i32))
        
    }
    if dp[x][y][3] == 1 {
        result = result || (y < (n - 1) as usize && dp[x][y + 1][1] == 1 && access_dp(&mut *dp_a,& *dp,x as i32,(y + 1) as i32))
    }
    if result {
        dp_a[x][y] = 1
    }
    return result;
}


impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp: Vec<Vec<Vec<i32>>> = vec![vec![vec![0;4];n];m];
        let mut dp_access:Vec<Vec<i32>> = vec![vec![0;n];m];
        for i in 0..m {
            for j in 0..n {
                match grid[i][j] {
                    1 => {
                        dp[i][j][1] = 1;
                        dp[i][j][3] = 1;
                    },
                    2 => {
                        dp[i][j][0] = 1;
                        dp[i][j][2] = 1;
                    },
                    3 => {
                        dp[i][j][1] = 1;
                        dp[i][j][2] = 1;
                    },
                    4 => {
                        dp[i][j][2] = 1;
                        dp[i][j][3] = 1;
                    },
                    5 => {
                        dp[i][j][1] = 1;
                        dp[i][j][0] = 1;
                    },
                    6 => {
                        dp[i][j][0] = 1;
                        dp[i][j][3] = 1;
                    },
                    _ => return false,
                }
            }
        }
        dp_access[0][0] = 1;
        return access_dp(&mut dp_access,&dp,(m - 1) as i32,(n - 1) as i32);
    }
}
```