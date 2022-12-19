/**
 * @param {number[]} A
 * @return {number[]}
 */
偶数从数组首端添加，奇数从数据尾端添加
var sortArrayByParity = function(A) {
    let res = []
    A.forEach( item => {
        if(item % 2 === 0) {
            res.unshift(item)
        }else{
            res.push(item)
        }
    })
    return res
};