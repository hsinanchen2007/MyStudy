/*
 * @lc app=leetcode.cn id=3 lang=javascript
 *
 * [3] 无重复字符的最长子串
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {    
  // 如果是个空字符串，则直接返回0
  if (!s) {
    return 0;
  }

  const sArr = s.split('');
  let currArr = [];
  let lenArr = [];

  sArr.forEach((item, idx) => {
    let index = currArr.findIndex(i => item == i);
    if (index === -1) {
      currArr.push(item);
    } else {
      lenArr.push(currArr.length);
      currArr.splice(0, index + 1)
      currArr.push(item);
    }
  })

  lenArr.push(currArr.length);

  return Math.max.apply(null, lenArr);
};

![image.png](https://pic.leetcode-cn.com/23a9a0104dc895ae71cd0600d6ea696b9be715195ddd2489eda6ac207e20a36c-image.png)


