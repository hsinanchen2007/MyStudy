```
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
  let temp = [],list = [];

  if(n == 0){
      return [0];
  }

  let one = (length,list,who) => {
      if(list.length == length){
          let one = parseInt(list.join(''),2);
          if(temp.indexOf(one)<0){
              temp.push(one);
          }
          return;
      }

     //当前节点中1的数量为偶数时，下面子节点依次为0,1。如果数量为奇数时，下面子节点依次为1,0。
     if(who%2 == 0){
         list.push(0);
         one(length,list.slice(),who);
         list.pop();
         list.push(1);
         one(length,list.slice(),who+1);
     }

     if(who%2 != 0){
         list.push(1);
         one(length,list.slice(),who+1);
         list.pop();
         list.push(0);
         one(length,list.slice(),who);
     }
  }

  one(n,list,0);
  return temp;  
};
```
