/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(str) {
    if(str.length < 2) return str[0] || ''
    // try{
        return str.reduce((a,b) => {
            let reg = ''
            for(let i in a){
                if(a[i] === b[i]){
                    reg += a[i]
                } else {
                    break
                }
            }
            // if(!reg) throw 'err'
            return reg
        })
    // } catch (err){
    //     return ''
    // }
};