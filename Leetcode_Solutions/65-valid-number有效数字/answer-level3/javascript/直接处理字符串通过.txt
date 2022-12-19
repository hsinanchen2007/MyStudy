- 有问题请留言
```
var isNumber = function(s) {
  s = s.trim();
  if (s === "" || /[^e0123456789.+-]/.test(s)) return false;
  let test1 = '0123456789';
  let isAInterger = function(num) {
    for (let char of num) {
      if (!test1.includes(char)) return false;
    }
    return true;
  }
  let handleSymbol = function(num) {
    if (num[1] === '+' || num[1] === '-') return false;
    if (num[0] === '+' || num[0] === '-') return num.slice(1);
    return num;
  }
  let isANumber = function(num) {
    let arr = num.split('.');
    arr[0] =  handleSymbol(arr[0])
    if (arr.length >= 3 || (arr[0] === "" && arr[1] === "")) return false;
    if (arr[0] === false) return false;
    if (arr.length === 2) {
      return isAInterger(arr[0]) && isAInterger(arr[1])
    } 
    else if (arr[0].length) return isAInterger(arr[0]) 
    else return false;
  }
  let arr = s.split('e')
  if (arr.length >= 3) return false;
  if (arr.length === 2) {
    if (arr[0] === '' || arr[1] === '') return false;
    arr[1] = handleSymbol(arr[1])
    if (!arr[1] || !isAInterger(arr[1])) return false;
  }
  return isANumber(arr[0]);
};
```
