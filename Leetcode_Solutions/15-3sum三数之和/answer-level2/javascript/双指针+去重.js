### 解题思路
此处撰写解题思路

### 代码

```javascript
  var threeSum = function(nums) {
    if (!nums || nums.length < 3) return [];
    let arr = nums.sort((a,b)=>a-b);
    if (arr[0] > 0 || arr[arr.length - 1] < 0) return [];

    let res = [];
    for (let i = 0; i < arr.length - 2; i++) {
      if (arr[i] > 0) return res;
      if (i > 0 && arr[i] === arr[i-1]) {
        continue;
      }
      let left = i + 1, right = arr.length - 1;
      while(left < right) {
        if (arr[i] + arr[left] + arr[right] === 0) {
          res.push([arr[i], arr[left], arr[right]]);
          while (left < right && arr[left] === arr[left+1]) {
            left++;
          }
          while (left < right && arr[right] === arr[right-1]) {
            right--;
          }
          left++;
          right--;
        } else if(arr[i] + arr[left] + arr[right] > 0) {
          right--;
        } else if(arr[i] + arr[left] + arr[right] < 0) {
          left++;
        }
      }
    }
    return res;
  };
```