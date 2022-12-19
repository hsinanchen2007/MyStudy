const isPalindrome = function(x) {
  const input = x.toString();
  const inputArr = input.split('');
  if (inputArr[0] === '-') {
    return false;
  } else {
    const inputArr2 = [];
    inputArr.forEach(item => {
      inputArr2.push(item);
    });
    const inputArrReverse = inputArr2.reverse();

    let bool = 1;
    for (let i = 0; i < inputArrReverse.length - 1; i++) {
      if (inputArr[i] !== inputArrReverse[i]) {
        bool = 0;
      }
    }
    if (bool == 1) return true;
    else return false;
  }
};