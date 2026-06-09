// 复杂度，组成数组长度总共为N  时间O(N)，空间O(1)
/**
 * @param {string[]} A
 * @return {number}
 */
var minDeletionSize = function(A) {
    let count = 0
    for(let i = 0; i < A[0].length; i++){
        for(let j = 0; j < A.length - 1; j++){
            if(A[j].charAt(i) > A[j+1].charAt(i)){
                count++
                console.log(A[j].charAt(i), A[j+1].charAt(i))
                break
            }
        }
    }
    return count
};