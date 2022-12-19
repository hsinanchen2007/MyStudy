```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
  let arr = new Array(num_people).fill(0), k = 1;
  while (candies > 0) {
    let i = (k - 1) % num_people;
    if (candies - k >= 0) {
      arr[i] += k;
      candies -= k;
    } else {
      arr[i] += candies;
      candies = 0;
    }
    k++;
  }
  return arr;
};
```