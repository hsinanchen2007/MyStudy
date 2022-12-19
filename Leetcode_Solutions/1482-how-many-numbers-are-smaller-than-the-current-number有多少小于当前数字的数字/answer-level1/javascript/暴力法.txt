### 解题思路
1.先循环一遍
2.开始计数
3.在进行循环进行匹配

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
    var smallerNumbersThanCurrent = function (nums) {
      let r = []; let obj = {}
      for (let i = 0; i < nums.length; i++) {
        let count = 0;
        for (let j = 0; j < nums.length; j++) {
         
          if (nums[j] !== nums[i] && nums[j] < nums[i]) {
            count++
            r[i] = count

          } else {
            r[i] = count
          }

        }

      }
      return r
    };
```