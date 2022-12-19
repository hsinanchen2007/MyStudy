// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  if (x > Math.pow(2, 31) - 1 || x < -1 * Math.pow(2, 31)) {
    return 0
  } else {
// 方法一
  let reverseNum = +(Math.abs(x) + '').split('').reverse().join('')
// 方法二
    /*let tempX = Math.abs(x)
    let tempStrX = tempX + ''
    let tempL = tempStrX.length
    let tempA = new Array(tempL)
    if (tempL === 1) {
      return x
    }
    let i = 0
    while (i < tempL - i) {
      tempA[i] = tempStrX.charAt(tempL - i - 1)
      tempA[tempL - i - 1] = tempStrX.charAt(i)
      i++
    }
    let reverseNum = +tempA.join('')*/
   
    if (reverseNum > Math.pow(2, 31) - 1 || x < -1 * Math.pow(2, 31)) {
      return 0
    }
    if (x > 0) {
      return reverseNum
    } else {
      return -reverseNum
    }
  }
};
// @lc code=end