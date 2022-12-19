![image.png](https://pic.leetcode-cn.com/0712951a33f6cd544bc342723b2bae79cefd25c16f7170cdb5180db483895068-image.png)

### 解题思路
```js
  贪心策略：先排身高大的人，如果先排身高小的人，那后面再往这个队列中排入大身高的
  人，可能会影响很多人的相对位置。
  同等身高的话，先排序前面人少的那个
```

### 代码

```javascript
/**
 * @param {number[][]} people
 * @return {number[][]}
 */

var reconstructQueue = function(people) {
  people.sort((a, b) => {
    if (a[0] !== b[0]) {
      return b[0] - a[0];
    } else {
      return a[1] - b[1];
    }
  });
  
  let arr = [];
  
  for (let i = 0; i < people.length; i++) {
    let [height, nums] = people[i];
    let index = 0, count = nums;
    while (index < arr.length && count > 0) {
      if (arr[index][0] >= height)count--;
      index++;
    }
    arr.splice(index, 0, [height, nums]);
  }
  
  return arr;
};
```