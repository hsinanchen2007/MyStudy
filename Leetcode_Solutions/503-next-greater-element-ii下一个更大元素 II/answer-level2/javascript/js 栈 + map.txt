![image.png](https://pic.leetcode-cn.com/659696d727702f99aabd0c901cf2b9c0350da7d01966f53329cab000d951b10d-image.png)

### 解题思路
1. 维护一个单调栈和一个map
2. 要遍历 nums 两遍，因为是循环数组，查找最后一个元素的下一个最大元素时要查找到它的上一个元素的位置
3. 因为有重复值，所以 map中的key 要用值的索引存储，比如`[1, 2, 1, 6]`，第一个1的下一个最大元素是2，第二个1的下一个最大元素是6

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */

var nextGreaterElements = function(nums) {
  let stack = [], map = new Map(), ans = [], loop = 0;
  
  for (let i = 0, len = nums.length; i < len; ) {
    let curr = nums[i];
    while (stack.length > 0 && curr > nums[ stack[stack.length - 1] ]) {
      let last = stack.pop();
      if (!map.has( last )) {
        map.set(last, curr);
      }
    }
    stack.push( i );
    
    if (i === len - 1 && loop < 1) {
      i = 0;
      loop ++;
    }
    else {
      i++;
    }
  }
  
  while (stack.length > 0) {
    let last = stack.pop();
    if (!map.has( last )) {
      map.set( last, -1 );
    }
  }
  
  for (let i = 0, len = nums.length; i < len; i++) {
    ans.push( map.get( i ) );
  }
  
  return ans;
};
```