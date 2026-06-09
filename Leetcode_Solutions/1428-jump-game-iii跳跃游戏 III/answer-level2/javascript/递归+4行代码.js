- arr[start] *= -1 arr[start] < 0 表示已经访问过
```
var canReach = function(arr, start) {
  if (start < 0 || start >= arr.length || arr[start] < 0) return false;
  if (arr[start] === 0) return true;
  arr[start] *= -1;
  return canReach(arr, start+arr[start]) || canReach(arr, start-arr[start])
};
```
