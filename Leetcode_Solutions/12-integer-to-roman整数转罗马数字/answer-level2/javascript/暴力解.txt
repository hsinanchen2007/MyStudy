```
代码块/*
 * @lc app=leetcode.cn id=12 lang=javascript
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  const num_dir = {
    "1000": ["M"],
    "100": ["C", "D"],
    "10": ["X", "L"],
    "1": ["I", "V"]
  };
  return num
    .toString()
    .split("")
    .reduce((target_str, item, index, this_arr) => {
      const turn_num = Number(item);
      let this_str = "";
      if (turn_num) {
        const w = Math.pow(10, this_arr.length - 1 - index);
        const w_num = num_dir[`${w}`];
        if (turn_num < 4) {
          this_str = Array.from({ length: turn_num }).reduce(
            tar => `${tar}${w_num[0]}`,
            ""
          );
          w_num[0] * turn_num;
        }
        if (turn_num === 4) {
          this_str = `${w_num[0]}${w_num[1]}`;
        }
        if (turn_num === 5) {
          this_str = `${w_num[1]}`;
        }
        if (turn_num > 5 && turn_num < 9) {
          this_str = Array.from({ length: turn_num - 5 }).reduce(
            tar => `${tar}${w_num[0]}`,
            w_num[1]
          );
        }
        if (turn_num === 9) {
          this_str = `${w_num[0]}${num_dir[`${w * 10}`][0]}`;
        }
      }
      return target_str + this_str;
    }, "");
};
// @lc code=end

```
