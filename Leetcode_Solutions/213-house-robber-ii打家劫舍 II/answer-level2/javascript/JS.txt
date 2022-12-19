### 解题思路
此处难点就是转移方程s[i] = max(num[i] + s[i-2], s[i-1])
因为要隔着一个偷，所以当前的最大值，应该是当前值加上前前一个的最大值，和左临值进行比较。
注意保存右滑过程中的最大值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  if(nums == null || nums.length <=1){return nums}
  let step = []
  step[0] = 0
  step[1] =nums[0]
  for(let i =2; i<nums.length ; i++){
      step[i] = Math.max(nums[i-1] + step[ i- 2], nums[i-2], step[i -1])
    //   console.log(step[i])
  }

    let step2 = []
    step2[1] = 0
    step2[2] =nums[1]
    for(let i =3; i<=nums.length ; i++){
     step2[i] = Math.max(nums[i-1] + step2[ i- 2], nums[i-2], step2[i-1])
  }
  let max = Math.max(step[step.length -1], step2[step2.length -1])
  return max
};
```