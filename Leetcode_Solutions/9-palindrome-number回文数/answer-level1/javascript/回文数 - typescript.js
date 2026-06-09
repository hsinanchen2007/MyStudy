const divByTen = (num: number) => Math.floor(num / 10);

const isPalindrome = function (num: number) {
  if (num < 0) {
    return false;
  }

  if (num < 10) {
    return true;
  }

  if (num % 10 === 0) {
    return num === 0;
  }

  const dump = (forwardNum: number, backwardNum: number): boolean => {
    if (forwardNum <= backwardNum) {
      // sufficient backward search
      return forwardNum === backwardNum || // even digits
        (backwardNum >= 10 && forwardNum === divByTen(backwardNum)); // old digits
    }
    const forward = divByTen(forwardNum) 
    const backward = backwardNum * 10 + forwardNum % 10;
    return dump(forward, backward)
  }
  return dump(Math.floor(num / 10), num % 10);
};


console.log(isPalindrome(121));
console.log(isPalindrome(-121));
console.log(isPalindrome(1234));
console.log(isPalindrome(10));
console.log(isPalindrome(3));
console.log(isPalindrome(101));
console.log(isPalindrome(21120));