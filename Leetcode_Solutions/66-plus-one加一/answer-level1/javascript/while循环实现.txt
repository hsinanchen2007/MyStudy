var plusOne = function(digits) {
  let index=digits.length-1;
  while(index>=0){
    if(digits[index]<9){
      digits[index]++;
      return digits;
    }else{
      digits[index]=0;
    }
    index--;
  }
  digits.unshift(1)
  return digits;
};