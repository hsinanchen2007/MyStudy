### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
  let list = Array(num_people).fill(0)
  let index = 0
  while(candies > 0){
    for(let i = 0; i< num_people; i++){
      if(candies > index){
        list[i] += ++index
        candies -= index
      } else{
        list[i] += candies
        candies = 0
      }
    }
  }
  return list
};
```