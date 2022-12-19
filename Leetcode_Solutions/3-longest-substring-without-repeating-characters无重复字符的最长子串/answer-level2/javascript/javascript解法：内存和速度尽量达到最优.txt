```
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if (!s) {
      return 0;
    }
    const sArr = s.split('');
    let maxNumber = 1;
    let strIndex = 0;
    for (let i = 1; i < sArr.length; i++) {
      for (let j = strIndex; j < i; j++) {
        if (sArr[i] === sArr[j]) {
          strIndex = j + 1;
          break;
        }
      }
      if (maxNumber < i - strIndex + 1) {
        maxNumber = i - strIndex + 1;
      }
    }
    return maxNumber;
};
```
执行结果：
![image.png](https://pic.leetcode-cn.com/d8074dcbce8bf3f0e705a18d42f0affd8e5843133d619e2e2a25865128d89f24-image.png)
