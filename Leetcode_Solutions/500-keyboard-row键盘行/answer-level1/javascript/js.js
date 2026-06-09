/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
  return words.filter(item=>{
      let arr=['qwertyuiop','asdfghjkl','zxcvbnm']
      let res=true
      
      let itemArr=item.split('')
      for(let i=1;i<itemArr.length;i++){
        let index=findIndex(arr,itemArr[0].toLowerCase())
          if(index!==findIndex(arr,itemArr[i].toLowerCase())) res=false
      }
      return res
  })
};
function findIndex(arr,char){
  for(let i=0;i<arr.length;i++){
      if(arr[i].indexOf(char)!==-1){
          return i
      }
  }
}