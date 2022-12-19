```
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    let reg1 =new RegExp(`["qwertyuiop"]`,"i"),
        reg2 =new RegExp(`["asdfghjkl"]`,"i"),
        reg3 =new RegExp(`["zxcvbnm"]`,"i"); 
    
    let newWords = []
    words.forEach(word=>{
      let flag1= reg1.test(word);
      let flag2= reg2.test(word);
      let flag3= reg3.test(word);
      
      
      if((flag1 && !flag2 && !flag3)||(!flag1 && !flag2 && flag3)||(!flag1 && flag2 && !flag3)){
        newWords.push(word);
      }
      
    })
    return newWords
};

//执行用时 :52 ms, 在所有 JavaScript 提交中击败了99.58%的用户
//内存消耗 :33.6 MB, 在所有 JavaScript 提交中击败了53.73%的用户
```
正则能解决的问题,都不是问题(滑稽)
优化靠各位的发挥啦,哈哈

