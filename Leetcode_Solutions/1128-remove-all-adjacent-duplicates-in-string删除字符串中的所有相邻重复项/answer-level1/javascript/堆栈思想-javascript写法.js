/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
//遍历当前数组，取第一个字母
    let arr=S.split('')
    let result=[]
    arr.forEach(item=>{
        //item--取到的字母
        if(result.length&&item===result[result.length-1]){
            result.pop()
        }else{
            result.push(item)
        }
    })
    return result.join('')
};