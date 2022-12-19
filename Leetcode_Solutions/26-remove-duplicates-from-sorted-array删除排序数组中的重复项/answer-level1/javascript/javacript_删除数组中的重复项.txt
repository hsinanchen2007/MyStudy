
- 最传统的双层循环
```javascript []

var A = [1, 1, 2, 3, 3, 33, 4, 4, 5, 6]

  var removeDuplicates = function (nums) {
    for (var i = 0; i < nums.length - 1; i++) {
      for (var j = i + 1; j < nums.length; j++) {
        if (nums[i] === nums[j]) {
          nums.splice(i, 1);
          j--
        }
      }
    }
    return nums.length
  };
  removeDuplicates(A)

```
-  参照官方解题思路，利用双指针
```javascript []

  var a = [0,2,2]
  var removeDuplicates1 = function (nums) {
    var i=0
    for (var j = 1; j < nums.length; j++) {
      if(nums[i] != nums[j]){
          i++;
          nums[i] = nums[j]
          
      }
    }
    return i+1
  };
  removeDuplicates1(a)
```

- 第一种解法的优化，去除了双层嵌套循环
```javascript []
 var removeDuplicates2 = function (nums) {
    for (var i = 0; i < nums.length - 1; i++) {
        var j = i+1
        if (nums[i] === nums[j]) {
          nums.splice(i, 1);
          i--
      }
    }
    return nums
  };
  removeDuplicates2(a) 
```

