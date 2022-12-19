- 把x移到左边 数值移到右边 如下
- 左边的x的系数直接取用  数值取相反数
- 右边的x的系数取相反数  数值直接取用
```
var solveEquation = function(equation) {
  let xCount = 0; // x的数量
  let param = 0; // 剩余数值
  let arr = equation.split('=');
  let helper = function (equation, sym) {
    let tempParam = '';
    let symbol = '+'; // 当前符号
    let i = 0;
    equation += '+' // 等式最后加上一个'+'为了处理最后的剩余数值
    while(equation[i]) {
      let char = equation[i];
      if (char === 'x') {
        let temp = parseInt(tempParam  || 1)
        tempParam = '';
        symbol === sym ? xCount += temp : xCount -= temp
      } else if (char === "+" || char === "-") {
        let temp = parseInt(tempParam || 0)
        tempParam = '';
        symbol === sym ? param-=temp : param+=temp
        symbol = char
      } else {
        tempParam += char;
      }
      ++i;
    }
  }
  helper(arr[0], "+")
  helper(arr[1], "-")
  if (xCount === 0 && param === 0) return "Infinite solutions"
  if (xCount === 0) return "No solution"
  return 'x=' + (param/xCount)
};
```
