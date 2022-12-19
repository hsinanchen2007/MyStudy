思路：一直判断空括号（()）符合条件就裁剪掉直到它为空就代表括号是符合条件的，如果当中有没有了空括号证明这个括号是不符合条件的
缺点：如果需要括号里面有内容这个方法就不起作用了
优点：简单
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
//     如果为空返回true
    if(!s) {
        return true;
    }
//     确定括号类型
    var brackets = ["()","[]","{}"];
//     通过寻找空内容的括号确定是否能闭合
    var bracket_type = brackets.find(item => s.indexOf(item) > -1);
    if(bracket_type) {
//         如果符合条件这把这个括号切了然后递归下去直到为空就代表这个括号是符合条件的
        var brackets_content = s.substr(0,s.indexOf(bracket_type)) + s.substr(s.indexOf(bracket_type)+2);
       return isValid(brackets_content);
    } else { //不能则返回false
        return false;
    }
};