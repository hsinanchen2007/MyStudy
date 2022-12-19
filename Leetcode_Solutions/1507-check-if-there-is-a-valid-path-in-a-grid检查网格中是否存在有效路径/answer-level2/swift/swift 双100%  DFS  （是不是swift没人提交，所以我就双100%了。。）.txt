
主要思路就是DFS。

1:)定义四个方向1:↑,2:←,3:↓,4:→,我们使用一个二维数组directList来存储当前这一步j根据上一步的方向i计算到方向n,表达为directList[i][j]=d.
例如dict[4][3]=1表示当前这个格子的值为3,前一个的方向为→(4),当前这一个格子为值为3,计算到的方向为↑(1),也就是下一个格子要和↑匹配。当d的值为0时,表示j这个格子个方向i不能构成联通。
![WechatIMG51.jpeg](https://pic.leetcode-cn.com/ed4367aa6dc5ece127fb4874f5e5483e0cee534fce8dbc461e7e24de0d8dd630-WechatIMG51.jpeg)

2:)用一个数组visitedArray来存储已经访问过的节点,访问过的就直接返回

3:)就是细分各种情况，代码有详细注释

    class Solution {
        func hasValidPath(_ grid: [[Int]]) -> Bool {
            //只有一个节点,那么肯定是满足情况
            if (grid[0].count == 1){
                return true
            }
            //eg:direct[i][j]表示前一个的方向为i,当前这个满足条件的值为j,计算到的结束的方向,就是下一个方向
            let directList: [[Int]] =  [
                                            [0, 0, 0, 0, 0, 0, 0],
                                            [0, 0, 1, 2, 4, 0, 0],   // ↑
                                            [0, 2, 0, 0, 3, 0, 1],   // ←
                                            [0, 0, 3, 0, 0, 2, 4],   // ↓
                                            [0, 4, 0, 3, 0, 1, 0]    // →
                                        ]
            var visitedArray: [[Int]] = [[Int]] (repeating: ([Int] (repeating: 0, count: grid[0].count)), count: grid.count)
            return hasValidPath(0, 0, grid,  &visitedArray, -1, directList)
        }
        
        //当前这个节点的row，column,节点数组grid,记忆化数组visitedArray,前一个的方向direct(-1表示这个节点是🕖),是否能够构成联通的联通数组.
        func hasValidPath(_ row: Int, _ column: Int, _ grid: [[Int]], _ visitedArray:inout [[Int]], _ direct: Int, _ directList:[[Int]]) -> Bool {
            let m = grid.count
            let n = grid[0].count
            let val = grid[row][column]
            
            if (row == m-1 && column == n-1){
                //如果遍历到了最后一个格子,并且能够和前一个方向构成联通,那么返回ture
                return (directList[direct][val] > 0)
            }

            if (visitedArray[row][column] == 1){
                //如果这个节点访问过,那么返回false
                return false
            }
            visitedArray[row][column] = 1  //这个节点置位访问过
            if (direct == -1 ){
                //direct为-1表示是第一个节点
                if ((val == 1 || val == 6) && column + 1 < n){
                    //第一个节点为1或者是6,判断是否越界然后计算的方向为→(4)
                    return hasValidPath(row, column+1, grid, &visitedArray, 4, directList)
                }else if ((val == 2 || val == 3) && row + 1 < m){
                    //第一个节点为2或者是3,判断是否越界然后计算的方向为↓(3)
                    return hasValidPath(row + 1, column, grid, &visitedArray, 3, directList)
                }else if (val == 4){
                    //第一个节点为4，有向右和向下两条路
                    var res1 = false
                    if (column + 1 < n){
                    res1 = hasValidPath(row, column+1, grid, &visitedArray, 4, directList)
                    }
                    var res2 = false
                    if (row + 1 < m){
                        res2 = hasValidPath(row + 1, column, grid, &visitedArray, 3, directList)
                    }
                    return (res1 || res2)
                }
                //第一个节点为5的话，是不满足条件的(只有一个节点的情况除外,在最开始已经处理这个边界条件)
            }else{
                let temp = directList[direct][val] //下一个的方向为temp，temp>0表示联通
                var tempRow = row
                var tempColoumn = column
                //方向和当前这个节点的值能够联通,并且下一个节点也没越界
                if (temp > 0 && isNextValidate(temp, &tempRow, &tempColoumn, grid)){
                    return hasValidPath(tempRow, tempColoumn, grid, &visitedArray, temp, directList)
                }
            }
            return false
        }
        
        //根据方向来判断下一个节点是否越界
        func isNextValidate(_ direct: Int, _ row:inout Int, _ column:inout Int, _ grid: [[Int]]) -> Bool{
            if (direct == 1 && row - 1 >= 0){
                //下一个节点的方向是向上,那么判断row-1是否越界，其他的同理
                row = row - 1
                return true
            }else if (direct == 2 && column - 1 >= 0){
                column = column - 1
                return true
            }else if (direct == 3 && row + 1 < grid.count){
                row = row + 1
                return true
            }else if (direct == 4 && column + 1 < grid[0].count){
                column = column + 1
                return true
            }
            return false
        }
    }