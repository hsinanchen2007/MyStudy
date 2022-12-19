var reverseWords = function(s) {
    let arr = s.split(' ')
    let result = arr.map(item => {
        return item.split('').reverse().join('')
    })
<!-- 最后以空格分格数组 -->
    return result.join(' ')
};