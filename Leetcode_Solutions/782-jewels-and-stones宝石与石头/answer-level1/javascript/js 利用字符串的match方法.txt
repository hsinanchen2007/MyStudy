/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 *执行结果：通过 显示详情
执行用时 :76 ms, 在所有 JavaScript 提交中击败了97.39%的用户
内存消耗 :33.7 MB, 在所有 JavaScript 提交中击败了76.53%的用户

 */

var numJewelsInStones = function(J, S) {
        let nums = 0;
        for(let i =0,len = J.length;i<len;i++){
            let char = J.charAt(i)
            let reg = new RegExp(char,"gm")
            let res = S.match(reg)
            if(res){
                nums += res.length
            }
        }
        // console.log(nums)
        return nums
};