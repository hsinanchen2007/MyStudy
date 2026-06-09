       直接上代码：

/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
  let result = new Array(num_people).fill(0);
  let surplus = candies;
  let j = 0;
  for (let i = 1; i < candies; i++) {
    if (surplus > i) {
      result[j] = result[j] + i;
      surplus = surplus - i;
      j++;
      if (j === num_people) {
        j = 0;
      }
    } else {
      result[j] = result[j] + surplus;
      break;
    }
  }
  return result;
};   