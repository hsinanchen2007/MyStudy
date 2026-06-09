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
    var res=[],i;
    for(i=0;i<num_people;i++){
        res[i]=0;
    }
    i=0;
    while(candies>0) {
        res[i%num_people] += Math.min(i+1,candies);
        candies -= Math.min(i+1,candies);
        i++;
    }
    return res;
};
```