// 解题本题的解题思路是将输入的数首先转换成字符串，然后将其进行逆序拼接
// 将拼接的结果值与原始值，进行比较，如果相等返回ttue，否则返回false

var isPalindrome = function(x) {
     let str = String(x);
    let result = ''
    for(let i=str.length-1;i>=0;i--){
      result+=str[i]
    }
    if(result==str){
      return true
    }else{
      return false
    }
};
