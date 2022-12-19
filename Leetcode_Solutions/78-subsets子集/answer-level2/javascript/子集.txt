随便写写实现算法
Your runtime beats 51.76 % of javascript submissions
Your memory usage beats 43.97 % of javascript submissions (35.2 MB)
也不知道好不好
```
var subsets = function(nums) {
  let answer = [[]];
  for (let i = 0; i < nums.length; i++) {
    let len = answer.length;
    for (let j = 0; j < len; j++) {
      answer.push(answer[j].concat([nums[i]]));
    }
  }
  return answer;
};
```
第一层循环上要定义好len为answer的长度，不然会报计算不过来的错
