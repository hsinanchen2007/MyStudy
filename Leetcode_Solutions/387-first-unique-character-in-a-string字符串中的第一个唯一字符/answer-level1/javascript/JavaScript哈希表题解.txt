`
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    const map = {}
    s.split('').forEach((item,index) => {
        if(map[item] !== undefined){
            map[item] = Infinity
        }
        else map[item] = index
    })
    const result = Math.min(...Object.values(map))
    return result === Infinity ? -1 : result
};
`

没啥好说的，就是hashMap的简单应用，在O(n)时间内完成

时间上打败了78%的人
