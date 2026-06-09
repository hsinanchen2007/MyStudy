运用了栈的思想


/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let obj={
           ')':'(',
           ']':'[',
           '}':'{'
       },len=s.length;
    
    //若第一个字符为闭括号或字符个数为奇数则直接返回false
    if(len%2==0&&!obj[s[0]]){
        let arr=[];
       for(var i=0;i<len;i++){
           if(!obj[s[i]]){
               //将所有开括号放入数组中
              arr.push(s[i]);
          }else{
              //匹配到的第一个闭括号是否与最后一个开括号配对，若配对便将开括号从数组中删除
              //若不匹配则直接跳出循环
              if(obj[s[i]]===arr[arr.length-1]){
                  arr.pop();
              }else{
                  break;
              }
          }
       };
       return arr.length==0
   }else{
       return false
   }
};