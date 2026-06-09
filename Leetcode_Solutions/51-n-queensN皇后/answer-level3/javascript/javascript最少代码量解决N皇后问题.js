var solveNQueens = function (n) {  
  let res = [];
  let deal = (row, temp) => {
    if (row === n) {
      res.push(temp.map(item => '.'.repeat(item) + 'Q' + '.'.repeat(n - item - 1)));
      return;
    }
    for (let col = 0; col < n; col++) {
      if (temp.some((co, ro) =>co === col || ro + co === row + col || ro - co === row - col)) continue;
      deal(row + 1, [...temp, col]);
    }
  };
  deal(0, []);
  return res;
}