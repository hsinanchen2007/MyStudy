### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
  let i=0;
  let j=numbers.length - 1;
  while(i<j){
    let m= Math.floor((i+j)/2);
    if(numbers[m]<numbers[j]) {
       j=m;
    } else if(numbers[m]>numbers[j]) {
      i=m+1;
    } else if(numbers[m] === numbers[j]) {
        j--;
    }
  }
  return numbers[i];
};
```