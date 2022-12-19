  let count = 0;
  let count2 = 0;
  let arr = [];
   for (let index = 0; index < S.length; index++) {
     if(S[index] === '(') {
       count = count + 1;
     } 
     if (S[index] === ')') {
      count = count - 1;
     }
     if(count === 0) {
       arr.push(S.substring(count2, index+1));
       count2 = index + 1;
     }
   }
   return arr.map(item => item.slice(1, item.length-1)).toString().replace(/\,/g, '')