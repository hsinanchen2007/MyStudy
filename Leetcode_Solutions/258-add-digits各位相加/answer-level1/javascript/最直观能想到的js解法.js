/**
 * @param {number} num
 * @return {number}
 */
const addDigits = function(num) {
  const numString = num + ''
  const numArr = numString.split('')
  if (numArr.length <= 1){
    return num
  } else {
    let sum = 0
    numArr.forEach(numItem => {
      sum += +numItem
    })
    if (sum >= 10) {
      return addDigits(sum)
    }else {
      return sum
    }
  }
};