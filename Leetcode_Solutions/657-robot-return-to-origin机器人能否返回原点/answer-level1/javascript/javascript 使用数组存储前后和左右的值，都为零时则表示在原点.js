```
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
  let arr = [0,0];
  let movesArr = moves.split('') 
  movesArr.forEach(function(x){
    if (x==="U"){
      arr[0]++
    }else if(x==="D"){
      arr[0]--
    }else if(x==="L"){
      arr[1]--
    }else if(x==="R"){
      arr[1]++
    }else{consle.log("error")}
  })
  if(arr[0]===0 && arr[1] === 0){
    return true
  }else{
    return false
  }
};
```

