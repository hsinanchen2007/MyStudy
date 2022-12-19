```
let getLeastNumbers = function(nums, k) {
  return countSort(nums, k)
}
function countSort(arr, k) {
  let bucket = [], len = arr.length, index=0
  for(let i = 0; i < len; i++) {
    if(!bucket[arr[i]]) {
      bucket[arr[i]] = 0
    }
    bucket[arr[i]]++
  }
  for(let j = 0; j < bucket.length; j++) {
    while(bucket[j] > 0) {
      arr[index++] = j
      if(index === k) return arr.slice(0, k)
      bucket[j]--
    }
  }
  return arr.slice(0, k)
}
```
