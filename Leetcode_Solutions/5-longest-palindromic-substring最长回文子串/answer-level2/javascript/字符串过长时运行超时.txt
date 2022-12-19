const longestPalindrome = function(s) {
    if(!s) return s;
    const { length } = s;
    // 判断是否是回文数
    const isPal = (str) => str === str.split('').reverse().join('');

    // 假设最大回文数的长度 === length - i
    for (let i = 0; i < length; i += 1) {
      // 最大回文数起始索引 === j
      for (let j = 0; j <= i; j += 1) {
        const subStr = s.substr(j, length - i);
        if (isPal(subStr)) {
          return(subStr);
        }
      }
    }
};