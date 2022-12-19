从后向前满9向前加1
var plusOne = function(digits) {
  const len = digits.length
  for(let i = len-1; i >= 0; i--){
    digits[i]++;
    if(digits[i]%10 !== 0) {
      return digits
    }else{
      digits[i]=0
    }
  }
  const arr = new Array(len).fill(0)
  arr.unshift(1)
  return arr
};
