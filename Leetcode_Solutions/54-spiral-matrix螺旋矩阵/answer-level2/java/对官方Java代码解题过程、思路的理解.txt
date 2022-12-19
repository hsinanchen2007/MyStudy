/**
    *
    *   第一步 确定矩阵的规格R*C
    *   第二步 给R*C矩阵一个visit（是否访问过的判断标记数组）
    *   第三步 规定迭代方向（用两个一维数组来表示）
    *   设置初始化遍历元素r=0，c=0 di=0 从（0，0）出发，选用第一种方式前进
    *   第四步 遍历矩阵全部元素（R*C个元素）
    *   第五步 将该元素加入到遍历结果中visit标记数组标记为“走过”
    *   第六步 判断下一步如何走 判断当前di方式下前进一步的元素是否越界且是否被访问过
    *   如果越界或者被访问过 di = （di+1） % 4；r、c直接赋值dr[di],dc[di]
    *   否则（下一个元素不越界 且没被访问 可以走这一步） r c直接赋值cr、cc
    */
``` 
class Solution {
    /**
    *
    *   第一步 确定矩阵的规格R*C
    *   第二步 给R*C矩阵一个visit（是否访问过的判断标记数组）
    *   第三步 规定迭代方向（用两个一维数组来表示）
    *   设置初始化遍历元素r=0，c=0 di=0 从（0，0）出发，选用第一种方式前进
    *   第四步 遍历矩阵全部元素（R*C个元素）
    *   第五步 将该元素加入到遍历结果中visit标记数组标记为“走过”
    *   第六步 判断下一步如何走 判断当前di方式下前进一步的元素是否越界且是否被访问过
    *   如果越界或者被访问过 di = （di+1） % 4；r、c直接赋值dr[di],dc[di]
    *   否则（下一个元素不越界 且没被访问 可以走这一步） r c直接赋值cr、cc
    */
    public List<Integer> spiralOrder(int[][] matrix) {
        List ans = new ArrayList();
        
        if (matrix.length == 0) return ans;
        //R*C矩阵
        int R = matrix.length, C = matrix[0].length;
        
        boolean[][] seen = new boolean[R][C];
        
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < R * C; i++) {
            //将这个元素加入到List中
            ans.add(matrix[r][c]);
        
            seen[r][c] = true;//第r行第c列已经被走过
        
            int cr = r + dr[di];
            int cc = c + dc[di];
            //如果[cr，cc]没有越界 且[cr,cc]没有被访问过的话，那么就访问这个点
            //如果越界了 说明这个di走不通 那么就重新设置di且这个东西是该路不通 下一路就必通的那种，这就是为什么不用循环判断此时di造成的cr、cc（直接写成了r、c）是否合法的情况，因为必定合法
            
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc]){
                r = cr;
                c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return ans;
    }
}
```
