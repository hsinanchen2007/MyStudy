```
/* 
首先 X 肯定是在2-9范围内
其次数组能被分割为X份 则该数组长度肯定能整除X
然后每X份都有着相同的元素，也就是说这些元素也能整除X
*/
var hasGroupsSizeX = function(deck) {
  if (deck.length < 2) return false;
  let res = false
  for (let i = 2; i < 9; i++) {
    if(deck.length%i===0){
      let curFlag = true
      deck.forEach(e => {
        // 求出每个元素在数组种的个数
        let elCount = deck.filter(x=>{return x === e}).length
        if(elCount%i!==0){curFlag = false}
      });
      if(curFlag){
        res = true
        break
      }
    }
  }
  return res
};
```
