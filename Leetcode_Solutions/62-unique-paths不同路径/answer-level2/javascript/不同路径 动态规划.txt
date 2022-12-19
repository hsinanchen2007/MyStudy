var uniquePaths = function(m, n) {
    let memo = [];
    for(let i=0; i<n; i++) {
        memo.push([])
    }
    for(let row=0; row<n; row++){
        memo[row][0] = 1;
    }
    for(let col=0; col<m; col++){
        memo[0][col] = 1;
    }
    for(let col=1; col<n; col++){
        for(let row=1; row<m; row++){
            memo[col][row] = memo[col-1][row] + memo[col][row-1]
        }
    }
    return memo[n-1][m-1]
};